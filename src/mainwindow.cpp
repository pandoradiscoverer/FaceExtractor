#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDateTime>

using namespace std;
using namespace cv;
using namespace dlib;
namespace fs = std::filesystem;

// Worker class for face extraction
FaceExtractionWorker::FaceExtractionWorker(const std::string& inputPath, const std::string& outputDir, int fps, std::atomic<bool>& stopFlag)
    : inputPath(inputPath), outputDir(outputDir), fps(fps), stopFlag(stopFlag)
{
}

// Process function for face extraction
void FaceExtractionWorker::process()
{
    // Open the input file (video or image)
    VideoCapture cap(inputPath);
    Mat frame;
    std::vector<string> images;

    // If the input file is not a video, try to read it as an image
    if (!cap.isOpened())
    {
        frame = imread(inputPath);
        if (frame.empty())
        {
            emit logMessage("Error: Unable to open input file as video or image.");
            emit extractionFinished(0);
            return;
        }
        images.push_back(inputPath);
    }

    frontal_face_detector detector = get_frontal_face_detector();
    int frameCount = 0;
    int faceCount = 0;

    if (!images.empty())
    {
        // If the input file is an image, detect faces and save them
        cv_image<bgr_pixel> cimg(frame);
        std::vector<dlib::rectangle> faces = detector(cimg);

        for (auto& face : faces)
        {
            saveFace(frame, face, faceCount++);
        }
        emit logMessage("Processed 1/1 image(s). Found " + QString::number(faceCount) + " face(s).");
    }
    else
    {
        // If the input file is a video, process each frame and detect faces
        int totalFrames = static_cast<int>(cap.get(CAP_PROP_FRAME_COUNT));
        int frameInterval = std::max(1, 30 / fps);
        while (cap.read(frame))
        {
            if (stopFlag)
            {
                emit logMessage("Extraction stopped at: " + QDateTime::currentDateTime().toString());
                emit extractionFinished(faceCount);
                return;
            }

            if (frameCount % frameInterval == 0)
            {
                // Detect faces in the current frame and save them
                cv_image<bgr_pixel> cimg(frame);
                std::vector<dlib::rectangle> faces = detector(cimg);

                for (auto& face : faces)
                {
                    saveFace(frame, face, faceCount++);
                }

                // Update the progress based on the current frame count
                float progress = (static_cast<float>(frameCount) / totalFrames) * 100;
                emit progressUpdated(progress);
            }
            frameCount++;
        }
        emit logMessage("Processing complete. Found " + QString::number(faceCount) + " face(s).");
        emit logMessage("Extraction finished at: " + QDateTime::currentDateTime().toString());
    }
    emit extractionFinished(faceCount);
}

void FaceExtractionWorker::saveFace(const Mat& frame, const dlib::rectangle& face, int faceCount)
{
    // Extract the face region from the frame
    Mat faceImg = frame(Rect(Point(face.left(), face.top()), Point(face.right(), face.bottom()))).clone();
    // Generate the output file path
    fs::path outputFile = fs::path(outputDir) / ("face_" + std::to_string(faceCount) + ".jpg");
    // Save the face image to the output file
    imwrite(outputFile.string(), faceImg);
    // Emit a log message with the saved file path
    emit logMessage(QString::fromStdString("Saved face to " + outputFile.string()));
    // Emit a signal to display the last saved face image
    emit displayLastFace(QString::fromStdString(outputFile.string()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), stopFlag(false)
{
    ui->setupUi(this);
    fps = 1; // Default FPS

    connect(this, &MainWindow::destroyed, &workerThread, &QThread::quit);
}

MainWindow::~MainWindow()
{
    workerThread.quit();
    workerThread.wait();
    delete ui;
}

void MainWindow::on_selectFileButton_clicked()
{
    // Open a file dialog to select the input file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Videos and Images (*.mp4 *.jpg *.png)"));
    if (!fileName.isEmpty())
    {
        inputPath = fileName.toStdString();
        handleLogMessage("Selected file: " + fileName);
    }
}

void MainWindow::on_selectOutputDirButton_clicked()
{
    // Open a file dialog to select the output directory
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Output Directory"));
    if (!dir.isEmpty())
    {
        outputDir = dir.toStdString();
        handleLogMessage("Selected output directory: " + dir);
    }
}

// Function to handle the extraction of faces
void MainWindow::on_extractFacesButton_clicked()
{
    // Check if an input file has been selected
    if (inputPath.empty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Please select a file first."));
        return;
    }

    // Check if an output directory has been selected
    if (outputDir.empty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Please select an output directory."));
        return;
    }

    // Check if the input file exists
    if (!fs::exists(inputPath))
    {
        QMessageBox::critical(this, tr("Error"), tr("Input file does not exist."));
        return;
    }

    // Create the output directory if it doesn't exist
    if (!fs::exists(outputDir))
    {
        fs::create_directories(outputDir);
    }

    // Disable UI elements during extraction
    ui->selectFileButton->setEnabled(false);
    ui->selectOutputDirButton->setEnabled(false);
    ui->extractFacesButton->setEnabled(false);
    ui->fpsComboBox->setEnabled(false);
    ui->stopExtractionButton->setEnabled(true);
    ui->progressBar->setValue(0);

    // Log the start time of the extraction
    handleLogMessage("Extraction started at: " + QDateTime::currentDateTime().toString());

    // Reset the stop flag
    stopFlag = false;

    // Create a new worker object for face extraction
    FaceExtractionWorker *worker = new FaceExtractionWorker(inputPath, outputDir, fps, stopFlag);
    worker->moveToThread(&workerThread);

    // Connect signals and slots for worker thread communication
    connect(&workerThread, &QThread::started, worker, &FaceExtractionWorker::process);
    connect(worker, &FaceExtractionWorker::progressUpdated, this, &MainWindow::handleProgressUpdated);
    connect(worker, &FaceExtractionWorker::extractionFinished, this, &MainWindow::handleExtractionFinished);
    connect(worker, &FaceExtractionWorker::logMessage, this, &MainWindow::handleLogMessage);
    connect(worker, &FaceExtractionWorker::displayLastFace, this, &MainWindow::handleDisplayLastFace);
    connect(worker, &FaceExtractionWorker::extractionFinished, worker, &QObject::deleteLater);

    // Start the worker thread
    workerThread.start();
}

void MainWindow::on_stopExtractionButton_clicked()
{
    stopFlag = true;
    ui->stopExtractionButton->setEnabled(false);
}

void MainWindow::on_fpsComboBox_currentIndexChanged(int index)
{
    // Update the FPS value based on the selected index in the combo box
    fps = ui->fpsComboBox->itemText(index).toInt();
}

void MainWindow::handleProgressUpdated(float progress)
{
    // Update the progress bar value based on the progress value
    ui->progressBar->setValue(static_cast<int>(progress));
}

// Function to handle the completion of face extraction
void MainWindow::handleExtractionFinished(int faceCount)
{
    // Log the finish time of the extraction
    handleLogMessage("Extraction finished at: " + QDateTime::currentDateTime().toString());
    // Log the total number of faces extracted
    handleLogMessage("Extraction finished. Total faces extracted: " + QString::number(faceCount));
    // Enable the UI elements for selecting input file, output directory, and starting extraction
    ui->selectFileButton->setEnabled(true);
    ui->selectOutputDirButton->setEnabled(true);
    ui->extractFacesButton->setEnabled(true);
    ui->fpsComboBox->setEnabled(true);
    // Disable the stop extraction button
    ui->stopExtractionButton->setEnabled(false);
    // Reset the progress bar
    ui->progressBar->setValue(0);
    // Quit the worker thread
    workerThread.quit();
}

void MainWindow::handleLogMessage(const QString &message)
{
    // Append the log message to the log text edit
    ui->logTextEdit->append(message);
}

void MainWindow::handleDisplayLastFace(const QString &filePath)
{
    // Load the last saved face image and display it in the lastFaceLabel
    QPixmap pixmap(filePath);
    if (!pixmap.isNull()) {
        ui->lastFaceLabel->setPixmap(pixmap.scaled(ui->lastFaceLabel->size(), Qt::KeepAspectRatio));
    } else {
        handleLogMessage("Failed to load image: " + filePath);
    }
}

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

FaceExtractionWorker::FaceExtractionWorker(const std::string& inputPath, const std::string& outputDir, int fps, std::atomic<bool>& stopFlag)
    : inputPath(inputPath), outputDir(outputDir), fps(fps), stopFlag(stopFlag)
{
}

void FaceExtractionWorker::process()
{
    VideoCapture cap(inputPath);
    Mat frame;
    std::vector<string> images;

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
                cv_image<bgr_pixel> cimg(frame);
                std::vector<dlib::rectangle> faces = detector(cimg);

                for (auto& face : faces)
                {
                    saveFace(frame, face, faceCount++);
                }

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
    Mat faceImg = frame(Rect(Point(face.left(), face.top()), Point(face.right(), face.bottom()))).clone();
    fs::path outputFile = fs::path(outputDir) / ("face_" + std::to_string(faceCount) + ".jpg");
    imwrite(outputFile.string(), faceImg);
    emit logMessage(QString::fromStdString("Saved face to " + outputFile.string()));
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Videos and Images (*.mp4 *.jpg *.png)"));
    if (!fileName.isEmpty())
    {
        inputPath = fileName.toStdString();
        handleLogMessage("Selected file: " + fileName);
    }
}

void MainWindow::on_selectOutputDirButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Output Directory"));
    if (!dir.isEmpty())
    {
        outputDir = dir.toStdString();
        handleLogMessage("Selected output directory: " + dir);
    }
}

void MainWindow::on_extractFacesButton_clicked()
{
    if (inputPath.empty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Please select a file first."));
        return;
    }

    if (outputDir.empty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Please select an output directory."));
        return;
    }

    if (!fs::exists(inputPath))
    {
        QMessageBox::critical(this, tr("Error"), tr("Input file does not exist."));
        return;
    }

    if (!fs::exists(outputDir))
    {
        fs::create_directories(outputDir);
    }

    ui->selectFileButton->setEnabled(false);
    ui->selectOutputDirButton->setEnabled(false);
    ui->extractFacesButton->setEnabled(false);
    ui->fpsComboBox->setEnabled(false);
    ui->stopExtractionButton->setEnabled(true);
    ui->progressBar->setValue(0);

    handleLogMessage("Extraction started at: " + QDateTime::currentDateTime().toString());

    stopFlag = false;

    FaceExtractionWorker *worker = new FaceExtractionWorker(inputPath, outputDir, fps, stopFlag);
    worker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::started, worker, &FaceExtractionWorker::process);
    connect(worker, &FaceExtractionWorker::progressUpdated, this, &MainWindow::handleProgressUpdated);
    connect(worker, &FaceExtractionWorker::extractionFinished, this, &MainWindow::handleExtractionFinished);
    connect(worker, &FaceExtractionWorker::logMessage, this, &MainWindow::handleLogMessage);
    connect(worker, &FaceExtractionWorker::displayLastFace, this, &MainWindow::handleDisplayLastFace);
    connect(worker, &FaceExtractionWorker::extractionFinished, worker, &QObject::deleteLater);

    workerThread.start();
}

void MainWindow::on_stopExtractionButton_clicked()
{
    stopFlag = true;
    ui->stopExtractionButton->setEnabled(false);
}

void MainWindow::on_fpsComboBox_currentIndexChanged(int index)
{
    fps = ui->fpsComboBox->itemText(index).toInt();
}

void MainWindow::handleProgressUpdated(float progress)
{
    ui->progressBar->setValue(static_cast<int>(progress));
}

void MainWindow::handleExtractionFinished(int faceCount)
{
    handleLogMessage("Extraction finished at: " + QDateTime::currentDateTime().toString());
    handleLogMessage("Extraction finished. Total faces extracted: " + QString::number(faceCount));
    ui->selectFileButton->setEnabled(true);
    ui->selectOutputDirButton->setEnabled(true);
    ui->extractFacesButton->setEnabled(true);
    ui->fpsComboBox->setEnabled(true);
    ui->stopExtractionButton->setEnabled(false);
    ui->progressBar->setValue(0); // Reset the progress bar
    workerThread.quit();
}

void MainWindow::handleLogMessage(const QString &message)
{
    ui->logTextEdit->append(message);
}

void MainWindow::handleDisplayLastFace(const QString &filePath)
{
    QPixmap pixmap(filePath);
    if (!pixmap.isNull()) {
        ui->lastFaceLabel->setPixmap(pixmap.scaled(ui->lastFaceLabel->size(), Qt::KeepAspectRatio));
    } else {
        handleLogMessage("Failed to load image: " + filePath);
    }
}

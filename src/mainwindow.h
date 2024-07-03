#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp> // Include OpenCV library
#include <dlib/image_processing/frontal_face_detector.h> // Include dlib library for face detection
#include <dlib/opencv/cv_image.h>
#include <dlib/image_processing.h>
#include <iostream>
#include <filesystem>
#include <QThread>
#include <atomic>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// FaceExtractionWorker class
class FaceExtractionWorker : public QObject
{
    Q_OBJECT

public:
    // Constructor
    FaceExtractionWorker(const std::string& inputPath, const std::string& outputDir, int fps, std::atomic<bool>& stopFlag);

signals:
    // Signals emitted during face extraction process
    void progressUpdated(float progress);
    void extractionFinished(int faceCount);
    void logMessage(const QString &message);
    void displayLastFace(const QString &filePath);

public slots:
    // Slot for processing face extraction
    void process();

private:
    std::string inputPath; // Input video file path
    std::string outputDir; // Output directory for saving extracted faces
    int fps; // Frames per second for video processing
    std::atomic<bool>& stopFlag; // Atomic flag to stop the extraction process
    void saveFace(const cv::Mat& frame, const dlib::rectangle& face, int faceCount); // Function to save extracted face
};

// MainWindow class
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor
    MainWindow(QWidget *parent = nullptr);
    // Destructor
    ~MainWindow();

private slots:
    // Slots for handling UI events
    void on_selectFileButton_clicked();
    void on_selectOutputDirButton_clicked();
    void on_extractFacesButton_clicked();
    void on_stopExtractionButton_clicked();
    void on_fpsComboBox_currentIndexChanged(int index);
    void handleProgressUpdated(float progress);
    void handleExtractionFinished(int faceCount);
    void handleLogMessage(const QString &message);
    void handleDisplayLastFace(const QString &filePath);

private:
    Ui::MainWindow *ui; // User interface object
    std::string inputPath; // Input video file path
    std::string outputDir; // Output directory for saving extracted faces
    int fps; // Frames per second for video processing
    QThread workerThread; // Thread for running face extraction worker
    std::atomic<bool> stopFlag; // Atomic flag to stop the extraction process
};

#endif // MAINWINDOW_H

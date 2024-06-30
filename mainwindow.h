#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv/cv_image.h>
#include <dlib/image_processing.h>
#include <iostream>
#include <filesystem>
#include <QThread>
#include <atomic>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FaceExtractionWorker : public QObject
{
    Q_OBJECT

public:
    FaceExtractionWorker(const std::string& inputPath, const std::string& outputDir, int fps, std::atomic<bool>& stopFlag);

signals:
    void progressUpdated(float progress);
    void extractionFinished(int faceCount);
    void logMessage(const QString &message);
    void displayLastFace(const cv::Mat &face);

public slots:
    void process();

private:
    std::string inputPath;
    std::string outputDir;
    int fps;
    std::atomic<bool>& stopFlag;
    void saveFace(const cv::Mat& frame, const dlib::rectangle& face, int faceCount);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_selectFileButton_clicked();
    void on_selectOutputDirButton_clicked();
    void on_extractFacesButton_clicked();
    void on_stopExtractionButton_clicked();
    void on_fpsComboBox_currentIndexChanged(int index);
    void handleProgressUpdated(float progress);
    void handleExtractionFinished(int faceCount);
    void handleLogMessage(const QString &message);
    void handleDisplayLastFace(const cv::Mat &face);

private:
    Ui::MainWindow *ui;
    std::string inputPath;
    std::string outputDir;
    int fps;
    QThread workerThread;
    std::atomic<bool> stopFlag;
};

#endif // MAINWINDOW_H

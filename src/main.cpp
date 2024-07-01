#include "mainwindow.h" // Include the header file for the MainWindow class
#include <QApplication> // Include the QApplication header file

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Create a QApplication object
    MainWindow w; // Create an instance of the MainWindow class
    w.show(); // Show the main window
    return a.exec(); // Start the event loop and execute the application
}

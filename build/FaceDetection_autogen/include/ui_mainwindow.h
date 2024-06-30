/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *selectFileButton;
    QPushButton *selectOutputDirButton;
    QPushButton *extractFacesButton;
    QPushButton *stopExtractionButton;
    QComboBox *fpsComboBox;
    QProgressBar *progressBar;
    QTextEdit *logTextEdit;
    QLabel *lastFaceLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        selectFileButton = new QPushButton(centralwidget);
        selectFileButton->setObjectName(QString::fromUtf8("selectFileButton"));

        verticalLayout->addWidget(selectFileButton);

        selectOutputDirButton = new QPushButton(centralwidget);
        selectOutputDirButton->setObjectName(QString::fromUtf8("selectOutputDirButton"));

        verticalLayout->addWidget(selectOutputDirButton);

        extractFacesButton = new QPushButton(centralwidget);
        extractFacesButton->setObjectName(QString::fromUtf8("extractFacesButton"));

        verticalLayout->addWidget(extractFacesButton);

        stopExtractionButton = new QPushButton(centralwidget);
        stopExtractionButton->setObjectName(QString::fromUtf8("stopExtractionButton"));
        stopExtractionButton->setEnabled(false);

        verticalLayout->addWidget(stopExtractionButton);

        fpsComboBox = new QComboBox(centralwidget);
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->addItem(QString());
        fpsComboBox->setObjectName(QString::fromUtf8("fpsComboBox"));

        verticalLayout->addWidget(fpsComboBox);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));

        verticalLayout->addWidget(progressBar);

        logTextEdit = new QTextEdit(centralwidget);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));

        verticalLayout->addWidget(logTextEdit);

        lastFaceLabel = new QLabel(centralwidget);
        lastFaceLabel->setObjectName(QString::fromUtf8("lastFaceLabel"));
        lastFaceLabel->setMinimumSize(QSize(200, 200));
        lastFaceLabel->setFrameShape(QFrame::Box);
        lastFaceLabel->setScaledContents(true);
        lastFaceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lastFaceLabel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Face Extractor", nullptr));
        selectFileButton->setText(QCoreApplication::translate("MainWindow", "Select Image/Video", nullptr));
        selectOutputDirButton->setText(QCoreApplication::translate("MainWindow", "Select Output Directory", nullptr));
        extractFacesButton->setText(QCoreApplication::translate("MainWindow", "Extract Faces", nullptr));
        stopExtractionButton->setText(QCoreApplication::translate("MainWindow", "Stop Extraction", nullptr));
        fpsComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        fpsComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        fpsComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        fpsComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        fpsComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        fpsComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        fpsComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        fpsComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        fpsComboBox->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));
        fpsComboBox->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));
        fpsComboBox->setItemText(10, QCoreApplication::translate("MainWindow", "11", nullptr));
        fpsComboBox->setItemText(11, QCoreApplication::translate("MainWindow", "12", nullptr));
        fpsComboBox->setItemText(12, QCoreApplication::translate("MainWindow", "13", nullptr));
        fpsComboBox->setItemText(13, QCoreApplication::translate("MainWindow", "14", nullptr));
        fpsComboBox->setItemText(14, QCoreApplication::translate("MainWindow", "15", nullptr));

        fpsComboBox->setCurrentText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

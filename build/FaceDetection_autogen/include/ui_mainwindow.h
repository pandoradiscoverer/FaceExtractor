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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QTextEdit *logTextEdit;
    QLabel *lastFaceLabel;
    QSplitter *splitter;
    QPushButton *selectFileButton;
    QPushButton *selectOutputDirButton;
    QPushButton *extractFacesButton;
    QPushButton *stopExtractionButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *fpsComboBox;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(389, 472);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 230, 371, 25));
        logTextEdit = new QTextEdit(centralwidget);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setGeometry(QRect(10, 270, 371, 146));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(36, 31, 49, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(54, 46, 73, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(45, 38, 61, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(18, 15, 24, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(24, 21, 33, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(38, 162, 105, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        QBrush brush9(QColor(38, 162, 105, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        logTextEdit->setPalette(palette);
        logTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        logTextEdit->setCursorWidth(0);
        lastFaceLabel = new QLabel(centralwidget);
        lastFaceLabel->setObjectName(QString::fromUtf8("lastFaceLabel"));
        lastFaceLabel->setGeometry(QRect(180, 10, 200, 200));
        lastFaceLabel->setMinimumSize(QSize(200, 200));
        lastFaceLabel->setFrameShape(QFrame::Box);
        lastFaceLabel->setScaledContents(true);
        lastFaceLabel->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(19, 9, 141, 127));
        splitter->setOrientation(Qt::Vertical);
        selectFileButton = new QPushButton(splitter);
        selectFileButton->setObjectName(QString::fromUtf8("selectFileButton"));
        splitter->addWidget(selectFileButton);
        selectOutputDirButton = new QPushButton(splitter);
        selectOutputDirButton->setObjectName(QString::fromUtf8("selectOutputDirButton"));
        splitter->addWidget(selectOutputDirButton);
        extractFacesButton = new QPushButton(splitter);
        extractFacesButton->setObjectName(QString::fromUtf8("extractFacesButton"));
        splitter->addWidget(extractFacesButton);
        stopExtractionButton = new QPushButton(splitter);
        stopExtractionButton->setObjectName(QString::fromUtf8("stopExtractionButton"));
        stopExtractionButton->setEnabled(false);
        splitter->addWidget(stopExtractionButton);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        fpsComboBox = new QComboBox(widget);
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

        horizontalLayout->addWidget(fpsComboBox);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        splitter->addWidget(widget);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 389, 22));
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
        label->setText(QCoreApplication::translate("MainWindow", "FPS Extracted ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

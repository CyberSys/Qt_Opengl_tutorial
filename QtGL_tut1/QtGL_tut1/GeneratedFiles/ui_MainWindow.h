/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <openglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    OpenglWidget *Gl_widget;
    QGroupBox *groupBox;
    QSlider *RedSlider;
    QSlider *GreenSlider;
    QSlider *BlueSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *AlphaSlider;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1101, 839);
        MainWindowClass->setMaximumSize(QSize(1101, 839));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Gl_widget = new OpenglWidget(centralWidget);
        Gl_widget->setObjectName(QString::fromUtf8("Gl_widget"));
        Gl_widget->setGeometry(QRect(0, 0, 711, 781));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(720, 10, 371, 351));
        RedSlider = new QSlider(groupBox);
        RedSlider->setObjectName(QString::fromUtf8("RedSlider"));
        RedSlider->setGeometry(QRect(190, 40, 160, 22));
        RedSlider->setMaximum(100);
        RedSlider->setValue(100);
        RedSlider->setOrientation(Qt::Horizontal);
        GreenSlider = new QSlider(groupBox);
        GreenSlider->setObjectName(QString::fromUtf8("GreenSlider"));
        GreenSlider->setGeometry(QRect(190, 130, 160, 22));
        GreenSlider->setMaximum(100);
        GreenSlider->setValue(100);
        GreenSlider->setOrientation(Qt::Horizontal);
        BlueSlider = new QSlider(groupBox);
        BlueSlider->setObjectName(QString::fromUtf8("BlueSlider"));
        BlueSlider->setGeometry(QRect(190, 240, 160, 22));
        BlueSlider->setMaximum(100);
        BlueSlider->setValue(100);
        BlueSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 50, 47, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 140, 47, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 240, 47, 13));
        AlphaSlider = new QSlider(groupBox);
        AlphaSlider->setObjectName(QString::fromUtf8("AlphaSlider"));
        AlphaSlider->setGeometry(QRect(190, 310, 160, 22));
        AlphaSlider->setMaximum(100);
        AlphaSlider->setValue(100);
        AlphaSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 310, 71, 16));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1101, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Colors", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "Red", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "Green", nullptr));
        label_3->setText(QApplication::translate("MainWindowClass", "Blue", nullptr));
        label_4->setText(QApplication::translate("MainWindowClass", "transperancy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

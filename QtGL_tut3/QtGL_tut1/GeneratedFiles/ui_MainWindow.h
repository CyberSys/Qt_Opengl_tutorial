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
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
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
    QGroupBox *groupBox_2;
    QSpinBox *PositionY;
    QSpinBox *PositionX;
    QSpinBox *ScaleY;
    QSpinBox *ScaleX;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QDial *RotationZ;
    QLabel *label_13;
    QGroupBox *groupBox_3;
    QPushButton *NewSprite;
    QLabel *SpritePic;
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
        groupBox->setGeometry(QRect(720, 10, 371, 151));
        RedSlider = new QSlider(groupBox);
        RedSlider->setObjectName(QString::fromUtf8("RedSlider"));
        RedSlider->setGeometry(QRect(190, 20, 160, 22));
        RedSlider->setMaximum(100);
        RedSlider->setValue(100);
        RedSlider->setOrientation(Qt::Horizontal);
        GreenSlider = new QSlider(groupBox);
        GreenSlider->setObjectName(QString::fromUtf8("GreenSlider"));
        GreenSlider->setGeometry(QRect(190, 50, 160, 22));
        GreenSlider->setMaximum(100);
        GreenSlider->setValue(100);
        GreenSlider->setOrientation(Qt::Horizontal);
        BlueSlider = new QSlider(groupBox);
        BlueSlider->setObjectName(QString::fromUtf8("BlueSlider"));
        BlueSlider->setGeometry(QRect(190, 80, 160, 22));
        BlueSlider->setMaximum(100);
        BlueSlider->setValue(100);
        BlueSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 47, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 60, 47, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 90, 47, 13));
        AlphaSlider = new QSlider(groupBox);
        AlphaSlider->setObjectName(QString::fromUtf8("AlphaSlider"));
        AlphaSlider->setGeometry(QRect(190, 110, 160, 22));
        AlphaSlider->setMaximum(100);
        AlphaSlider->setValue(100);
        AlphaSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 110, 71, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(720, 170, 371, 281));
        PositionY = new QSpinBox(groupBox_2);
        PositionY->setObjectName(QString::fromUtf8("PositionY"));
        PositionY->setGeometry(QRect(260, 20, 42, 22));
        PositionY->setMaximum(1000);
        PositionY->setValue(50);
        PositionX = new QSpinBox(groupBox_2);
        PositionX->setObjectName(QString::fromUtf8("PositionX"));
        PositionX->setGeometry(QRect(160, 20, 42, 22));
        PositionX->setMaximum(1000);
        PositionX->setValue(50);
        ScaleY = new QSpinBox(groupBox_2);
        ScaleY->setObjectName(QString::fromUtf8("ScaleY"));
        ScaleY->setGeometry(QRect(260, 70, 42, 22));
        ScaleY->setMaximum(1000);
        ScaleY->setValue(100);
        ScaleX = new QSpinBox(groupBox_2);
        ScaleX->setObjectName(QString::fromUtf8("ScaleX"));
        ScaleX->setGeometry(QRect(160, 70, 42, 22));
        ScaleX->setMaximum(1000);
        ScaleX->setValue(100);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 20, 41, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 70, 47, 13));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(140, 20, 16, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(140, 70, 16, 16));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(240, 20, 16, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(240, 70, 16, 16));
        RotationZ = new QDial(groupBox_2);
        RotationZ->setObjectName(QString::fromUtf8("RotationZ"));
        RotationZ->setGeometry(QRect(200, 120, 121, 141));
        RotationZ->setMaximum(360);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(70, 190, 47, 13));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(720, 460, 371, 321));
        NewSprite = new QPushButton(groupBox_3);
        NewSprite->setObjectName(QString::fromUtf8("NewSprite"));
        NewSprite->setGeometry(QRect(270, 290, 91, 23));
        SpritePic = new QLabel(groupBox_3);
        SpritePic->setObjectName(QString::fromUtf8("SpritePic"));
        SpritePic->setGeometry(QRect(20, 30, 331, 241));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1101, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        MainWindowClass->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Tutorial_2", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Colors", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "Red", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "Green", nullptr));
        label_3->setText(QApplication::translate("MainWindowClass", "Blue", nullptr));
        label_4->setText(QApplication::translate("MainWindowClass", "transperancy", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "Transformations 2D", nullptr));
        label_5->setText(QApplication::translate("MainWindowClass", "Position", nullptr));
        label_6->setText(QApplication::translate("MainWindowClass", "Scale", nullptr));
        label_7->setText(QApplication::translate("MainWindowClass", "X", nullptr));
        label_8->setText(QApplication::translate("MainWindowClass", "X", nullptr));
        label_9->setText(QApplication::translate("MainWindowClass", "Y", nullptr));
        label_10->setText(QApplication::translate("MainWindowClass", "Y", nullptr));
        label_13->setText(QApplication::translate("MainWindowClass", "Rotation ", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindowClass", "Sprite", nullptr));
        NewSprite->setText(QApplication::translate("MainWindowClass", "NewSprite", nullptr));
        SpritePic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

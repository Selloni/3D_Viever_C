/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "scene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Scene *sceneWidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QComboBox *line_color;
    QLabel *label_5;
    QRadioButton *line_solid;
    QRadioButton *line_dashed;
    QLabel *label_6;
    QLabel *label_7;
    QRadioButton *vertex_square;
    QLabel *label_8;
    QLabel *label_9;
    QRadioButton *vertex_no;
    QComboBox *vertex_color;
    QLabel *label_10;
    QLabel *label_11;
    QRadioButton *vertex_circle;
    QSlider *line_width;
    QProgressBar *line_progress;
    QSlider *vertex_wigth;
    QPushButton *background;
    QDoubleSpinBox *rotateX;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *rotetaY;
    QDoubleSpinBox *rotateZ;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1141, 775);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sceneWidget = new Scene(centralwidget);
        sceneWidget->setObjectName(QString::fromUtf8("sceneWidget"));
        sceneWidget->setGeometry(QRect(29, 19, 791, 651));
        sceneWidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(930, 490, 121, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(950, 30, 91, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(940, 210, 111, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(920, 60, 58, 16));
        line_color = new QComboBox(centralwidget);
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->setObjectName(QString::fromUtf8("line_color"));
        line_color->setGeometry(QRect(960, 51, 103, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(900, 100, 41, 16));
        line_solid = new QRadioButton(centralwidget);
        line_solid->setObjectName(QString::fromUtf8("line_solid"));
        line_solid->setGeometry(QRect(950, 100, 61, 20));
        line_dashed = new QRadioButton(centralwidget);
        line_dashed->setObjectName(QString::fromUtf8("line_dashed"));
        line_dashed->setGeometry(QRect(1010, 100, 99, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(900, 140, 58, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(970, 280, 58, 16));
        vertex_square = new QRadioButton(centralwidget);
        vertex_square->setObjectName(QString::fromUtf8("vertex_square"));
        vertex_square->setGeometry(QRect(1010, 310, 99, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(920, 249, 58, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(910, 350, 31, 16));
        vertex_no = new QRadioButton(centralwidget);
        vertex_no->setObjectName(QString::fromUtf8("vertex_no"));
        vertex_no->setGeometry(QRect(960, 310, 61, 20));
        vertex_color = new QComboBox(centralwidget);
        vertex_color->addItem(QString());
        vertex_color->addItem(QString());
        vertex_color->addItem(QString());
        vertex_color->addItem(QString());
        vertex_color->addItem(QString());
        vertex_color->setObjectName(QString::fromUtf8("vertex_color"));
        vertex_color->setGeometry(QRect(970, 240, 103, 41));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(400, 710, 51, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(200, 710, 51, 16));
        vertex_circle = new QRadioButton(centralwidget);
        vertex_circle->setObjectName(QString::fromUtf8("vertex_circle"));
        vertex_circle->setGeometry(QRect(890, 310, 61, 20));
        line_width = new QSlider(centralwidget);
        line_width->setObjectName(QString::fromUtf8("line_width"));
        line_width->setGeometry(QRect(940, 140, 141, 25));
        line_width->setMinimum(1);
        line_width->setMaximum(40);
        line_width->setOrientation(Qt::Horizontal);
        line_progress = new QProgressBar(centralwidget);
        line_progress->setObjectName(QString::fromUtf8("line_progress"));
        line_progress->setGeometry(QRect(900, 170, 181, 23));
        line_progress->setMinimum(2);
        line_progress->setMaximum(40);
        line_progress->setValue(2);
        vertex_wigth = new QSlider(centralwidget);
        vertex_wigth->setObjectName(QString::fromUtf8("vertex_wigth"));
        vertex_wigth->setGeometry(QRect(940, 350, 141, 25));
        vertex_wigth->setMinimum(1);
        vertex_wigth->setMaximum(40);
        vertex_wigth->setOrientation(Qt::Horizontal);
        background = new QPushButton(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(900, 420, 181, 41));
        rotateX = new QDoubleSpinBox(centralwidget);
        rotateX->setObjectName(QString::fromUtf8("rotateX"));
        rotateX->setGeometry(QRect(450, 700, 51, 31));
        rotateX->setDecimals(1);
        rotateX->setMinimum(0.000000000000000);
        rotateX->setMaximum(1.000000000000000);
        rotateX->setSingleStep(0.100000000000000);
        rotateX->setValue(0.600000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(340, 700, 51, 31));
        doubleSpinBox_4->setDecimals(1);
        doubleSpinBox_5 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(290, 700, 51, 31));
        doubleSpinBox_5->setDecimals(1);
        doubleSpinBox_6 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(240, 700, 51, 31));
        doubleSpinBox_6->setDecimals(1);
        rotetaY = new QDoubleSpinBox(centralwidget);
        rotetaY->setObjectName(QString::fromUtf8("rotetaY"));
        rotetaY->setGeometry(QRect(500, 700, 51, 31));
        rotetaY->setDecimals(1);
        rotetaY->setMaximum(1.000000000000000);
        rotetaY->setSingleStep(0.100000000000000);
        rotetaY->setValue(0.600000000000000);
        rotateZ = new QDoubleSpinBox(centralwidget);
        rotateZ->setObjectName(QString::fromUtf8("rotateZ"));
        rotateZ->setGeometry(QRect(550, 700, 51, 31));
        rotateZ->setDecimals(1);
        rotateZ->setMaximum(1.000000000000000);
        rotateZ->setSingleStep(0.100000000000000);
        rotateZ->setValue(0.600000000000000);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1141, 24));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "LINE SETTING", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "VERTEX SETTING", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        line_color->setItemText(0, QCoreApplication::translate("MainWindow", "Write", nullptr));
        line_color->setItemText(1, QCoreApplication::translate("MainWindow", "Black", nullptr));
        line_color->setItemText(2, QCoreApplication::translate("MainWindow", "Red", nullptr));
        line_color->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        line_color->setItemText(4, QCoreApplication::translate("MainWindow", "Blue", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "style", nullptr));
        line_solid->setText(QCoreApplication::translate("MainWindow", "solid", nullptr));
        line_dashed->setText(QCoreApplication::translate("MainWindow", "dashed", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "style", nullptr));
        vertex_square->setText(QCoreApplication::translate("MainWindow", "square", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        vertex_no->setText(QCoreApplication::translate("MainWindow", "no", nullptr));
        vertex_color->setItemText(0, QCoreApplication::translate("MainWindow", "Write", nullptr));
        vertex_color->setItemText(1, QCoreApplication::translate("MainWindow", "Black", nullptr));
        vertex_color->setItemText(2, QCoreApplication::translate("MainWindow", "Red", nullptr));
        vertex_color->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        vertex_color->setItemText(4, QCoreApplication::translate("MainWindow", "Blue", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "ROTATE", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "MOVE", nullptr));
        vertex_circle->setText(QCoreApplication::translate("MainWindow", "circle", nullptr));
        background->setText(QCoreApplication::translate("MainWindow", "BACKGROUND SETTING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

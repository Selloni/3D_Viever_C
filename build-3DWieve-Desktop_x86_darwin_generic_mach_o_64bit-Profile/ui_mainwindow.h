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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
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
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *line_color;
    QLabel *label_5;
    QRadioButton *line_solid;
    QRadioButton *line_dashed;
    QLabel *label_6;
    QScrollBar *line_width;
    QLabel *label_7;
    QRadioButton *line_dashed_2;
    QScrollBar *line_width_2;
    QLabel *label_8;
    QLabel *label_9;
    QRadioButton *vertex_no;
    QComboBox *line_color_2;
    QLabel *label_10;
    QLabel *label_11;
    QRadioButton *vertex_circle;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sceneWidget = new Scene(centralwidget);
        sceneWidget->setObjectName(QString::fromUtf8("sceneWidget"));
        sceneWidget->setGeometry(QRect(29, 19, 531, 500));
        sceneWidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(620, 470, 121, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 20, 91, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(630, 200, 111, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(610, 400, 161, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(610, 50, 58, 16));
        line_color = new QComboBox(centralwidget);
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->addItem(QString());
        line_color->setObjectName(QString::fromUtf8("line_color"));
        line_color->setGeometry(QRect(650, 41, 103, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(590, 90, 41, 16));
        line_solid = new QRadioButton(centralwidget);
        line_solid->setObjectName(QString::fromUtf8("line_solid"));
        line_solid->setGeometry(QRect(640, 90, 61, 20));
        line_dashed = new QRadioButton(centralwidget);
        line_dashed->setObjectName(QString::fromUtf8("line_dashed"));
        line_dashed->setGeometry(QRect(700, 90, 99, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(590, 130, 58, 16));
        line_width = new QScrollBar(centralwidget);
        line_width->setObjectName(QString::fromUtf8("line_width"));
        line_width->setGeometry(QRect(640, 130, 131, 16));
        line_width->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(660, 270, 58, 16));
        line_dashed_2 = new QRadioButton(centralwidget);
        line_dashed_2->setObjectName(QString::fromUtf8("line_dashed_2"));
        line_dashed_2->setGeometry(QRect(700, 300, 99, 20));
        line_width_2 = new QScrollBar(centralwidget);
        line_width_2->setObjectName(QString::fromUtf8("line_width_2"));
        line_width_2->setGeometry(QRect(640, 340, 131, 16));
        line_width_2->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(610, 239, 58, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(600, 340, 31, 16));
        vertex_no = new QRadioButton(centralwidget);
        vertex_no->setObjectName(QString::fromUtf8("vertex_no"));
        vertex_no->setGeometry(QRect(650, 300, 61, 20));
        line_color_2 = new QComboBox(centralwidget);
        line_color_2->addItem(QString());
        line_color_2->addItem(QString());
        line_color_2->addItem(QString());
        line_color_2->addItem(QString());
        line_color_2->addItem(QString());
        line_color_2->setObjectName(QString::fromUtf8("line_color_2"));
        line_color_2->setGeometry(QRect(660, 230, 103, 41));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(410, 540, 51, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(210, 540, 51, 16));
        vertex_circle = new QRadioButton(centralwidget);
        vertex_circle->setObjectName(QString::fromUtf8("vertex_circle"));
        vertex_circle->setGeometry(QRect(580, 300, 61, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
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
        label_3->setText(QCoreApplication::translate("MainWindow", "BACKGROUND SETTING", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        line_color->setItemText(0, QCoreApplication::translate("MainWindow", "Black", nullptr));
        line_color->setItemText(1, QCoreApplication::translate("MainWindow", "Write", nullptr));
        line_color->setItemText(2, QCoreApplication::translate("MainWindow", "Red", nullptr));
        line_color->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        line_color->setItemText(4, QCoreApplication::translate("MainWindow", "Blue", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "style", nullptr));
        line_solid->setText(QCoreApplication::translate("MainWindow", "solid", nullptr));
        line_dashed->setText(QCoreApplication::translate("MainWindow", "dashed", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "style", nullptr));
        line_dashed_2->setText(QCoreApplication::translate("MainWindow", "square", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        vertex_no->setText(QCoreApplication::translate("MainWindow", "no", nullptr));
        line_color_2->setItemText(0, QCoreApplication::translate("MainWindow", "Black", nullptr));
        line_color_2->setItemText(1, QCoreApplication::translate("MainWindow", "Write", nullptr));
        line_color_2->setItemText(2, QCoreApplication::translate("MainWindow", "Red", nullptr));
        line_color_2->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        line_color_2->setItemText(4, QCoreApplication::translate("MainWindow", "Blue", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "ROTATE", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "MOVE", nullptr));
        vertex_circle->setText(QCoreApplication::translate("MainWindow", "circle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
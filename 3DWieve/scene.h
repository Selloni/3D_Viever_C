#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
//#include <QGLWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
//#include <QMatrix4x4>
//#include "mainwindow.h"

class Scene: public QOpenGLWidget
{
private slots:

    float xRot, yRot, zRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent*) override; // click mouse
    void mouseMoveEvent(QMouseEvent*) override; // move mouse

    void initializeGL() override;  // вызываеться после вызова конструктора
    void resizGL( int w, int h);  //  когда изменяеться размер окна
    void paintGL() override;  // нужно перерасовть окно
public:

    Scene(QWidget *parent = 0);
    void line_color(int l_c);
    int a;


};

#endif // SCENE_H

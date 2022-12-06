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
    void line_style(int l_s);
    void vertex_color(int w_c);
    void veretex_stile(int v_s);

    int l_c = 2;
    int l_s = 0;
    int l_w = 1;

    int v_c = 2;
    int v_s = 0;
    int v_w = 1;
//    QColor color;
    double back_red;
    double back_green;
    double back_blue;
    double back_alpha;


};

#endif // SCENE_H

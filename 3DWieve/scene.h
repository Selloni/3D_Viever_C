#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
//#include <QGLWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
//#include <QMatrix4x4>

class Scene: public QOpenGLWidget
{
private slots:
    float xRot, yRot, zRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent*); // click mouse
    void mouseMoveEvent(QMouseEvent*); // move mouse

    void initializeGL();  // вызываеться после вызова конструктора
    void paintGL();  // нужно перерасовть окно
    void resizGL( int w, int h);  //  когда изменяеться размер окна
public:
    Scene(QWidget *parent = 0);



};

#endif // SCENE_H

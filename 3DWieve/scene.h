#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>


class Scene: public QOpenGLWidget
{
public:
    Scene(QOpenGLWidget *parent);

    void initializeGL();  // вызываеться после вызова конструктора
    void paintGL();  // нужно перерасовть окно
    void resizGL( int w, int h);  //  когда изменяеться размер окна

};

#endif // SCENE_H

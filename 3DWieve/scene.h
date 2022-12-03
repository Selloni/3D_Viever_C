#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

class Scene: public QOpenGLWidget
{
public:
    Scene(QWidget *parent);

    void initializeGL();
    void paintGL();
    void resizGL( int w, int h);

};

#endif // SCENE_H

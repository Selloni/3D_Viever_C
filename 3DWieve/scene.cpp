#include "scene.h"


Scene::Scene(QOpenGLWidget *parent):
    QOpenGLWidget (parent)
{
}

void Scene::initializeGL() {

}

void Scene::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    QMatrix4x4 matrix;
    matrix.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);
    matrix.translate(0.0f, 0.0f, -1.0f);

    GLfloat vertices[] {
        0.0f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };

    GLfloat colors[] {
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
    };

}
void Scene::resizGL( int w, int h) {
    glViewport(0, 0, w, h);
}

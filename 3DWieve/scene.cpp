#include "scene.h"


Scene::Scene(QWidget *parent):
    QOpenGLWidget (parent)
{
}

void Scene::initializeGL() {
    glEnable(GL_DEPTH_TEST); // буфер клубины
    glClearColor( 0.0f, 0.0f, 0.f, 0.0f );  //  colo bakcground
}
float arr[] = {0,0,0, -1,0,-1, 0,1,0, 1,0,0}; // масив вершин

void Scene::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glVertexPointer(3, GL_FLOAT, 0, &arr);  // берет каждые три точки под вершины
    glEnableClientState(GL_VERTEX_ARRAY);

        glColor3d(1,0,1);  //  color

        glEnable(GL_LINE_STIPPLE); // пунктирная линия
        glLineStipple(1, 0x00ff);

        glLineWidth(6); // size line
        glDrawArrays(GL_LINE_LOOP,0,4);
        glPointSize(16);  // size point

        glDrawArrays(GL_POINTS, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Scene::resizGL( int w, int h) {
    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Создаем проекцию
    glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
    glLoadIdentity(); // загружаем матрицу
    // Establish clipping volume (left, right, bottom, top, near, far)
    glFrustum(-10, 10, -10, 10, 10, 10);  //  перспективная проекция

}

void Scene::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

void Scene::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1/M_PI*(mo->pos().y() - mPos.y());
    xRot = 1/M_PI*(mo->pos().x() - mPos.x());
    update(); //обовление кординат
}



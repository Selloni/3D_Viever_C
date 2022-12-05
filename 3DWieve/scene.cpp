#include "scene.h"



Scene::Scene(QWidget *parent):
    QOpenGLWidget (parent)
{
}

void Scene::initializeGL() {
    glScalef(0.5, 0.5, 0.5);  // для маштаба
    glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
    glLoadIdentity(); // закреплаяем изменения
    glEnable(GL_DEPTH_TEST); // буфер глубины
    glClearColor( 0.0f, 0.0f, 0.f, 0.0f );  //  colo bakcground
}

float arr[] = {0,0,0, -1,0,-1, 0,1,0, 1,0,0}; // масив вершин
int mass[] = {1,0, 1,2, 1,3, 2,3, 2,4, 3,4 };  // масив соединений


void line_color(int a, int b, int c) {
    glColor3d(a,b,c);
    update();
}

void Scene::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  // очищаем буфера

    glVertexPointer(3, GL_FLOAT, 0, &arr);  // берет каждые три точки под вершины из масива
        glEnableClientState(GL_VERTEX_ARRAY);  //  разрешаем рисовать из масива вершин
        line_color;
//        glColor3d(1,0,1);  //  color

        glEnable(GL_LINE_STIPPLE); // пунктирная линия
        glLineStipple(1, 0x00ff);

        glDrawElements(GL_LINES, 12 , GL_UNSIGNED_INT, &mass); // рисуем не зависмыми линиями

        glLineWidth(6); // size line
//        glDrawArrays(GL_LINE_LOOP,0,4);  // цельная линия
        glPointSize(16);  // size point
        glEnable(GL_POINT_SMOOTH);  // круглые точки
        glDrawArrays(GL_POINTS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glRotatef(xRot, 1, 0, 0);// для движения мышью
    glRotatef(yRot, 0, 1, 0);
}



void MoveCamera() {  // для движения камеры
//    glRotated(-20, 1, 0, 0);
    glTranslatef(0, 0, 30);
}



void Scene::resizGL( int w, int h) {
    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Создаем проекцию
    glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
    glLoadIdentity(); // загружаем матрицу
    // Establish clipping volume (left, right, bottom, top, near, far)
    glFrustum(-100, 100, -100, 100, 2, 100);  //  перспективная проекция
}


void Scene::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}
void Scene::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1/M_PI*(mo->pos().y() - mPos.y());
    yRot = 1/M_PI*(mo->pos().x() - mPos.x());
    update(); //обовление кординат
}



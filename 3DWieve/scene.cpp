#include "scene.h"


Scene::Scene(QWidget *parent):
    QOpenGLWidget (parent)
{
}

void Scene::initializeGL() {
    glClearColor( 0.0f, 0.0f, 0.f, 0.0f );  //  colo bakcground
}
float arr[] = {0, 0, -0.5, 1, 0, -1, 0, 1, -1}; // масив вершин
void Scene::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT);
//    glVertexPointer(3, GL_FLOAT, 0, &arr);  // берет каждые три точки под вершины
//    glEnableClientState(GL_VERTEX_ARRAY);
//        glColor3d(1,0,1);
//        glDrawArrays(GL_VERTEX_ARRAY,0,3);
//    glDisableClientState(GL_VERTEX_ARRAY);
    glBegin(GL_TRIANGLES);

    glVertex3d(0, 0, -0.5);
    glVertex3d(1, 0, -1);
    glVertex3d(0, 1, -1);
    glEnd();

}

void Scene::resizGL( int w, int h) {
    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Создаем проекцию
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Establish clipping volume (left, right, bottom, top, near, far)
//    glOrtho(-1, 1, -1, 1, 1, 2);
    glFrustum(-1, 1, -1, 1, 1, 2);



//    // Reset coordinate system
//    glMatrixMode( GL_PROJECTION );
//    glLoadIdentity();

//    // Establish clipping volume (left, right, bottom, top, near, far)
//    glOrtho( -200, 200, -200, 200, 1.0, -1.0 );

//    glMatrixMode( GL_MODELVIEW );
//    glLoadIdentity();
}

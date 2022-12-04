#include "scene.h"


Scene::Scene(QWidget *parent):
    QOpenGLWidget (parent)
{
}

void Scene::initializeGL() {
    glClearColor( 0.0f, 0.0f, 0.f, 0.0f );  //  colo bakcground
}

void Scene::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex2d(0,34);
    glVertex2d(1,0);
    glVertex2d(0,1);
    glEnd();

}

//    glClear(GL_COLOR_BUFFER_BIT);
//    QMatrix4x4 matrix;
//    matrix.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f); // x,y,z
//    matrix.translate(0.0f, 0.0f, -1.0f);

//    GLfloat vertices[] {
//        0.0f, 0.5f,
//        -0.5f, -0.5f,
//        0.5f, -0.5f
//    };

//    GLfloat colors[] {
//        1.0f, 1.0f, 1.0f,
//        1.0f, 1.0f, 1.0f,
//        1.0f, 1.0f, 1.0f,
//    };
//}

void Scene::resizGL( int w, int h) {
    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );



//    // Reset coordinate system
//    glMatrixMode( GL_PROJECTION );
//    glLoadIdentity();

//    // Establish clipping volume (left, right, bottom, top, near, far)
//    glOrtho( -200, 200, -200, 200, 1.0, -1.0 );

//    glMatrixMode( GL_MODELVIEW );
//    glLoadIdentity();
}

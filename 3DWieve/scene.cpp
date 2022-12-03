#include "scene.h"


Scene::Scene(QWidget *parent):
    QGLWidget (parent)
{
}

void initializeGL() {

}

void paintGL();
void resizGL( int w, int h);

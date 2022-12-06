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

}

float arr[] = {0,0,0, -1,0,-1, 0,1,0, 1,0,0}; // масив вершин
int mass[] = {1,0, 1,2, 1,3, 2,3, 2,4, 3,4 };  // масив соединений


void line_color(int l_c) {
    if (l_c == 0) {
        glColor3d(0,0,0.2);
    } else if (l_c == 1) {
        glColor3d(1,1,1);
    }else if (l_c == 2) {
        glColor3d(0.5,0,0);
    }else if (l_c == 3) {
        glColor3d(0.1,1,0.7);
    }else if (l_c == 4) {
        glColor3d(0.1,0,1);
    }
}

void line_style( int l_s) {
    glLineStipple(1, 0x00ff);
    if (l_s == 0) {
        glEnable(GL_LINE);
    } else {
        glEnable(GL_LINE_STIPPLE); // пунктирная линия
    }
}

//void line_width(int l_w) {
//    glLineWidth(l_w); // size line
//}


void vertex_color(int w_c) {

    if (w_c == 0) {
        glColor3d(0,0,0.2);
    } else if (w_c == 1) {
        glColor3d(1,1,1);
    }else if (w_c == 2) {
        glColor3d(0.5,0,0);
    }else if (w_c == 3) {
        glColor3d(0.1,1,0.7);
    }else if (w_c == 4) {
        glColor3d(0.1,0,1);
    }

}

void veretex_stile(int v_s) {
    if (v_s == 0) {
        glEnable(GL_NONE);
    } else if (v_s == 1) {
        glEnable(GL_POINT_SMOOTH);  // круглые точки
    } else {
        glEnable(GL_POINT);  // круглые точки
    }
}

void Scene::paintGL() {
    glClearColor(back_red / 255.0f, back_green / 255.0f, back_blue / 255.0f, back_alpha / 255.0f);  //  colo bakcground
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  // очищаем буфера
    glVertexPointer(3, GL_FLOAT, 0, &arr);  // берет каждые три точки под вершины из масива
    glEnableClientState(GL_VERTEX_ARRAY);  //  разрешаем рисовать из масива вершин
    glDrawElements(GL_LINES, 12 , GL_UNSIGNED_INT, &mass); // рисуем не зависмыми линиями


        ::line_color(l_c);
        ::line_style(l_s);
        glLineWidth(l_w); // size line




//        ::vertex_color(v_c);
        if (v_s != 0) glPointSize(v_w);  // size point
        ::veretex_stile(v_s);
        glDrawArrays(GL_POINTS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);




    glRotatef(xRot, 1, 0, 0);// для движения мышью
    glRotatef(yRot, 0, 1, 0);
    update();
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



#include "scene.h"



Scene::Scene(QWidget *parent):
    QOpenGLWidget (parent)
{
}
//double *arr = ;
//unsigned int *mass = ;

void Scene::initializeGL() {

    glScalef(rotX, rotY, rotY);  // для маштаба
    glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
    glLoadIdentity(); // закреплаяем изменения
    glEnable(GL_DEPTH_TEST); // буфер глубины
}

double arr[] = {0,0,0, -1,0,-1, 0,1,0, 1,0,0}; // масив вершин
int mass[] = {1,0, 1,2, 1,3, 2,3, 2,4, 3,4 };  // масив соединений

void line_color(int l_c) {
    if (l_c == 0) {
        glColor3f(1,1,1);
    } else if (l_c == 1) {
        glColor3f(0,0,0.2);
    } else if (l_c == 2) {
        glColor3f(0.5,0,0);
    } else if (l_c == 3) {
        glColor3f(0.1,1,0.7);
    } else if (l_c == 4) {
        glColor3f(0.1,0,1);
    }
}

void line_style( int l_s) {
    if (l_s == 1) {
        glDisable(GL_LINE_STIPPLE);
        glEnable(GL_LINE);
    } else if (l_s == 0) {
        glLineStipple(1, 0x00ff);
        glEnable(GL_LINE_STIPPLE); // пунктирная линия
    }
}

void vertex_color(int w_c) {
    if (w_c == 0) {
        glColor3d(1,1,1);
    } else if (w_c == 1) {
        glColor3d(0,0,0.2);
    }else if (w_c == 2) {
        glColor3d(0.5,0,0);
    }else if (w_c == 3) {
        glColor3d(0.1,1,0.7);
    }else if (w_c == 4) {
        glColor3d(0.1,0,1);
    }
}

void veretex_stile(int v_s) {
    if (v_s == 1) {
        glEnable(GL_POINT_SMOOTH);  // круглые точки
    } else if (v_s == 2){
        glDisable(GL_POINT_SMOOTH);
        glEnable(GL_POINT);  // точки
    }
}

void Scene::paintGL() {

//    qcount_vert = 4;
//    qcount_facets = 12;
    glClearColor(back_red / 255.0f, back_green / 255.0f, back_blue / 255.0f, back_alpha / 255.0f);  //  colo bakcground
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  // очищаем буфера
    glVertexPointer(3, GL_DOUBLE, 0, &qvertexes);  // берет каждые три точки под вершины из масива
    glEnableClientState(GL_VERTEX_ARRAY);  //  разрешаем рисовать из масива вершин
    glDrawElements(GL_LINES, qcount_facets, GL_UNSIGNED_INT, &qfacets); // рисуем не зависмыми линиями
    glEnableClientState(GL_VERTEX_ARRAY);  //  разрешаем рисовать из масива вершин
    glBegin(GL_LINE);
        ::line_color(l_c);
        ::line_style(l_s);
        glLineWidth(l_w); // size line
//        glDisable(GL_LINE_STIPPLE); // сброс настроек точек
    glEnd();

    glBegin(GL_POINT);
        ::vertex_color(v_c);
        if (v_s != 0) {
            glPointSize(v_w);  // size point
            glDrawArrays(GL_POINTS, 0, qcount_vert);
        }
        ::veretex_stile(v_s);
        glDisableClientState(GL_VERTEX_ARRAY);
    glEnd();

//    glLoadIdentity(); // восанавливаем систему координат, загружаем единичную матрицу
//    glTranslatef(moveX, moveY, moveZ);  // для семещения по осям

    glRotatef(xRot, 1, 0, 0);// для движения мышью
    glRotatef(yRot, 0, 1, 0);
    glRotatef(zRot, 0, 0, 1);
    update();
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
    xRot = 0.006/M_PI*(mo->pos().y() - mPos.y());
    yRot = 0.006/M_PI*(mo->pos().x() - mPos.x());
    update(); //обовление кординат
}



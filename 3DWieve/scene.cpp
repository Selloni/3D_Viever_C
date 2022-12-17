#include "scene.h"
//#include <iostream>


Scene::Scene(QWidget *parent):
    QOpenGLWidget (parent)

{
     settings = new QSettings (QDir::homePath() + "/save_config/settings.conf", QSettings::IniFormat);
}

data_t obj = {'\0'};
double arr[] = {0,0,0, -1,0,-1, 0,1,0, 1,0,0}; // масив вершин
unsigned int mass[] = {1,0, 1,2, 1,3, 2,3, 2,4, 3,4 };  // масив соединений

void Scene::free_mem() {
    if (obj.facets != NULL && obj.vertexes != NULL) {
        free(obj.facets);
        free(obj.vertexes);
        obj.facets = 0;
        obj.vertexes = 0;
        obj.count_facets = 0;
        obj.count_vert = 0;
        qcount_facets = 0;
        qcount_vert = 0;
        qvertexes = 0;
        qfacets = 0;
    }
}

void Scene::read_file(char *path_file) {
    if (obj.facets != NULL && obj.vertexes != NULL) {
        free(obj.facets);
        free(obj.vertexes);
        obj.facets = 0;
        obj.vertexes = 0;
        obj.count_facets = 0;
        obj.count_vert = 0;
        qcount_facets = 0;
        qcount_vert = 0;
        qvertexes = 0;
        qfacets = 0;
    }
    int err_flag = 1;
//    int len = strlen(path_file);
//    for (int i = 0; len > 1 ; --len) {
//        if (path_file[len] != '/') {
//            str[i] = path_file[len];
//            i++;
//        } else {
//            break;
//        }
//    }
    err_flag = s21_count_v_f(path_file, &obj);
    if (err_flag) {
        QMessageBox msgBox;
        msgBox.setText("The file was not considered");
        msgBox.exec();
    } else {
        s21_read(path_file, &obj);
        qcount_facets = obj.count_facets;
        qcount_vert = obj.count_vert;
        qvertexes = obj.vertexes;
        qfacets = obj.facets;
    }
}

void Scene::initializeGL() {
    glEnable(GL_DEPTH_TEST); // буфер глубины
}

void Scene::resizeGL( int w, int h) {
    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );
}

void Scene::paintGL() {
    projection(proj);
//        obj.count_vert = 4;
//        obj.count_facets = 12;
    glClearColor(back_red / 255.0f, back_green / 255.0f, back_blue / 255.0f, back_alpha / 255.0f);  //  colo bakcground
    if (obj.count_facets > 3){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0, 0, -3);
        glRotatef(xRot, 1, 0, 0);// для движения мышью
        glRotatef(yRot, 0, 1, 0);
        glRotatef(zRot, 0, 0, 1);
        draw();
//        update();
//        saveSetting();
    }
}
void Scene::draw() {
    if (obj.count_facets > 3) {
        glVertexPointer(3, GL_DOUBLE, 0, qvertexes);
        glEnableClientState(GL_VERTEX_ARRAY);
        veretex_stile(v_s);
        vertex_color(v_c);
        if (v_s != 0) {
            glPointSize(v_w);  // size point
            glDrawArrays(GL_POINTS, 0, obj.count_vert);
        }
        line_color(l_c);
        line_style(l_s);
        glDrawElements(GL_LINES, (qcount_facets * 2), GL_UNSIGNED_INT, qfacets);
        glLineWidth(l_w); // size line
        glDisableClientState(GL_VERTEX_ARRAY);
    }
}

void Scene::line_color(int l_c) {
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

void Scene::line_style( int l_s) {
    if (l_s == 1) {
        glDisable(GL_LINE_STIPPLE);
        glEnable(GL_LINE);
    } else if (l_s == 0) {
        glLineStipple(1, 0x00ff);
        glEnable(GL_LINE_STIPPLE); // пунктирная линия
    }
}

void Scene::vertex_color(int w_c) {
    if (w_c == 0) {
        glColor3f(1,1,1);
    } else if (w_c == 1) {
        glColor3f(0,0,0.2);
    }else if (w_c == 2) {
        glColor3f(0.5,0,0);
    }else if (w_c == 3) {
        glColor3f(0.1,1,0.7);
    }else if (w_c == 4) {
        glColor3f(0.1,0,1);
    }
}

void Scene::veretex_stile(int v_s) {
    if (v_s == 1) {
        glEnable(GL_POINT_SMOOTH);  // круглые точки
    } else if (v_s == 2){
        glDisable(GL_POINT_SMOOTH);
        glEnable(GL_POINT);  // точки
    }
}

void Scene::projection(int proj) {
    // Создаем проекцию
    glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
    glLoadIdentity(); // загружаем матрицу
    if (proj) {
        // Establish clipping volume (left, right, bottom, top, near, far)
        glFrustum(-1, 1, -1, 1, 1, 99999);  //  перспективная проекция
    } else {
        glOrtho(-1, 1, -1, 1, -1, 99999);  // отоганальная
    }
}

void Scene::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

void Scene::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 0.6/M_PI*(mo->pos().y() - mPos.y());
    yRot = 0.6/M_PI*(mo->pos().x() - mPos.x());
    update(); //обовление кординат
}

void Scene::saveSetting()  {
    settings->setValue("l_c", l_c);
    settings->setValue("l_s", l_s);
    settings->setValue("l_w", l_w);
    settings->setValue("v_c", v_c);
    settings->setValue("v_s", v_s);
    settings->setValue("v_w", v_w);
    settings->setValue("l_c", l_c);
    settings->setValue("proj", proj);
    settings->setValue("back_red",back_red);
    settings->setValue("back_green",back_green);
    settings->setValue("back_blue",back_blue);
    settings->setValue("back_alpha",back_alpha);

}

void Scene::loadSetting()
{
    l_c = settings->value("l_c", 0).toInt();
    l_s = settings->value("l_s", 0).toInt();
    l_w = settings->value("l_w", 0).toInt();
    v_c = settings->value("v_c", 0).toInt();
    v_s = settings->value("v_s", 0).toInt();
    v_w = settings->value("v_w", 0).toInt();
    proj = settings->value("proj", proj).toInt();
    back_red=settings->value("back_red",back_red).toFloat();
    back_green=settings->value("back_green",back_green).toFloat();
    back_blue=settings->value("back_blue",back_blue).toFloat();
    back_alpha=settings->value("back_alpha",back_alpha).toFloat();
}

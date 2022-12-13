#include "scene.h"
#include <iostream>


Scene::Scene(QWidget *parent):
    QOpenGLWidget (parent)

{
//     setlocale(LC_ALL, "en_US.UTF-8");
//     settings = new QSettings (QDir::homePath() + "/save_config/settings.conf", QSettings::IniFormat);
//     loadSetting();
}

data_t obj;
double arr[] = {0,0,0, -1,0,-1, 0,1,0, 1,0,0}; // масив вершин
unsigned int mass[] = {1,0, 1,2, 1,3, 2,3, 2,4, 3,4 };  // масив соединений

void Scene::read_file(char *path_file) {

    unsigned int index_f = 0;
    unsigned int index_v = 0;

//    qpath_file = QString("/Users/grandpat/3D_Viever_C/obj/cub.obj");


    int err_flag = 1;
    printf("%s", path_file);

    err_flag = s21_count_v_f(path_file, &obj);
    s21_read(path_file, &obj, index_f, index_v);
//    if (err_flag) {
//        QMessageBox msgBox;
//        msgBox.setText("The file was not considered");
//        msgBox.exec();
//    }
     std::cout << "c_f|" << obj.count_facets << "|";
     std::cout << "c_v|" << obj.count_vert << "|";
//     std::cout << "|v_v|" << obj.vertexes[1] << "||";
//     std::cout << "|f_f|" << obj.facets[1] << "||";
     for (int i = 0; i < 24; i++) {
         std::cout << "v|" << obj.vertexes[i];
     }
      printf("\n");
     for (int i = 0; i < 72; i++) {
          std::cout << "f|" << obj.facets[i];
     }
//     update();
//    free(obj.vertexes);
//    free(obj.facets);
}


void Scene::initializeGL() {
//    setlocale(LC_ALL, "en_US.UTF-8");
    glScalef(0.4, 0.4, 0.4);  // для маштаба
    glEnable(GL_DEPTH_TEST); // буфер глубины
}

void Scene::resizeGL( int w, int h) {
    // Set Viewport to window dimensions

    glViewport( 0, 0, w, h );
    glFrustum(-1, 1, -1, 1, 1, 100);
//    projection(proj);
}

//void Scene::paintGL() {

////    obj.count_vert = 4;
////    obj.count_facets = 12;
////    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
////    glFrustum(-1, 1, -1, 1, 1, 1000000);

//    glClearColor(back_red / 255.0f, back_green / 255.0f, back_blue / 255.0f, back_alpha / 255.0f);  //  colo bakcground
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  // очищаем буфера
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();

//    glVertexPointer(3, GL_DOUBLE, 0, &obj.vertexes);  // берет каждые три точки под вершины из масива
////    glEnableClientState(GL_VERTEX_ARRAY);  //  разрешаем рисовать из масива вершин
//    glDrawElements(GL_LINES, obj.count_facets, GL_UNSIGNED_INT, &obj.facets); // рисуем не зависмыми линиями
//    //  разрешаем рисовать из масива вершин


//    line_color(l_c);
//    line_style(l_s);
//    glLineWidth(l_w); // size line


//    vertex_color(v_c);
//    if (v_s != 0) {
//        glPointSize(v_w);  // size point
//        glDrawArrays(GL_POINTS, 0, obj.count_vert);
//    }
//    veretex_stile(v_s);
//    glDisableClientState(GL_VERTEX_ARRAY);

////    glRotatef(xRot, 1, 0, 0);// для движения мышью
////    glRotatef(yRot, 0, 1, 0);
////    glRotatef(zRot, 0, 0, 1);

//    glDisableClientState(GL_VERTEX_ARRAY);
//    saveSetting();
////    update();

//}


void Scene::paintGL() {

    glClearColor(0, 1, 0,0);
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glVertexPointer(3, GL_DOUBLE, 0, obj.vertexes);
     glEnableClientState(GL_VERTEX_ARRAY);
     glPointSize(40);
     glDrawArrays(GL_POINTS, 0, obj.count_vert);
     glDisableClientState(GL_VERTEX_ARRAY);

     glDrawElements(GL_LINES, obj.count_facets, GL_UNSIGNED_INT, &obj.facets);


}

//void Scene::draw();
//    glVertexPointer(3, GL_DOUBLE, 0, &obj.vertexes);
//    glEnableClientState(GL_VERTEX_ARRAY);

//    glDrawArrays(GL_POINTS, 0, obj.count_vert);
//    glDisableClientState(GL_VERTEX_ARRAY);

//void Scene::saveSetting()
//{
//    settings->value("l_c", l_c);
//    settings->value("l_s", l_s);
//    settings->value("l_w", l_w);
//    settings->value("v_c", v_c);
//    settings->value("v_s", v_s);
//    settings->value("v_w", v_w);

//}

//void Scene::loadSetting()
//{
//    l_c = settings->value("l_c", l_c).toInt();
//    l_s = settings->value("l_s", l_s).toInt();
//    l_s = settings->value("l_w", l_w).toInt();
//    v_c = settings->value("v_c", v_c).toInt();
//    v_s = settings->value("v_s", v_s).toInt();
//    v_w = settings->value("v_w", v_w).toInt();
//}

void Scene::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();

}
void Scene::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 0.006/M_PI*(mo->pos().y() - mPos.y());
    yRot = 0.006/M_PI*(mo->pos().x() - mPos.x());
    update(); //обовление кординат
}


//void Scene::line_color(int l_c) {
//    if (l_c == 0) {
//        glColor3f(1,1,1);
//    } else if (l_c == 1) {
//        glColor3f(0,0,0.2);
//    } else if (l_c == 2) {
//        glColor3f(0.5,0,0);
//    } else if (l_c == 3) {
//        glColor3f(0.1,1,0.7);
//    } else if (l_c == 4) {
//        glColor3f(0.1,0,1);
//    }
//}

//void Scene::line_style( int l_s) {
//    if (l_s == 1) {
//        glDisable(GL_LINE_STIPPLE);
//        glEnable(GL_LINE);
//    } else if (l_s == 0) {
//        glLineStipple(1, 0x00ff);
//        glEnable(GL_LINE_STIPPLE); // пунктирная линия
//    }
//}

//void Scene::vertex_color(int w_c) {
//    if (w_c == 0) {
//        glColor3d(1,1,1);
//    } else if (w_c == 1) {
//        glColor3d(0,0,0.2);
//    }else if (w_c == 2) {
//        glColor3d(0.5,0,0);
//    }else if (w_c == 3) {
//        glColor3d(0.1,1,0.7);
//    }else if (w_c == 4) {
//        glColor3d(0.1,0,1);
//    }
//}

//void Scene::veretex_stile(int v_s) {
//    if (v_s == 1) {
//        glEnable(GL_POINT_SMOOTH);  // круглые точки
//    } else if (v_s == 2){
//        glDisable(GL_POINT_SMOOTH);
//        glEnable(GL_POINT);  // точки
//    }
//}

//void Scene::projection(int proj) {
//    // Создаем проекцию
//    glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
//    glLoadIdentity(); // загружаем матрицу
//    if (!proj){
//        // Establish clipping volume (left, right, bottom, top, near, far)
//        glFrustum(-10, 10, -10, 10, 1, 100);  //  перспективная проекция
//    }else{
//        glOrtho(-10, 10, -10, 10, -10, 100);  // отоганальная
//    }
//}



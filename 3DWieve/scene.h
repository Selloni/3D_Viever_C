#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

extern "C" {
    #include "../parsing/s21_viewer.h"
}

class Scene: public QOpenGLWidget
{
private slots:
    QSettings *settings;
    float xRot, yRot, zRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent*) override; // click mouse
    void mouseMoveEvent(QMouseEvent*) override; // move mouse

    void initializeGL() override;  // вызываеться после вызова конструктора
    void resizGL( int w, int h);  //  когда изменяеться размер окна
    void paintGL() override;  // нужно перерасовть окно

    void line_color(int l_c);
    void line_style(int l_s);
    void vertex_color(int w_c);
    void veretex_stile(int v_s);
    void loadSetting();

public:

    void saveSetting();

    Scene(QWidget *parent = 0);

    unsigned int qcount_vert = 0; // количество v
    unsigned int qcount_facets = 0; // количество f
    double *qvertexes = 0; // хранятся в, цифры
    unsigned int *qfacets = 0; // массив, в нем полигоны, 122331

    int l_c = 0;   // color
    int l_s = 1;  // style
    int l_w = 1; // width


    int yy = 0;
    int v_c = 0;
    int v_s = 0;
    int v_w = 1;
//    QColor color;
    QString file;
    double back_red;
    double back_green;
    double back_blue;
    double back_alpha;
//    unsigned int vertex;
    double rotX = 0.6;
    double rotY = 0.6;
    double rotZ = 0.6;

    double moveX = 0.0;
    double moveY = 0.0;
    double moveZ = 0.0;

    int proj = 0;

};

#endif // SCENE_H

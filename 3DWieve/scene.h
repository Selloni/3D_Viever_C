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

public:

    Scene(QWidget *parent = 0);


    unsigned int count_vert; // количество v
    unsigned int count_facets; // количество f
    double *vertexes; // хранятся в, цифры
    unsigned int *facets; // массив, в нем полигоны, эфки 122331

    int l_c = 0;
    int l_s = 1;
    int l_w = 1;

    int v_c = 0;
    int v_s = 0;
    int v_w = 1;
//    QColor color;
    double back_red;
    double back_green;
    double back_blue;
    double back_alpha;
//    unsigned int vertex;


};

#endif // SCENE_H

#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QMessageBox>

#define GL_SILENCE_DEPRECATION

extern "C" {
    #include "../parsing/s21_viewer.h"
}

//typedef struct DATA_QT {
//    unsigned int count_vert; // количество v
//    unsigned int count_facets; // количество f
//    double *vertexes; // хранятся в, цифры
//    unsigned int *facets; // массив, в нем полигоны, эфки 122331
//} data_qt;

class Scene: public QOpenGLWidget
{
private slots:

    QSettings *settings;
    float xRot, yRot, zRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent*) override; // click mouse
    void mouseMoveEvent(QMouseEvent*) override; // move mouse

    void initializeGL() override;  // вызываеться после вызова конструктора
    void resizeGL( int w, int h) override;  //  когда изменяеться размер окна
    void paintGL() override;  // нужно перерасовть окно

    void line_color(int l_c);
    void line_style(int l_s);
    void vertex_color(int w_c);
    void veretex_stile(int v_s);
//    void loadSetting();

    void projection(int proj);
    void draw();

public:
    void read_file(char *path_file);

//    int i=0 ;
//    void saveSetting();

    Scene(QWidget *parent = 0);

    unsigned int qcount_vert = 0; // количество v
    unsigned int qcount_facets = 0; // количество f
    double *qvertexes = 0; // хранятся в, цифры
    unsigned int *qfacets = 0; // массив, в нем полигоны, 122331

    int l_c = 0;   // color
    int l_s = 1;  // style
    int l_w = 1; // width

//    data_t *obj_scene;

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
    QString path_file;

};

#endif // SCENE_H

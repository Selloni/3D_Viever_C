#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QSettings>
#include <QMessageBox>

#include "scene.h"


extern "C" {
    #include "../parsing/s21_viewer.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_line_color_activated(int index);

    void on_line_solid_clicked();

    void on_line_dashed_clicked();

    void on_line_width_valueChanged(int value);

    void on_vertex_color_activated(int index);

    void on_vertex_circle_clicked();

    void on_vertex_no_clicked();

    void on_vertex_square_clicked();

    void on_vertex_wigth_valueChanged(int value);

    void on_background_clicked();

    void on_rotateX_valueChanged(double arg1);

    void on_rotetaY_valueChanged(double arg1);

    void on_rotateZ_valueChanged(double arg1);

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_actioninfo_triggered();

    void on_setting_scale_valueChanged(double arg1);

    void on_but_scale_clicked();

private:
    Ui::MainWindow *ui;
    Scene scene;
};
#endif // MAINWINDOW_H

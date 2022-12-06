#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

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

    void on_line_width_actionTriggered(int action);

private:
    Ui::MainWindow *ui;
    Scene scene;
};
#endif // MAINWINDOW_H

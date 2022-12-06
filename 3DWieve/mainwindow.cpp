#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize( this->size() );  //  не изменяемый размер окна
    ui->line_width->setRange(1, 40);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    data_t obj;
    QString qpath_file;
    qpath_file = QFileDialog::getOpenFileName(this, "выберите файл","All Files (*.obj)");
    QByteArray ba = qpath_file.toLocal8Bit(); // перевод из Qstring in *str
    char *path_file = ba.data();
    s21_count_v_f(path_file, &obj);
    s21_read(path_file, &obj);
}

void MainWindow::on_line_color_activated(int index)
{
    ui->sceneWidget->l_c = index;
}

void MainWindow::on_line_solid_clicked()
{
    ui->sceneWidget->l_s = 0;
    ui->sceneWidget->update();
}

void MainWindow::on_line_dashed_clicked()
{
    ui->sceneWidget->l_s = 1;
    ui->sceneWidget->update();
}

void MainWindow::on_line_width_valueChanged(int value)
{
    ui->sceneWidget->l_w = value;
    ui->line_progress->setValue(value);
}


void MainWindow::on_vertex_color_activated(int index)
{
    ui->sceneWidget->v_c = index;
}


void MainWindow::on_vertex_circle_clicked()
{
    ui->sceneWidget->v_s = 1;
    ui->sceneWidget->update();
}


void MainWindow::on_vertex_no_clicked()
{
    ui->sceneWidget->v_s = 0;
    ui->sceneWidget->update();
}


void MainWindow::on_vertex_square_clicked()
{
    ui->sceneWidget->v_s = 2;
    ui->sceneWidget->update();
}


void MainWindow::on_vertex_wigth_valueChanged(int value)
{
     ui->sceneWidget->v_w = value;
}

void MainWindow::on_background_clicked()
{
    QColor color = QColorDialog::getColor(Qt::blue).toRgb();
    ui->sceneWidget->back_red = color.red();
    ui->sceneWidget->back_green = color.green();
    ui->sceneWidget->back_blue = color.blue();
    ui->sceneWidget->back_alpha = color.alpha();
}


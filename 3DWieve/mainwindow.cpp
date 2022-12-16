#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>

/////// вопрос с цветом и с выводом фигруы и как что то сделать перед тем как запуститсья прогармма
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    ui->setupUi(this);
    this->setFixedSize( this->size() );  //  не изменяемый размер окна
    ui->line_width->setRange(1, 40);

}

MainWindow::~MainWindow()
{
    delete ui;
    ui->sceneWidget->free_mem();
}


QString qpath_file;
void MainWindow::on_pushButton_clicked()
{
    qpath_file = QFileDialog::getOpenFileName(0, "Open File .obj", "/Users/", "*.obj");
    QByteArray ba = qpath_file.toLocal8Bit(); // перевод из Qstring in *str
    char *path_file = ba.data();
    ui->sceneWidget->read_file(path_file);

}

void MainWindow::on_line_color_activated(int index)
{
    ui->sceneWidget->l_c = index;
    ui->sceneWidget->update();
}

void MainWindow::on_line_solid_clicked()
{
    ui->sceneWidget->l_s = 1;
    ui->sceneWidget->update();
}

void MainWindow::on_line_dashed_clicked()
{
    ui->sceneWidget->l_s = 0;
    ui->sceneWidget->update();
}

void MainWindow::on_line_width_valueChanged(int value)
{
    ui->sceneWidget->l_w = value;
    ui->line_progress->setValue(value);
    ui->sceneWidget->update();
}


void MainWindow::on_vertex_color_activated(int index)
{
    ui->sceneWidget->v_c = index;
    ui->sceneWidget->update();
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
     ui->sceneWidget->update();
}

void MainWindow::on_background_clicked()
{
    QColor color = QColorDialog::getColor(Qt::blue).toRgb();
    ui->sceneWidget->back_red = color.red();
    ui->sceneWidget->back_green = color.green();
    ui->sceneWidget->back_blue = color.blue();
    ui->sceneWidget->back_alpha = color.alpha();
//    ui->sceneWidget->update();
}

void MainWindow::on_rotateX_valueChanged(double arg1)
{
    s21_rotate(&ui->sceneWidget->qvertexes, 'x', arg1, ui->sceneWidget->qcount_vert);
    ui->sceneWidget->update();
}


void MainWindow::on_rotetaY_valueChanged(double arg1)
{
    s21_rotate(&ui->sceneWidget->qvertexes, 'y', arg1, ui->sceneWidget->qcount_vert);
    ui->sceneWidget->update();
}


void MainWindow::on_rotateZ_valueChanged(double arg1)
{
    s21_rotate(&ui->sceneWidget->qvertexes, 'z', arg1, ui->sceneWidget->qcount_vert);
    ui->sceneWidget->update();
}


void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    s21_moveX(&ui->sceneWidget->qvertexes, arg1, ui->sceneWidget->qcount_vert);
    ui->sceneWidget->update();
}


void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    s21_moveY(&ui->sceneWidget->qvertexes, arg1, ui->sceneWidget->qcount_vert);
    ui->sceneWidget->update();;
}


void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    s21_moveZ(&ui->sceneWidget->qvertexes, arg1, ui->sceneWidget->qcount_vert);
    ui->sceneWidget->update();
}

void MainWindow::on_actioninfo_triggered()
{
    QString a = QString::number(ui->sceneWidget->qcount_vert);
    QString b = QString::number(ui->sceneWidget->qcount_facets);
    QString info = "Name: " + qpath_file + '\n' + "Vertex: " + a + '\n' + "Facets: " + b;

    QMessageBox::information(this, tr("Info"), info);

}

double tmp = 1;

void MainWindow::on_setting_scale_valueChanged(double arg1)
{
    tmp = arg1;
}



void MainWindow::on_but_scale_clicked()
{
    s21_scale(&ui->sceneWidget->qvertexes, tmp, ui->sceneWidget->qcount_vert);
    ui->sceneWidget->update();
}


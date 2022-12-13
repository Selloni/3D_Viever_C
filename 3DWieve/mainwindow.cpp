#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
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
//    scene.saveSetting();

}

void MainWindow::on_pushButton_clicked()
{

    setlocale(LC_ALL, "en_US.UTF-8");

    unsigned int index_f = 0;
    unsigned int index_v = 0;
    data_t obj;
//    QString qpath_file = "/Users/grandpat/3D_Viever_C/obj/cub.obj";
    QString qpath_file = QFileDialog::getOpenFileName(this, "выберите файл","All Files (*.obj)");

    QByteArray ba = qpath_file.toLocal8Bit(); // перевод из Qstring in *str
    char *path_file = ba.data();
    int err_flag = 1;
    err_flag = s21_count_v_f(path_file, &obj);
    s21_read(path_file, &obj, index_f, index_v);

//        for (int i = 0; i < 72; i++) {
//            printf("%u ",obj.facets[i]);
//        }
//         printf("\n");
//        for (int i = 0; i < 24; i++) {
//             printf("%lf|  ",obj.vertexes[i]);
//        }
//    ui->sceneWidget->file = qpath_file;
    ui->sceneWidget->qcount_vert = obj.count_vert;
    ui->sceneWidget->qcount_facets = obj.count_facets;
    ui->sceneWidget->qvertexes = obj.vertexes;
    ui->sceneWidget->qfacets = obj.facets;

    std::cout<<ui->sceneWidget->qcount_facets;
//    for (int i = 0; i < 72; i++) {
//        printf("%u ",scene.qfacets[i]);
//    }
//     printf("\n");
//    for (int i = 0; i < 24; i++) {
//         printf("%lf|  ",scene.qvertexes[i]);
//    }
    free(obj.vertexes);
    free(obj.facets);
    ui->sceneWidget->update();
}

void MainWindow::on_line_color_activated(int index)
{
    ui->sceneWidget->l_c = index;
}

void MainWindow::on_line_solid_clicked()
{
    ui->sceneWidget->l_s = 1;
}

void MainWindow::on_line_dashed_clicked()
{
    ui->sceneWidget->l_s = 0;
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
}


void MainWindow::on_vertex_no_clicked()
{
    ui->sceneWidget->v_s = 0;
}


void MainWindow::on_vertex_square_clicked()
{
    ui->sceneWidget->v_s = 2;
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

void MainWindow::on_rotateX_valueChanged(double arg1)
{
    scene.rotX = arg1;
}


void MainWindow::on_rotetaY_valueChanged(double arg1)
{
    scene.rotY = arg1;
}


void MainWindow::on_rotateZ_valueChanged(double arg1)
{
    scene.rotZ = arg1;
}


void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    scene.moveX = arg1;
}


void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    scene.moveY = arg1;
}


void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    scene.moveZ = arg1;
}

void MainWindow::on_actioninfo_triggered()
{

}


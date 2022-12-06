#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize( this->size() );  //  не изменяемый размер окна
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
}

void MainWindow::on_line_dashed_clicked()
{
    ui->sceneWidget->l_s = 1;
}


void MainWindow::on_line_width_actionTriggered(int action)
{
    printf("%d", action);
}


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
    scene.line_color(1, 0, 1);
}




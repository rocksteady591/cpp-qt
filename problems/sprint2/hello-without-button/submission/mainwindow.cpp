#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        ui->lbl_result->setText("Привет из Qt, " + arg1 + "!");
    }else{
        ui->lbl_result->setText("Введите имя");
    }
}


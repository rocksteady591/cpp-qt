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

void MainWindow::on_pushButton_clicked()
{
    QString result;
    QString text = ui->lineEdit->text();
    for(int i = text.size() - 1; i >= 0; i--)    {
        result += text[i];
    }
    ui->lineEdit->setText(result);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UpdateSizeLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateSizeLabel() {
    // Доработайте этот метод.
    auto new_text = std::to_string(width()) + "x" + std::to_string(height());
    ui->lbl_size->setText(QString::fromStdString(new_text));
    ui->lbl_size->move(0, 0);
    ui->lbl_size->resize(this->width(), this->height());
}

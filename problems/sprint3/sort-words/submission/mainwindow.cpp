#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rb_asc_clicked()
{
    std::sort(line_.begin(), line_.end(), [](const QString& word1, const QString& word2){
        return QString::compare(word1, word2, Qt::CaseInsensitive) < 0;
    });
    QString result = line_.join(" ");
    ui->le_sorted->setText(result);
    start_ = false;
}

void MainWindow::on_rb_desc_clicked()
{
    std::sort(line_.begin(), line_.end(), [](const QString& word1, const QString& word2){
        return QString::compare(word1, word2, Qt::CaseInsensitive) > 0;
    });
    QString result = line_.join(" ");
    ui->le_sorted->setText(result);
    start_ = true;
}

void MainWindow::on_cb_case_clicked()
{
    std::sort(line_.begin(), line_.end(), [](const QString& word1, const QString& word2){
        return QString::compare(word1, word2) > 0;
    });
    QString result = line_.join(" ");
    ui->le_sorted->setText(result);
}

void MainWindow::on_le_unsorted_textChanged(const QString &arg1)
{
    line_ = arg1.split(" ");
    if(!start_){
        on_rb_asc_clicked();
    }else{
        on_rb_desc_clicked();
    }

}

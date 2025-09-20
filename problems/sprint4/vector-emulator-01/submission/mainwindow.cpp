#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ApplyModel();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ApplyModel() {
    ui->list_widget->clear();
    if(vector_model_.items.empty()){
        ui->pb_pop_back->setEnabled(false);
    }else{
        ui->pb_pop_back->setEnabled(true);
    }
    ui->txt_size->setText(QString::number(vector_model_.items.size()));
    QStringList res;
    res.clear();
    for(const auto& item : vector_model_.items){
        res.push_back(QString::fromStdString(item));
    }

    for(int i = 0; i < res.size(); i++){
        ui->list_widget->addItem(QString::number(i) + ": " + res[i]);
    }

}


void MainWindow::on_pb_days_of_week_clicked()
{
    static std::vector<std::string> days_of_week = {
        "Понедельник",
        "Вторник",
        "Среда",
        "Четверг",
        "Пятница",
        "Суббота",
        "Воскресенье"
    };

    vector_model_.items = days_of_week;
    ApplyModel();
}


void MainWindow::on_pb_months_clicked()
{
    static std::vector<std::string> months_of_year = {
        "Январь",
        "Февраль",
        "Март",
        "Апрель",
        "Май",
        "Июнь",
        "Июль",
        "Август",
        "Сентябрь",
        "Октябрь",
        "Ноябрь",
        "Декабрь"
    };

    vector_model_.items = months_of_year;
    ApplyModel();
}


void MainWindow::on_pb_pop_back_clicked()
{
    vector_model_.items.pop_back();
    ApplyModel();
}


void MainWindow::on_pb_clear_clicked()
{
    vector_model_.items.clear();
    ApplyModel();
}


void MainWindow::on_pb_push_back_2_clicked()
{
    std::string item = ui->txt_elem_content->text().toStdString();
    if(item.empty()){
        return;
    }
    vector_model_.items.push_back(item);
    ApplyModel();
}


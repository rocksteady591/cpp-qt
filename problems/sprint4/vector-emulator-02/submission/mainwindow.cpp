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
    ApplyIterator();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_list_widget_currentRowChanged(int currentRow){
    if (currentRow < 0 || currentRow >= static_cast<int>(vector_model_.items.size())) {
        vector_model_.iterator = vector_model_.items.end();
    } else {
        vector_model_.iterator = vector_model_.items.begin() + currentRow;
        ui->txt_elem_content->setText(QString::fromStdString(*vector_model_.iterator));
    }
    ApplyIterator();
}

void MainWindow::ApplyIterator(){
    bool has_items = !vector_model_.items.empty();
    bool is_begin = (vector_model_.iterator == vector_model_.items.begin());
    bool is_end = (vector_model_.iterator == vector_model_.items.end());

    ui->btn_dec->setEnabled(has_items && !is_begin);
    ui->pb_edit->setEnabled(has_items && !is_end);
    ui->pb_erase->setEnabled(has_items && !is_end);
    ui->pb_plus->setEnabled(has_items && !is_end);
    ui->pb_pop_back->setEnabled(has_items);

    if (has_items && !is_end) {
        ui->txt_elem_content->setText(QString::fromStdString(*vector_model_.iterator));
    } else {
        ui->txt_elem_content->clear();
    }

    ui->list_widget->blockSignals(true);
    if (is_end) {
        ui->list_widget->setCurrentRow(vector_model_.items.size());
    } else if (has_items) {
        int index = std::distance(vector_model_.items.begin(), vector_model_.iterator);
        ui->list_widget->setCurrentRow(index);
    } else {
        ui->list_widget->setCurrentRow(-1);
    }
    ui->list_widget->blockSignals(false);
}

void MainWindow::ApplyModel() {
    // Сохраняем индекс (безопасно) вместо копии итератора
    size_t preserve_index;
    if (vector_model_.items.empty()) {
        preserve_index = 0; // при пустом векторе единственный элемент списка - "end" с индексом 0
    } else if (vector_model_.iterator == vector_model_.items.end()) {
        preserve_index = vector_model_.items.size(); // указывает на фиктивный элемент end
    } else {
        preserve_index = static_cast<size_t>(std::distance(vector_model_.items.begin(), vector_model_.iterator));
    }

    ui->list_widget->blockSignals(true);
    ui->list_widget->clear();

    ui->txt_size->setText(QString::number(vector_model_.items.size()));

    for (size_t i = 0; i < vector_model_.items.size(); ++i) {
        ui->list_widget->addItem(QString::number(i) + ": " +
                                 QString::fromStdString(vector_model_.items[i]));
    }
    ui->list_widget->addItem("end");

    // Восстанавливаем итератор по индексу (с учётом возможного изменения размера)
    if (preserve_index >= vector_model_.items.size()) {
        vector_model_.iterator = vector_model_.items.end();
        ui->list_widget->setCurrentRow(static_cast<int>(vector_model_.items.size()));
    } else {
        vector_model_.iterator = vector_model_.items.begin() + static_cast<std::ptrdiff_t>(preserve_index);
        ui->list_widget->setCurrentRow(static_cast<int>(preserve_index));
    }

    ui->list_widget->blockSignals(false);

    ApplyIterator();
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
    vector_model_.iterator = vector_model_.items.begin();
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
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
}


void MainWindow::on_pb_pop_back_clicked()
{
    if (vector_model_.items.empty()) return;

    vector_model_.items.pop_back();
    if (vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.end();
    } else {
        vector_model_.iterator = vector_model_.items.begin();
    }
    ApplyModel();
}


void MainWindow::on_pb_clear_clicked()
{
    vector_model_.items.clear();
    vector_model_.iterator = vector_model_.items.end();
    ApplyModel();
}


void MainWindow::on_pb_push_back_2_clicked()
{
    std::string item = ui->txt_elem_content->text().toStdString();
    if(item.empty()){
        return;
    }
    vector_model_.items.push_back(item);
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
}

void MainWindow::on_pb_plus_clicked()
{
    if (vector_model_.iterator != vector_model_.items.end()) {
        ++vector_model_.iterator;
        ApplyIterator();
    }
}


void MainWindow::on_pb_begin_clicked()
{
    if (!vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.begin();
        ApplyIterator();
    }
}


void MainWindow::on_pb_end_clicked()
{
    vector_model_.iterator = vector_model_.items.end();
    ApplyIterator();
}


void MainWindow::on_pb_edit_clicked()
{
    if (vector_model_.iterator == vector_model_.items.end() || vector_model_.items.empty()) {
        return;
    }

    std::string new_text = ui->txt_elem_content->text().toStdString();
    if (new_text.empty()) {
        return;
    }

    *vector_model_.iterator = new_text;
    ApplyModel();
}


void MainWindow::on_pb_erase_clicked()
{
    if (vector_model_.iterator == vector_model_.items.end() || vector_model_.items.empty()) {
        return;
    }

    // Удаляем элемент, затем приводим итератор в ожидаемое состояние
    vector_model_.items.erase(vector_model_.iterator);

    if (vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.end();
    } else {
        // По условиям тестов — сбрасываем на begin()
        vector_model_.iterator = vector_model_.items.begin();
    }

    ApplyModel();
}



void MainWindow::on_pb_insert_clicked()
{
    std::string new_text = ui->txt_elem_content->text().toStdString();
    if (new_text.empty()) {
        return;
    }

    if (vector_model_.iterator == vector_model_.items.end()) {
        // вставка в конец
        vector_model_.items.push_back(new_text);
    } else {
        // вставка перед текущим итератором
        vector_model_.items.insert(vector_model_.iterator, new_text);
    }

    // Согласно тестам — после вставки итератор должен указывать на begin()
    if (vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.end();
    } else {
        vector_model_.iterator = vector_model_.items.begin();
    }

    ApplyModel();
}



void MainWindow::on_btn_dec_clicked()
{
    if (vector_model_.iterator != vector_model_.items.begin() && !vector_model_.items.empty()) {
        --vector_model_.iterator;
        ApplyIterator();
    }
}

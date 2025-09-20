#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

}
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pb_one_clicked()
{
    digit_callback_(1);
}


void MainWindow::on_pb_two_clicked()
{
    digit_callback_(2);
}


void MainWindow::on_pb_three_clicked()
{
    digit_callback_(3);
}


void MainWindow::on_pb_four_clicked()
{
    digit_callback_(4);
}


void MainWindow::on_pb_five_clicked()
{
    digit_callback_(5);
}


void MainWindow::on_pb_six_clicked()
{
    digit_callback_(6);
}


void MainWindow::on_pb_seven_clicked()
{
    digit_callback_(7);
}


void MainWindow::on_pb_eight_clicked()
{
    digit_callback_(8);
}


void MainWindow::on_pb_nine_clicked()
{
    digit_callback_(9);
}


void MainWindow::on_pb_zero_clicked()
{
    digit_callback_(0);
}


void MainWindow::on_tb_extra_clicked()
{
    control_key_callback_(ControlKey::EXTRA_KEY);
}


void MainWindow::on_pb_delete_clicked()
{
    control_key_callback_(ControlKey::BACKSPACE);
}


void MainWindow::on_pb_result_clicked()
{
    control_key_callback_(ControlKey::EQUALS);
}


void MainWindow::on_pb_add_clicked()
{
    operation_callback_(Operation::ADDITION);
}


void MainWindow::on_pb_substraction_clicked()
{
    operation_callback_(Operation::SUBTRACTION);
}


void MainWindow::on_pb_multiply_clicked()
{
    operation_callback_(Operation::MULTIPLICATION);
}


void MainWindow::on_pb_division_clicked()
{
    operation_callback_(Operation::DIVISION);
}


void MainWindow::on_pb_change_of_sign_clicked()
{
    control_key_callback_(ControlKey::PLUS_MINUS);
}


void MainWindow::on_pb_clear_clicked()
{
    control_key_callback_(ControlKey::CLEAR);
}


void MainWindow::on_pb_pow_clicked()
{
    operation_callback_(Operation::POWER);
}


void MainWindow::on_pb_save_number_clicked()
{
    control_key_callback_(ControlKey::MEM_SAVE);
}


void MainWindow::on_pb_memory_read_clicked()
{
    control_key_callback_(ControlKey::MEM_LOAD);
}

void MainWindow::on_pb_memory_clear_clicked()
{
    control_key_callback_(ControlKey::MEM_CLEAR);
}

void MainWindow::SetInputText(const std::string& text) {
    ui->l_result->setStyleSheet(""); // сброс цвета
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string& text) {
    ui->l_result->setStyleSheet("color: #ff0000;");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string& text){
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text){
    ui->l_memory->setText((QString::fromStdString(text)));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key) {
    if (key.has_value()) {
        ui->tb_extra->setText(QString::fromStdString(*key));
        ui->tb_extra->show();
    } else {
        ui->tb_extra->hide();
    }
}

void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb){
    digit_callback_ = std::move(cb);
}

void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb){
    operation_callback_ = std::move(cb);
}

void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb){
    control_key_callback_ = std::move(cb);
}

void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb){
    controller_type_callback_ = std::move(cb);
}

void MainWindow::on_cmb_controller_activated(int index)
{
    ControllerType cp = static_cast<ControllerType>(index);
    controller_type_callback_(cp);
}


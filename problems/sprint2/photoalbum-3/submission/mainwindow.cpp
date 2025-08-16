#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

// Функция подгоняет изображение под нужный размер окна.
[[nodiscard("Не игнорируйте результат функции")]] QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if ( w_ratio > h_ratio ) {
        return src.scaledToHeight(window_height);
    } else {
        return src.scaledToWidth(window_width);

    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetFolder(":/cats/images/");
    //SetPixmap(":/cats/images/cat1.jpg");
    FitImage();
    UpdateEnabled();
}

void MainWindow::SetFolder(const QString& d){
    current_folder_ = d;
    QString image = GetCurrentFile();
    SetPixmap(":/cats/images/" + image);
}

QString MainWindow::GetCurrentFile(){
    QDir dir(current_folder_);
    QStringList list = dir.entryList();
    return list[cur_file_index_];
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    Q_ASSERT(!active_pixmap.isNull());

    // Напишите этот метод.
    // 1. Вызовите ResizeImgToFit.
    auto img = ResizeImgToFit(active_pixmap, this->width(), this->height());
    // 2. Поместите изображение в lbl_img.
    lbl_new_.setPixmap(img);
    // 3. Измените размер lbl_img.
    lbl_new_.resize(img.width(), img.height());
    // 4. Переместите lbl_img, пользуясь формулами из условия.
    int lbl_x = (this->width() - lbl_new_.width()) / 2; // Координата x.
    int lbl_y = (this->height() - lbl_new_.height()) / 2; // Координата y.
    lbl_new_.move(lbl_x, lbl_y);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}

void MainWindow::UpdateEnabled(){
    int folder_size = QDir(current_folder_).entryList().size();
    ui->btn_left->setEnabled(cur_file_index_ > 0);
    ui->btn_right->setEnabled(cur_file_index_ < folder_size - 1);
}

void MainWindow::on_btn_right_clicked()
{
    cur_file_index_++;
    UpdateEnabled();
    GetCurrentFile();
    QString image = GetCurrentFile();
    SetPixmap(current_folder_ + image);
    FitImage();
}


void MainWindow::on_btn_left_clicked()
{
    cur_file_index_--;
    UpdateEnabled();
    QString image = GetCurrentFile();
    SetPixmap(current_folder_ + image);
    FitImage();
}


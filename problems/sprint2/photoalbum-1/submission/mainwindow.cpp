#include "mainwindow.h"
#include "ui_mainwindow.h"

// Функция подгоняет изображение под нужный размер окна.
[[nodiscard("Не игнорируйте результат функции")]] QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if ( w_ratio > h_ratio ) {
        return src.scaledToWidth(window_width);
    } else {
        return src.scaledToHeight(window_height);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetPixmap(":/cats/images/cat1.jpg");
    FitImage();
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
    ui->lbl_img->setPixmap(img);
    // 3. Измените размер lbl_img.
    ui->lbl_img->resize(img.width(), img.height());
    // 4. Переместите lbl_img, пользуясь формулами из условия.
    int lbl_x = (this->width() - ui->lbl_img->width()) / 2; // Координата x.
    int lbl_y = (this->height() - ui->lbl_img->height()) / 2; // Координата y.
    ui->lbl_img->move(lbl_x, lbl_y);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}

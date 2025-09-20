#include "winterwindow.h"
#include "ui_winterwindow.h"
#include <QColorDialog>
#include <QPaintEvent>

WinterWindow::WinterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WinterWindow)
{
    ui->setupUi(this);
}

WinterWindow::~WinterWindow()
{
    delete ui;
}

void WinterWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    prac::QPainter painter(this);
    painter.setPen(Qt::black);
    double size = double(ui->sld_size->value());

    SnowFlakeParams flake_params{
        .center = {width() / 2., height() / 2.},
        .color = color_,
        .size = size,
        .line_width = ui->sld_line->value() / 15.,
        .rotation = double(ui->sld_rotation->value())
    };

    // Создайте снежинку (объект класса SnowFlake) и нарисуйте её методом Draw.
    SnowFlake new_snow_flake{flake_params};
    new_snow_flake.Draw(painter);

    QRect rect(10, 10, width() - 20, height() - 20);

    QFont font("Verdana", 12);
    painter.setFont(font);
    painter.setPen(Qt::white);

    // Получите описание снежинки из метода GetDescription,
    // напечатайте этот текст в прямоугольнике rect.
    // Получите описание снежинки из метода GetDescription,
    // напечатайте этот текст в прямоугольнике rect.
    painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, new_snow_flake.GetDescription());

}

void WinterWindow::on_btn_color_clicked()
{
    QColorDialog dialog{color_};
    dialog.exec();
    color_ = dialog.selectedColor();
    update();
}

#include "mywindowwithimage.h"
#include "ui_mywindowwithimage.h"

#include <QFileInfo>
#include <QDir>

#include <QtGlobal>

// Специальная магия для получения пути изображения.
#define MACRO_TO_STR_INNER(x) #x
#define MACRO_TO_STR(x) MACRO_TO_STR_INNER(x)

MyWindowWithImage::MyWindowWithImage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindowWithImage)
{
    ui->setupUi(this);

    // Получим изображение из переменной, которую задали в .pro-файле.
    // Не делайте так в реальных программах.
    QString image_path = MACRO_TO_STR(ILOVEQT_IMAGE_FULL_PATH);
    SetPixmap(ui->lbl_pixmap, image_path);
    this->setFixedSize(ui->lbl_pixmap->width(), ui->lbl_pixmap->height());
}

MyWindowWithImage::~MyWindowWithImage()
{
    delete ui;
}

void MyWindowWithImage::SetPixmap(QLabel *label_pix, const QString path)
{
    // Тут нужно вызвать FitToImage.
    // Подумайте, в каком месте метода это лучше сделать.
    QPixmap pix(path);
    Q_ASSERT(!pix.isNull());

    label_pix->setPixmap( pix );
    FitToImage(label_pix);
    label_pix->show();
}

void MyWindowWithImage::FitToImage(QLabel* lbl){
    int width = lbl->width();
    int height = lbl->height();
    lbl->move(0, 0);
    lbl->setFixedSize(width, height);
    this->setFixedSize(width, height);
}

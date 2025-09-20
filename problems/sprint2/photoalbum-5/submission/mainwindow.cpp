#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <prac/QFileDialog>
#include <prac/QTimer>

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
    setWindowFlags(windowFlags().setFlag(Qt::WindowStaysOnTopHint, state_));
    SetFolder(current_folder_);
    FitImage();
    UpdateEnabled();

    ui->menuBar->hide();

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QMainWindow::customContextMenuRequested, this, &MainWindow::slotClickOpenMenu);
    connect(ui->action_choose_dir, &QAction::triggered, this, &MainWindow::slotClicOpenFile);
    connect(ui->action_use_resources, &QAction::triggered, this, &MainWindow::slotSetDefaultFolder);
    connect(ui->action_up_windows, &QAction::triggered, this, &MainWindow::slotSetUpToWindow);
    connect(ui->action_close_app, &QAction::triggered, this, &MainWindow::slotCloseApp);
    connect(ui->action_1sec, &QAction::triggered, this, &MainWindow::slot_Slider_OneSecond);
    connect(ui->action_5sec, &QAction::triggered, this, &MainWindow::slot_Slider_FiveSecond);
    connect(ui->action_10sec, &QAction::triggered, this, &MainWindow::slot_Slider_TenSecond);
    connect(ui->action_0sec, &QAction::triggered, this, &MainWindow::slot_Slider_Stop);
    connect(ui->btn_right, &QPushButton::clicked, this, &MainWindow::isUserClick);
    connect(&timer_, &prac::QTimer::timeout, this, &MainWindow::slotNextImage);
}

void MainWindow::SetFolder(const QString& d) {
    current_folder_ = d;
    cur_file_index_ = 0;
    UpdateEnabled();
    QString image = GetCurrentFile();
    if (!image.isEmpty()) {
        SetPixmap(image);
        FitImage();
    }
}

QString MainWindow::GetCurrentFile() {
    QDir dir(current_folder_);
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif";
    QStringList list = dir.entryList(filters, QDir::Files);
    if (list.isEmpty()) return QString();
    return dir.filePath(list[cur_file_index_]);  // полный путь
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    Q_ASSERT(!active_pixmap.isNull());

    auto img = ResizeImgToFit(active_pixmap, this->width(), this->height());
    lbl_new_.setPixmap(img);
    lbl_new_.resize(img.width(), img.height());
    int lbl_x = (this->width() - lbl_new_.width()) / 2;
    int lbl_y = (this->height() - lbl_new_.height()) / 2;
    lbl_new_.move(lbl_x, lbl_y);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}

void MainWindow::UpdateEnabled(){
    int folder_size = QDir(current_folder_).entryList(
                                               {"*.png", "*.jpg", "*.jpeg", "*.bmp", "*.gif"},
                                               QDir::Files
                                               ).size();
    if(folder_size == 0){
        lbl_new_.clear();
    }
    if(cur_file_index_ == folder_size){
        cur_file_index_ = 0;
    }else if(cur_file_index_ == -1){
        cur_file_index_ = folder_size - 1;
    }
}

void MainWindow::on_btn_right_clicked()
{
    if(userClick && isActive_){
        slot_Slider_Stop();
        ui->action_0sec->setChecked(true);
    }else{
        cur_file_index_++;
        UpdateEnabled();
        QString image = GetCurrentFile();
        SetPixmap(image);
        FitImage();
    }
}

void MainWindow::on_btn_left_clicked()
{
    if(isActive_){
        slot_Slider_Stop();
        ui->action_0sec->setChecked(true);
    }
    cur_file_index_--;
    UpdateEnabled();
    QString image = GetCurrentFile();
    SetPixmap(image);
    FitImage();
}

void MainWindow::slotClickOpenMenu(QPoint pos){
    ui->menu->popup(this->mapToGlobal(pos));
}

void MainWindow::slotClicOpenFile() {
    QString dir = prac::QFileDialog::getExistingDirectory(this,
                                                          tr("Открыть папку"),
                                                          QDir::currentPath(),
                                                          prac::QFileDialog::ShowDirsOnly | prac::QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        SetFolder(dir);
    }
}

void MainWindow::slotSetDefaultFolder(){
    SetFolder(":/cats/images/");
}

void MainWindow::slotSetUpToWindow(){
    state_ = !state_;
    setWindowFlags(windowFlags().setFlag(Qt::WindowStaysOnTopHint, state_));
    this->show();
}

void MainWindow::slotCloseApp(){
    this->close();
}

void MainWindow::slot_Slider_OneSecond()
{
    slot_Slider_Stop();
    isActive_ = true;
    timer_.start(1000);
    ui->action_1sec->setChecked(true);
    ui->action_0sec->setChecked(false);
}

void MainWindow::slot_Slider_FiveSecond(){
    slot_Slider_Stop();
    isActive_ = true;
    timer_.start(5000);
    ui->action_5sec->setChecked(true);
    ui->action_0sec->setChecked(false);
}

void MainWindow::slot_Slider_TenSecond(){
    slot_Slider_Stop();
    isActive_ = true;
    timer_.start(10000);
    ui->action_10sec->setChecked(true);
    ui->action_0sec->setChecked(false);
}

void MainWindow::slot_Slider_Stop(){
    timer_.stop();
    userClick = false;
    isActive_ = false;
    ui->action_1sec->setChecked(false);
    ui->action_5sec->setChecked(false);
    ui->action_10sec->setChecked(false);
    ui->action_0sec->setChecked(true);
}



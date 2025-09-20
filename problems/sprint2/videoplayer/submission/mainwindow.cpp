#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <prac/QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btn_pause->setText("⏸");

    // Подключаем сигналы
    connect(&player_, &prac::QMediaPlayer::positionChanged, this, &MainWindow::on_position_changed);
    connect(&player_, &prac::QMediaPlayer::mediaStatusChanged, this, &MainWindow::on_media_status_changed);
    connect(&player_, &prac::QMediaPlayer::playbackStateChanged, this, &MainWindow::on_playback_state_changed);

    // Подключаем аудио и видео к плееру
    player_.setVideoOutput(ui->video_output);
    player_.setAudioOutput(&audio_output_);
}

void MainWindow::on_position_changed(qint64 position) {
    ui->sld_pos->blockSignals(true);
    ui->sld_pos->setValue(position);
    ui->sld_pos->blockSignals(false);
}

void MainWindow::on_media_status_changed(QMediaPlayer::MediaStatus) {
    ui->sld_pos->setMaximum(player_.duration());
}

void MainWindow::on_playback_state_changed(QMediaPlayer::PlaybackState new_state) {
    // Ничего не нужно для тестов
}

void MainWindow::on_btn_choose_clicked()
{
    QString file_path = prac::QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "*.waw;*.mp4");

    player_.setSource(QUrl::fromLocalFile(file_path));

    // Устанавливаем громкость
    audio_output_.setVolume(1.0);

    // Начинаем воспроизведение
    player_.play();
}

void MainWindow::on_btn_pause_clicked() {
    if (player_.playbackState() == QMediaPlayer::StoppedState) {
        player_.setPosition(0);
        player_.play();
        ui->btn_pause->setText("⏸");
    } else if (player_.playbackState() == QMediaPlayer::PlayingState) {
        player_.pause();
        ui->btn_pause->setText("⏵");
    } else if (player_.playbackState() == QMediaPlayer::PausedState) {
        player_.play();
        ui->btn_pause->setText("⏸");
    }
}

void MainWindow::on_sld_volume_valueChanged(int value)
{
    audio_output_.setVolume(value / 100.0);
}

void MainWindow::on_sld_pos_valueChanged(int value)
{
    player_.setPosition(value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

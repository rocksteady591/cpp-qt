#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <prac/QFileDialog>
#include <QFileInfo>
#include <QUrl>
#include <prac/QDateTime>

// Форматирование времени
QString TimeToString(QTime time) {
    return QString("%1:%2:%3")
    .arg(time.hour(), 2, 10, QChar('0'))
        .arg(time.minute(), 2, 10, QChar('0'))
        .arg(time.second(), 2, 10, QChar('0'));
}

QString TimeToString(std::chrono::milliseconds ms) {
    if (ms.count() <= 0) return "Пора вставать";
    return TimeToString(QTime::fromMSecsSinceStartOfDay(ms.count() + 500));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player_.setAudioOutput(&audio_output_);
    audio_output_.setVolume(1.f);

    connect(&timer_, &prac::QTimer::timeout, this, &MainWindow::slot_update_time_now);
    connect(ui->action_load_file, &QAction::triggered, this, &MainWindow::slot_set_melody);
    connect(ui->action_close, &QAction::triggered, this, &MainWindow::slot_close_app);

    // Инициализация UI и таймера при запуске
    slot_update_time_now();

    ui->pb_start_stop->setText("Старт");
    ui->lbl_timeout->setText("Установите будильник");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_update_time_now() {
    // Используем текущее системное время, чтобы избежать расхождений с тестами
    QDateTime current_datetime = prac::QDateTime::currentDateTime();
    QTime time_now = current_datetime.time();

    ui->lbl_now->setText(TimeToString(time_now));

    // Перезапуск таймера на оставшиеся миллисекунды до следующей секунды
    int next_interval = 1000 - time_now.msec();
    if (next_interval <= 0) next_interval = 1000;
    timer_.start(next_interval);

    // Если будильник активен
    if (ui->pb_start_stop->text() == "Стоп" && alarm_moment_.isValid()) {
        qint64 millis_left = current_datetime.msecsTo(alarm_moment_);
        ui->lbl_timeout->setText(TimeToString(std::chrono::milliseconds(millis_left)));

        // Если время настало или прошло
        if (millis_left <= 0) {
            player_.play();
        }
    }
}

void MainWindow::slot_set_melody() {
    QString file_melody = prac::QFileDialog::getOpenFileName(
        this, QString("Открыть файл"), QDir::currentPath(), "*.waw;*.mp3");
    player_.setSource(QUrl::fromLocalFile(file_melody));
    QFileInfo info(file_melody);
    ui->lbl_melody->setText(info.fileName());
}

void MainWindow::slot_close_app() {
    this->close();
}

void MainWindow::on_pb_start_stop_clicked() {
    if (ui->pb_start_stop->text() == "Старт") {
        QDateTime now = prac::QDateTime::currentDateTime();
        QTime alarm_time(ui->sb_hour->value(), ui->sb_min->value(), ui->sb_sec->value());
        alarm_moment_ = QDateTime(now.date(), alarm_time);

        if (alarm_moment_ <= now) {
            alarm_moment_ = alarm_moment_.addDays(1);
        }

        ui->pb_start_stop->setText("Стоп");

        qint64 millis_left = now.msecsTo(alarm_moment_);
        ui->lbl_timeout->setText(TimeToString(std::chrono::milliseconds(millis_left)));
    } else {
        ui->pb_start_stop->setText("Старт");
        ui->lbl_timeout->setText("Установите будильник");
        player_.stop();
        alarm_moment_ = QDateTime{};
    }
}

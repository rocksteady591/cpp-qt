#pragma once

#include <QMainWindow>
#include <prac/QTimer>
#include <prac/QMediaPlayer>
#include <prac/QDateTime>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QDateTime GetAlarmMoment() const {
        return alarm_moment_;
    }

private slots:
    void slot_update_time_now();
    void slot_set_melody();
    void slot_close_app();
    void on_pb_start_stop_clicked();

private:
    Ui::MainWindow *ui;
    QDateTime alarm_moment_;
    prac::QTimer timer_{this};
    prac::QMediaPlayer player_{this};
    QAudioOutput audio_output_{this};
};

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class Calendar {
    kEastern,
    kTibetan,
    kZoroastrian
};

enum class Horoscope {
    kZodiac,
    kDruid
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ShowCalendar();
    void ShowHoroscope();
    QString FormattedCalendar(int year, QString& animal, QString& element);
    QString FormattedCalendar(int year, QString& animal);
    QString FormattedZodiac(int day, int month, QString& zodiac);
    QString FormattedDruid(int day, int month, QString& tree);

private slots:

    void on_le_year_textChanged(const QString &arg1);

    void on_rb_eastern_toggled(bool checked);

    void on_rb_tibetan_toggled(bool checked);

    void on_rb_zoroastrian_toggled(bool checked);

    void on_cb_is_date_toggled(bool checked);

    void on_rb_zodiac_toggled(bool checked);

    void on_rb_druid_toggled(bool checked);

    void on_sb_day_valueChanged(int arg1);

    void on_cb_month_activated(int index);

private:
    Ui::MainWindow *ui;
    Calendar calendar_ = Calendar::kEastern;
    Horoscope horoscope_ = Horoscope::kZodiac;
};
#endif // MAINWINDOW_H

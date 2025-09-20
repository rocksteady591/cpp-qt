#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include "magic_horoscope.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_year->setValidator(new QIntValidator(1, 9999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::FormattedCalendar(int year, QString& animal, QString& element){
    QString result = "%1 — это год %2. Стихия/цвет — %3";
    return result.arg(year).arg(animal).arg(element);
}

QString MainWindow::FormattedCalendar(int year, QString& animal){
    QString result = "%1 - это год %2.";
    return result.arg(year).arg(animal);
}

QString MainWindow::FormattedZodiac(int day, int month, QString& zodiac){
    QString result = "%1.%2 — ваш знак зодиака %3 по зодиакальному гороскопу";
    return result.arg(day, 2, 10, QChar('0')).arg(month, 2, 10, QChar('0')).arg(zodiac);
}

QString MainWindow::FormattedDruid(int day, int month, QString& tree){
    QString result = "%1.%2 — ваше тотемное дерево %3 по гороскопу друидов";
    return result.arg(day, 2, 10, QChar('0')).arg(month, 2, 10, QChar('0')).arg(tree);
}

void MainWindow::ShowCalendar(){
    if (!ui->le_year->hasAcceptableInput()){
        return;
    }
    int year = ui->le_year->text().toInt();
    QString animal;
    QString element;
    if(calendar_ == Calendar::kEastern){
        animal = GetAnimalForEasternCalendar(year);
        element = GetElementForEasternCalendar(year);
        ui->lbl_calendar->setText(FormattedCalendar(year, animal, element));
    }else if(calendar_ == Calendar::kTibetan){
        animal = GetAnimalForTibetanCalendar(year);
        ui->lbl_calendar->setText(FormattedCalendar(year, animal));
    }else{
        animal = GetAnimalForZoroastrianCalendar(year);
        ui->lbl_calendar->setText(FormattedCalendar(year, animal));
    }
}

void MainWindow::ShowHoroscope(){
    if(ui->le_year->text().isEmpty()){
        ui->lbl_horoscope->setText("Такой даты не существует");
        return;
    }
    QString zodiac;
    QString tree;
    int day = ui->sb_day->value();
    int month = ui->cb_month->currentIndex() + 1;
    int year = ui->le_year->text().toInt();
    if(day > DayMarker::DaysPerMonth(month, year)){
        ui->lbl_horoscope->setText("Такой даты не существует");
        return;
    }
    if(horoscope_ == Horoscope::kZodiac){
        zodiac = GetZodiac(day, month, year);
        ui->lbl_horoscope->setText(FormattedZodiac(day, month, zodiac));
    }else{
        tree = GetTree(day, month, year);
        ui->lbl_horoscope->setText(FormattedDruid(day, month, tree));
    }
}

void MainWindow::on_le_year_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->lbl_calendar->setText("Введите год");
    }else{
        ShowCalendar();
        ShowHoroscope();
    }

}


void MainWindow::on_rb_eastern_toggled(bool checked)
{
    if(checked){calendar_ = Calendar::kEastern;}
    ShowCalendar();
}


void MainWindow::on_rb_tibetan_toggled(bool checked)
{
    if(checked){calendar_ = Calendar::kTibetan;}
    ShowCalendar();
}


void MainWindow::on_rb_zoroastrian_toggled(bool checked)
{
    if(checked){calendar_ = Calendar::kZoroastrian;}
    ShowCalendar();
}


void MainWindow::on_cb_is_date_toggled(bool checked)
{
    ui->gb_horoscope->setEnabled(checked);
    ui->rb_zodiac->setEnabled(checked);
    ui->lbl_day->setEnabled(checked);
    ui->sb_day->setEnabled(checked);
    ui->lbl_month->setEnabled(checked);
    ui->cb_month->setEnabled(checked);
    if(checked){
        ShowHoroscope();
    }else{
        ui->lbl_horoscope->setText("Ввод даты отключён");
    }

}


void MainWindow::on_rb_zodiac_toggled(bool checked)
{
    if(checked){horoscope_ = Horoscope::kZodiac;}
    ShowHoroscope();
}


void MainWindow::on_rb_druid_toggled(bool checked)
{
    if(checked){horoscope_ = Horoscope::kDruid;}
    ShowHoroscope();
}


void MainWindow::on_sb_day_valueChanged(int arg1)
{
    ShowHoroscope();
}


void MainWindow::on_cb_month_activated(int index)
{
    ShowHoroscope();
}


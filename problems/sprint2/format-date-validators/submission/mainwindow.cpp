#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

int DaysPerMonth(int month, int year)
{
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29; // February in a leap year.
        } else {
            return 28; // February in a non-leap year.
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30; // April, June, September, November have 30 days.
    } else {
        return 31; // All other months have 31 days.
    }
}

int CalculateDaysFromStartYear(int day, int month, int year)
{
    if(month == 0) {
        return 0;
    }
    int num_days = 0;
    for(size_t num_month = 1; num_month < static_cast<size_t>(month); ++num_month) {
        num_days += DaysPerMonth(num_month, year);
    }
    num_days += day;
    return num_days;
}

QString MainWindow::GetFormatType1(int day, int month, int year)
{
    return QString::number(day) + "." + QString::number(month) + "." + QString::number(year);
}

QString MainWindow::GetFormatType2(int day, int month, int year)
{
    return QString::number(day) + "/" + QString::number(month) + "/" + QString::number(year);
}

QString MainWindow::GetFormatType3(int day, int month, int year)
{
    static const QString months[] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    return QString::number(day) + " " + months[month - 1] + " " + QString::number(year);
}

QString MainWindow::GetStrNumDays(int num_days, int year) {
    return "Это " + QString::number(num_days) + " день в " + QString::number(year);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_day->setValidator(new QIntValidator(1, 31, this));

    ui->le_month->setValidator(new QIntValidator(1, 12, this));

    ui->le_year->setValidator(new QIntValidator(1, 9999, this));

    SetError("Некорректная дата");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CheckValidity(QLineEdit* elem){
    if (elem->hasAcceptableInput()) {
        elem->setStyleSheet("border:1px solid transparent");
    } else {
        elem->setStyleSheet("border:1px solid red");
    }
}

void MainWindow::ShowFormattedDate()
{
    if(!ui->le_day->hasAcceptableInput() ||
        !ui->le_month->hasAcceptableInput() ||
        !ui->le_year->hasAcceptableInput() ) {
        SetError("Некорректная дата");

        return;
    }

    int day = ui->le_day->text().toInt();
    int month = ui->le_month->text().toInt();
    int year = ui->le_year->text().toInt();

    if (month <= 0 || day <= 0 || year <= 0) {
        SetError("Некорректная дата");
        return;
    }

    if(day > DaysPerMonth(month, year)){
        SetError("Некорректная дата");
        return;
    }
    int days_from_start_year = CalculateDaysFromStartYear(day, month, year);
    ui->lbl_format_type1->setText(GetFormatType1(day, month, year));
    ui->lbl_format_type2->setText(GetFormatType2(day, month, year));
    ui->lbl_format_type3->setText(GetFormatType3(day, month, year));
    ui->lbl_message->setText(GetStrNumDays(days_from_start_year, year));
}

void MainWindow::SetError(const QString& err_text)
{
    ui->lbl_format_type1->clear();
    ui->lbl_format_type2->clear();
    ui->lbl_format_type3->clear();
    ui->lbl_message->setText(err_text);
}

void MainWindow::on_le_day_textChanged(const QString&)
{
    CheckValidity(ui->le_day);
    ShowFormattedDate();
    UpdateLeDate();
}

void MainWindow::on_le_month_textChanged(const QString&)
{
    CheckValidity(ui->le_month);
    ShowFormattedDate();
    UpdateLeDate();
}

void MainWindow::on_le_year_textChanged(const QString&)
{
    CheckValidity(ui->le_year);
    ShowFormattedDate();
    UpdateLeDate();
}

void MainWindow::UpdateLeDate()
{
    QString day = ui->le_day->text();
    QString month = ui->le_month->text();
    QString year = ui->le_year->text();

    // если какое-то поле пустое — не стираем всё, просто выходим
    if (day.isEmpty() || month.isEmpty() || year.isEmpty()) {
        return;
    }

    // если что-то некорректное — тоже не трогаем le_date
    if (!ui->le_day->hasAcceptableInput() ||
        !ui->le_month->hasAcceptableInput() ||
        !ui->le_year->hasAcceptableInput()) {
        return;
    }

    QString dateStr = QString("%1.%2.%3").arg(day).arg(month).arg(year);

    QSignalBlocker blocker(ui->le_date);
    ui->le_date->setText(dateStr);
}



void MainWindow::on_le_date_textChanged(const QString &arg1)
{
    QSignalBlocker b1(ui->le_day);
    QSignalBlocker b2(ui->le_month);
    QSignalBlocker b3(ui->le_year);

    if (arg1.isEmpty()) {
        ui->le_day->clear();
        ui->le_month->clear();
        ui->le_year->clear();
        SetError("Некорректная дата");
    } else {
        QStringList dats = arg1.split(".");
        if (dats.size() == 3) {
            ui->le_day->setText(dats[0]);
            ui->le_month->setText(dats[1]);
            ui->le_year->setText(dats[2]);
        } else {
            //  не очищаем day/month/year, иначе ввод слетает
            SetError("Некорректная дата");
        }
    }

    ShowFormattedDate();
}



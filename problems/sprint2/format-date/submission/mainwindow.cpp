#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

void MainWindow::CheckValidity(QLineEdit* elem) {
    bool is_valid = elem->hasAcceptableInput();
    elem->setStyleSheet(is_valid ? "border:1px solid transparent" : "border:1px solid red");
}

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
    QString result = "%1.%2.%3";
    return result.arg(day, 2, 10, QChar('0')).arg(month, 2, 10, QChar('0')).arg(year);
}

QString MainWindow::GetFormatType2(int day, int month, int year)
{
    QString result = "%2/%1/%3";
    return result.arg(day, 2, 10, QChar('0')).arg(month, 2, 10, QChar('0')).arg(year);
}

QString MainWindow::GetFormatType3(int day, int month, int year)
{
    static const QString months[] = {
        "января", "февраля", "марта", "апреля", "мая", "июня",
        "июля", "августа", "сентября", "октября", "ноября", "декабря"
    };
    QString result = "%1 %2 %3 года";
    return result.arg(day, 2, 10, QChar('0')).arg(months[month - 1]).arg(year);
}

QString MainWindow::GetStrNumDays(int num_days, int year) {
    QString result = "Это %1 день в %2 году";
    return result.arg(num_days).arg(year);
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

    if(day > DaysPerMonth(month, year)){
        SetError("Такой даты не существует");

        return;
    }
    int num_days = CalculateDaysFromStartYear(day, month, year);
    ui->lbl_format_type1->setText(GetFormatType1(day, month, year));
    ui->lbl_format_type2->setText(GetFormatType2(day, month, year));
    ui->lbl_format_type3->setText(GetFormatType3(day, month, year));
    ui->lbl_message->setText((GetStrNumDays(num_days, year)));
}

void MainWindow::SetError(const QString& err_text)
{
    ui->lbl_format_type1->clear();
    ui->lbl_format_type2->clear();
    ui->lbl_format_type3->clear();
    ui->lbl_message->setText(err_text);
}

void MainWindow::on_le_date_textChanged(const QString&)
{

    QString string = ui->le_date->text();
    QSignalBlocker b1(ui->le_day);
    QSignalBlocker b2(ui->le_month);
    QSignalBlocker b3(ui->le_year);

    if (string.isEmpty()) {
        ui->le_day->clear();
        ui->le_month->clear();
        ui->le_year->clear();
        SetError("Некорректная дата");
    } else {
        QStringList dats = string.split(".");
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

    QString dateStr = day + "." + month + "." + year;




    QSignalBlocker blocker(ui->le_date);
    ui->le_date->setText(dateStr);
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

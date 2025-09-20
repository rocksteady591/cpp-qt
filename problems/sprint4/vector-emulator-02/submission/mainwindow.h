#pragma once

#include <QMainWindow>
#include <QStringListModel>
#include <QListWidgetItem>

#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_list_widget_currentRowChanged(int currentRow);

    void on_pb_days_of_week_clicked();

    void on_pb_months_clicked();

    void on_pb_pop_back_clicked();

    void on_pb_clear_clicked();

    void on_pb_push_back_2_clicked();

    void on_pb_plus_clicked();

    void on_pb_begin_clicked();

    void on_pb_end_clicked();

    void on_pb_edit_clicked();

    void on_pb_erase_clicked();

    void on_pb_insert_clicked();

    void on_btn_dec_clicked();

private:
    void ApplyModel();
    void ApplyIterator();

private:
    Model vector_model_;
    Ui::MainWindow *ui;
};

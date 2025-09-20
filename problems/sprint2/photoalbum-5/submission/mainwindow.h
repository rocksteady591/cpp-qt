#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <prac/QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetPixmap(const QString path) {
        active_pixmap = QPixmap(path);
    }

    void FitImage();
    void SetFolder(const QString& d);
    QString GetCurrentFile();

private slots:
    void on_btn_right_clicked();
    void on_btn_left_clicked();
    void slotClickOpenMenu(QPoint pos);
    void slotClicOpenFile();
    void slotSetDefaultFolder();
    void slotSetUpToWindow();
    void slotCloseApp();
    void slot_Slider_OneSecond();
    void slot_Slider_FiveSecond();
    void slot_Slider_TenSecond();
    void slot_Slider_Stop();
    void slotNextImage()
    {
        on_btn_right_clicked();
    }

    void isUserClick(){
        userClick = true;
    }

private:
    void resizeEvent(QResizeEvent *event) override;
    void UpdateEnabled();

private:
    Ui::MainWindow *ui;
    QPixmap active_pixmap;
    QLabel lbl_new_{this};
    QString current_folder_ = ":/cats/images/";
    int cur_file_index_ = 0;
    bool state_ = true;
    prac::QTimer timer_{this};
    bool isActive_ = false;
    bool userClick = false;
};
#endif // MAINWINDOW_H

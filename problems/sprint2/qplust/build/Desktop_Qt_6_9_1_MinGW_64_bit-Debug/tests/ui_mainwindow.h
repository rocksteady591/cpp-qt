/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *le_q;
    QLineEdit *le_t;
    QLabel *lbl_q;
    QLabel *lbl_t;
    QLabel *lbl_plus;
    QPushButton *btn_eq;
    QLineEdit *le_qt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(340, 240);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(340, 240));
        MainWindow->setMaximumSize(QSize(340, 240));
        MainWindow->setBaseSize(QSize(340, 240));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        le_q = new QLineEdit(centralwidget);
        le_q->setObjectName("le_q");
        le_q->setGeometry(QRect(70, 50, 81, 21));
        le_t = new QLineEdit(centralwidget);
        le_t->setObjectName("le_t");
        le_t->setGeometry(QRect(180, 50, 81, 21));
        lbl_q = new QLabel(centralwidget);
        lbl_q->setObjectName("lbl_q");
        lbl_q->setGeometry(QRect(80, 30, 58, 16));
        lbl_q->setAlignment(Qt::AlignCenter);
        lbl_t = new QLabel(centralwidget);
        lbl_t->setObjectName("lbl_t");
        lbl_t->setGeometry(QRect(190, 30, 58, 16));
        lbl_t->setAlignment(Qt::AlignCenter);
        lbl_plus = new QLabel(centralwidget);
        lbl_plus->setObjectName("lbl_plus");
        lbl_plus->setGeometry(QRect(150, 50, 31, 21));
        lbl_plus->setAlignment(Qt::AlignCenter);
        btn_eq = new QPushButton(centralwidget);
        btn_eq->setObjectName("btn_eq");
        btn_eq->setGeometry(QRect(119, 90, 91, 32));
        le_qt = new QLineEdit(centralwidget);
        le_qt->setObjectName("le_qt");
        le_qt->setGeometry(QRect(120, 140, 91, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 340, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Q Plus T", nullptr));
        lbl_q->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        lbl_t->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        lbl_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

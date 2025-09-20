/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *list_widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *txt_elem_content;
    QPushButton *pb_edit;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *pb_push_back_2;
    QPushButton *pb_pop_back;
    QPushButton *pb_clear;
    QPushButton *pb_erase;
    QPushButton *pb_insert;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QPushButton *btn_dec;
    QPushButton *pb_plus;
    QPushButton *pb_begin;
    QPushButton *pb_end;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_days_of_week;
    QPushButton *pb_months;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *txt_size;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        list_widget = new QListWidget(centralwidget);
        list_widget->setObjectName("list_widget");

        horizontalLayout->addWidget(list_widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        txt_elem_content = new QLineEdit(centralwidget);
        txt_elem_content->setObjectName("txt_elem_content");

        horizontalLayout_4->addWidget(txt_elem_content);

        pb_edit = new QPushButton(centralwidget);
        pb_edit->setObjectName("pb_edit");

        horizontalLayout_4->addWidget(pb_edit);


        verticalLayout->addLayout(horizontalLayout_4);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pb_push_back_2 = new QPushButton(centralwidget);
        pb_push_back_2->setObjectName("pb_push_back_2");

        gridLayout->addWidget(pb_push_back_2, 0, 1, 1, 1);

        pb_pop_back = new QPushButton(centralwidget);
        pb_pop_back->setObjectName("pb_pop_back");

        gridLayout->addWidget(pb_pop_back, 0, 0, 1, 1);

        pb_clear = new QPushButton(centralwidget);
        pb_clear->setObjectName("pb_clear");
        pb_clear->setEnabled(true);

        gridLayout->addWidget(pb_clear, 2, 0, 1, 1);

        pb_erase = new QPushButton(centralwidget);
        pb_erase->setObjectName("pb_erase");

        gridLayout->addWidget(pb_erase, 1, 0, 1, 1);

        pb_insert = new QPushButton(centralwidget);
        pb_insert->setObjectName("pb_insert");

        gridLayout->addWidget(pb_insert, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        btn_dec = new QPushButton(centralwidget);
        btn_dec->setObjectName("btn_dec");

        gridLayout_2->addWidget(btn_dec, 0, 0, 1, 1);

        pb_plus = new QPushButton(centralwidget);
        pb_plus->setObjectName("pb_plus");

        gridLayout_2->addWidget(pb_plus, 0, 1, 1, 1);

        pb_begin = new QPushButton(centralwidget);
        pb_begin->setObjectName("pb_begin");

        gridLayout_2->addWidget(pb_begin, 1, 0, 1, 1);

        pb_end = new QPushButton(centralwidget);
        pb_end->setObjectName("pb_end");

        gridLayout_2->addWidget(pb_end, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pb_days_of_week = new QPushButton(centralwidget);
        pb_days_of_week->setObjectName("pb_days_of_week");

        horizontalLayout_2->addWidget(pb_days_of_week);

        pb_months = new QPushButton(centralwidget);
        pb_months->setObjectName("pb_months");

        horizontalLayout_2->addWidget(pb_months);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        txt_size = new QLineEdit(centralwidget);
        txt_size->setObjectName("txt_size");

        horizontalLayout_3->addWidget(txt_size);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "std::vector demo", nullptr));
        pb_edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264\321\213", nullptr));
        pb_push_back_2->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        pb_pop_back->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        pb_erase->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        pb_insert->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_dec->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        pb_plus->setText(QCoreApplication::translate("MainWindow", "++", nullptr));
        pb_begin->setText(QCoreApplication::translate("MainWindow", "begin", nullptr));
        pb_end->setText(QCoreApplication::translate("MainWindow", "end", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\276\321\202\320\276\320\262\320\272\320\270", nullptr));
        pb_days_of_week->setText(QCoreApplication::translate("MainWindow", "= \320\264\320\275\320\270 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        pb_months->setText(QCoreApplication::translate("MainWindow", "= \320\274\320\265\321\201\321\217\321\206\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "size:()", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

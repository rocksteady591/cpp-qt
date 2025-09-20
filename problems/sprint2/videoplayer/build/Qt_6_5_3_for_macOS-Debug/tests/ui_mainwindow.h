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
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVideoWidget *video_output;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_pause;
    QSlider *sld_pos;
    QPushButton *btn_choose;
    QSlider *sld_volume;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        video_output = new QVideoWidget(centralwidget);
        video_output->setObjectName("video_output");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(video_output->sizePolicy().hasHeightForWidth());
        video_output->setSizePolicy(sizePolicy);
        video_output->setMinimumSize(QSize(320, 180));
        video_output->setAspectRatioMode(Qt::KeepAspectRatio);

        verticalLayout_3->addWidget(video_output);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btn_pause = new QPushButton(centralwidget);
        btn_pause->setObjectName("btn_pause");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::MediaPlaybackPause")));
        btn_pause->setIcon(icon);

        horizontalLayout_2->addWidget(btn_pause);

        sld_pos = new QSlider(centralwidget);
        sld_pos->setObjectName("sld_pos");
        sld_pos->setMaximum(100);
        sld_pos->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sld_pos);


        verticalLayout_2->addLayout(horizontalLayout_2);

        btn_choose = new QPushButton(centralwidget);
        btn_choose->setObjectName("btn_choose");

        verticalLayout_2->addWidget(btn_choose);


        horizontalLayout->addLayout(verticalLayout_2);

        sld_volume = new QSlider(centralwidget);
        sld_volume->setObjectName("sld_volume");
        sld_volume->setMaximum(100);
        sld_volume->setPageStep(1);
        sld_volume->setValue(50);
        sld_volume->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(sld_volume);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276\320\277\320\273\320\265\320\265\321\200", nullptr));
        btn_pause->setText(QString());
        btn_choose->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

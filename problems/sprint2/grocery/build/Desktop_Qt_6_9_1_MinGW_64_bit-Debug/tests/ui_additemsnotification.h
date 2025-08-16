/********************************************************************************
** Form generated from reading UI file 'additemsnotification.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMSNOTIFICATION_H
#define UI_ADDITEMSNOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddItemsNotification
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *AddItemsNotification)
    {
        if (AddItemsNotification->objectName().isEmpty())
            AddItemsNotification->setObjectName("AddItemsNotification");
        AddItemsNotification->resize(333, 348);
        verticalLayout = new QVBoxLayout(AddItemsNotification);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 233, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(AddItemsNotification);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        verticalSpacer_2 = new QSpacerItem(20, 144, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(AddItemsNotification);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton, 0, Qt::AlignmentFlag::AlignHCenter);


        retranslateUi(AddItemsNotification);
        QObject::connect(pushButton, &QPushButton::clicked, AddItemsNotification, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(AddItemsNotification);
    } // setupUi

    void retranslateUi(QDialog *AddItemsNotification)
    {
        AddItemsNotification->setWindowTitle(QCoreApplication::translate("AddItemsNotification", "\320\236\321\210\320\270\320\261\320\272\320\260", nullptr));
        label->setText(QCoreApplication::translate("AddItemsNotification", "\320\237\320\276\320\273\320\276\320\266\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200\321\213 \320\262 \320\272\320\276\321\200\320\267\320\270\320\275\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("AddItemsNotification", " \320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItemsNotification: public Ui_AddItemsNotification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMSNOTIFICATION_H

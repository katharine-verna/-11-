/********************************************************************************
** Form generated from reading UI file 'ninjafruit.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NINJAFRUIT_H
#define UI_NINJAFRUIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NinjaFruit
{
public:

    void setupUi(QWidget *NinjaFruit)
    {
        if (NinjaFruit->objectName().isEmpty())
            NinjaFruit->setObjectName(QLatin1String("NinjaFruit"));
        NinjaFruit->resize(800, 600);

        retranslateUi(NinjaFruit);

        QMetaObject::connectSlotsByName(NinjaFruit);
    } // setupUi

    void retranslateUi(QWidget *NinjaFruit)
    {
        NinjaFruit->setWindowTitle(QApplication::translate("NinjaFruit", "NinjaFruit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NinjaFruit: public Ui_NinjaFruit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NINJAFRUIT_H

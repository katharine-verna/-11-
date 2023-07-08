/********************************************************************************
** Form generated from reading UI file 'gamehelp.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHELP_H
#define UI_GAMEHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamehelp
{
public:
    QPushButton *helpexitButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *helptitle;
    QLabel *helpdetails;

    void setupUi(QWidget *gamehelp)
    {
        if (gamehelp->objectName().isEmpty())
            gamehelp->setObjectName(QLatin1String("gamehelp"));
        gamehelp->resize(400, 300);
        gamehelp->setAutoFillBackground(true);
        helpexitButton = new QPushButton(gamehelp);
        helpexitButton->setObjectName(QLatin1String("helpexitButton"));
        helpexitButton->setGeometry(QRect(150, 240, 91, 21));
        widget = new QWidget(gamehelp);
        widget->setObjectName(QLatin1String("widget"));
        widget->setGeometry(QRect(40, 50, 317, 181));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        helptitle = new QLabel(widget);
        helptitle->setObjectName(QLatin1String("helptitle"));

        verticalLayout->addWidget(helptitle);

        helpdetails = new QLabel(widget);
        helpdetails->setObjectName(QLatin1String("helpdetails"));

        verticalLayout->addWidget(helpdetails);


        retranslateUi(gamehelp);

        QMetaObject::connectSlotsByName(gamehelp);
    } // setupUi

    void retranslateUi(QWidget *gamehelp)
    {
        gamehelp->setWindowTitle(QApplication::translate("gamehelp", "Form", nullptr));
        helpexitButton->setText(QApplication::translate("gamehelp", "\351\200\200\345\207\272", nullptr));
        helptitle->setText(QApplication::translate("gamehelp", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:600;\">\345\270\256\345\212\251</span></p></body></html>", nullptr));
        helpdetails->setText(QApplication::translate("gamehelp", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\202\271\345\207\273\344\273\273\346\204\217\345\233\276\347\211\207\345\215\263\345\217\257\350\277\233\345\205\245\345\257\271\345\272\224\346\213\274\345\233\276\346\270\270\346\210\217</span></p><p align=\"center\"><span style=\" font-size:12pt;\">\345\234\250\346\270\270\346\210\217\347\225\214\351\235\242\357\274\214\350\277\236\347\273\255\347\202\271\345\207\273\345\235\227\346\213\274\345\233\276\345\217\257\344\272\244\346\215\242\345\205\266\344\275\215\347\275\256\343\200\202</span></p><p align=\"center\"><span style=\" font-size:12pt;\">\346\210\220\345\212\237\346\213\274\345\207\272\345\216\237\345\233\276\345\215\263\344\270\272\350\203\234\345\210\251\357\274\201<br/></span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamehelp: public Ui_gamehelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHELP_H

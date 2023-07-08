/********************************************************************************
** Form generated from reading UI file 'gameplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPLAYER_H
#define UI_GAMEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamePlayer
{
public:
    QPushButton *startButton;
    QPushButton *quitButton;
    QLabel *upperPicLabel;
    QLabel *titleLabel;
    QLabel *ruleLabel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *timeLabelTitle;
    QLabel *timeLabel;
    QLabel *stepTitleLabel;
    QLabel *stepNumLabel;

    void setupUi(QWidget *gamePlayer)
    {
        if (gamePlayer->objectName().isEmpty())
            gamePlayer->setObjectName(QLatin1String("gamePlayer"));
        gamePlayer->resize(916, 762);
        startButton = new QPushButton(gamePlayer);
        startButton->setObjectName(QLatin1String("startButton"));
        startButton->setGeometry(QRect(760, 570, 71, 31));
        quitButton = new QPushButton(gamePlayer);
        quitButton->setObjectName(QLatin1String("quitButton"));
        quitButton->setGeometry(QRect(760, 620, 71, 31));
        upperPicLabel = new QLabel(gamePlayer);
        upperPicLabel->setObjectName(QLatin1String("upperPicLabel"));
        upperPicLabel->setGeometry(QRect(20, 10, 61, 51));
        titleLabel = new QLabel(gamePlayer);
        titleLabel->setObjectName(QLatin1String("titleLabel"));
        titleLabel->setGeometry(QRect(110, 10, 171, 61));
        ruleLabel = new QLabel(gamePlayer);
        ruleLabel->setObjectName(QLatin1String("ruleLabel"));
        ruleLabel->setGeometry(QRect(730, 410, 171, 151));
        widget = new QWidget(gamePlayer);
        widget->setObjectName(QLatin1String("widget"));
        widget->setGeometry(QRect(720, 300, 124, 104));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QLatin1String("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        timeLabelTitle = new QLabel(widget);
        timeLabelTitle->setObjectName(QLatin1String("timeLabelTitle"));

        gridLayout->addWidget(timeLabelTitle, 0, 0, 1, 1);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName(QLatin1String("timeLabel"));
        QFont font;
        font.setFamily(QLatin1String("Arial"));
        font.setPointSize(18);
        timeLabel->setFont(font);

        gridLayout->addWidget(timeLabel, 0, 1, 1, 1);

        stepTitleLabel = new QLabel(widget);
        stepTitleLabel->setObjectName(QLatin1String("stepTitleLabel"));

        gridLayout->addWidget(stepTitleLabel, 1, 0, 1, 1);

        stepNumLabel = new QLabel(widget);
        stepNumLabel->setObjectName(QLatin1String("stepNumLabel"));
        stepNumLabel->setFont(font);

        gridLayout->addWidget(stepNumLabel, 1, 1, 1, 1);


        retranslateUi(gamePlayer);

        QMetaObject::connectSlotsByName(gamePlayer);
    } // setupUi

    void retranslateUi(QWidget *gamePlayer)
    {
        gamePlayer->setWindowTitle(QApplication::translate("gamePlayer", "Form", nullptr));
        startButton->setText(QApplication::translate("gamePlayer", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        quitButton->setText(QApplication::translate("gamePlayer", "\350\277\224\345\233\236\344\270\273\351\241\265", nullptr));
        upperPicLabel->setText(QApplication::translate("gamePlayer", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        titleLabel->setText(QApplication::translate("gamePlayer", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">\346\213\274\345\233\276\346\270\270\346\210\217\344\275\223\351\252\214</span></p></body></html>", nullptr));
        ruleLabel->setText(QApplication::translate("gamePlayer", "<html><head/><body><p><span style=\" font-weight:600;\">\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232</span></p><p><span style=\" font-weight:600;\">\351\274\240\346\240\207\345\267\246\345\207\273\344\270\244\345\274\240\344\270\215\345\220\214\347\232\204\345\233\276\347\211\207</span></p><p><span style=\" font-weight:600;\">\345\217\257\344\273\245\344\275\215\347\275\256\344\272\222\346\215\242\357\274\214</span></p><p><span style=\" font-weight:600;\">\346\213\274\345\245\275\344\271\213\345\220\216\345\260\261\350\203\275\347\234\213\345\210\260\345\205\250\350\262\214\345\225\246\357\274\201</span></p><p><span style=\" font-weight:600;\"><br/></span></p></body></html>", nullptr));
        timeLabelTitle->setText(QApplication::translate("gamePlayer", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\347\224\250\346\227\266\357\274\232</span></p></body></html>", nullptr));
        timeLabel->setText(QApplication::translate("gamePlayer", "<html><head/><body><p align=\"center\">0s</p></body></html>", nullptr));
        stepTitleLabel->setText(QApplication::translate("gamePlayer", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\347\264\257\350\256\241\346\255\245\346\225\260\357\274\232</span></p></body></html>", nullptr));
        stepNumLabel->setText(QApplication::translate("gamePlayer", "<html><head/><body><p align=\"center\">0\346\255\245</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamePlayer: public Ui_gamePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPLAYER_H

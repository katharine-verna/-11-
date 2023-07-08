/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *quitAction;
    QAction *helpAction;
    QAction *musicQuit;
    QAction *musicContinue;
    QWidget *centralWidget;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menu_K;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName(QLatin1String("MainScene"));
        MainScene->resize(400, 300);
        quitAction = new QAction(MainScene);
        quitAction->setObjectName(QLatin1String("quitAction"));
        helpAction = new QAction(MainScene);
        helpAction->setObjectName(QLatin1String("helpAction"));
        musicQuit = new QAction(MainScene);
        musicQuit->setObjectName(QLatin1String("musicQuit"));
        musicContinue = new QAction(MainScene);
        musicContinue->setObjectName(QLatin1String("musicContinue"));
        centralWidget = new QWidget(MainScene);
        centralWidget->setObjectName(QLatin1String("centralWidget"));
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QLatin1String("label_1"));
        label_1->setGeometry(QRect(20, 20, 100, 100));
        label_1->setMinimumSize(QSize(100, 100));
        label_1->setMaximumSize(QSize(100, 100));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QLatin1String("label_2"));
        label_2->setGeometry(QRect(140, 20, 100, 100));
        label_2->setMinimumSize(QSize(100, 100));
        label_2->setMaximumSize(QSize(100, 100));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QLatin1String("label_3"));
        label_3->setGeometry(QRect(20, 140, 100, 100));
        label_3->setMinimumSize(QSize(100, 100));
        label_3->setMaximumSize(QSize(100, 100));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QLatin1String("label_4"));
        label_4->setGeometry(QRect(140, 140, 100, 100));
        label_4->setMinimumSize(QSize(100, 100));
        label_4->setMaximumSize(QSize(100, 100));
        MainScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScene);
        menuBar->setObjectName(QLatin1String("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 17));
        menu_K = new QMenu(menuBar);
        menu_K->setObjectName(QLatin1String("menu_K"));
        MainScene->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainScene);
        statusBar->setObjectName(QLatin1String("statusBar"));
        MainScene->setStatusBar(statusBar);
        toolBar = new QToolBar(MainScene);
        toolBar->setObjectName(QLatin1String("toolBar"));
        MainScene->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_K->menuAction());
        menu_K->addAction(helpAction);
        menu_K->addAction(quitAction);
        menu_K->addAction(musicQuit);
        menu_K->addAction(musicContinue);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QApplication::translate("MainScene", "MainScene", nullptr));
        quitAction->setText(QApplication::translate("MainScene", "\351\200\200\345\207\272", nullptr));
        helpAction->setText(QApplication::translate("MainScene", "\345\270\256\345\212\251", nullptr));
        musicQuit->setText(QApplication::translate("MainScene", "\345\201\234\346\255\242\351\237\263\344\271\220", nullptr));
        musicContinue->setText(QApplication::translate("MainScene", "\347\273\247\347\273\255\346\222\255\346\224\276", nullptr));
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        menu_K->setTitle(QApplication::translate("MainScene", "\351\200\211\351\241\271(&S)", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainScene", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H

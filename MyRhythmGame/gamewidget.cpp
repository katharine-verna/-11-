#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "gamecontrol.h"
#include <QKeyEvent>
#include <QApplication>




GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

//    QApplication a;
//    QFile stylefile(GameDefine::PushButtonStyle);
//    stylefile.open(QFile::ReadOnly);
//    QString styleSheet = QString::fromLatin1(stylefile.readAll());
//    a.setStyleSheet(styleSheet);
//    stylefile.close();

    GameControl::Instance()->setParent(this);
    GameControl::Instance()->GameInit();

    this->setFixedSize(800,600);
    this->setWindowTitle("Rhythm Game");
    //退出按钮直接退出
//    QObject::connect(GameControl::Instance()->Quit,SIGNAL(clicked()),&w,SLOT(close()));
}

GameWidget::~GameWidget()
{
    delete ui;
}


void GameWidget::keyPressEvent(QKeyEvent *event)
{


    switch(event->key()){//添加对应按键组合
       case Qt::Key_S:
       case Qt::Key_D:
       case Qt::Key_J:
       case Qt::Key_K:
           mKeyList.append(event->key());
           break;
       }

}

void GameWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(mKeyList.contains(event->key())){//移除对应按键组合
            mKeyList.removeOne(event->key());
        }
}

//int Widget::MG_main(int argc, char *argv[])
//{



//    //QApplication a(argc, argv);
//    Widget w;
//    //PushButton样式读取
//    QFile stylefile(GameDefine::PushButtonStyle);
//    stylefile.open(QFile::ReadOnly);
//    QString styleSheet = QString::fromLatin1(stylefile.readAll());
//    a.setStyleSheet(styleSheet);
//    stylefile.close();

//    GameControl::Instance()->setParent(&w);
//    GameControl::Instance()->GameInit();

//    //退出按钮直接退出
//    QObject::connect(GameControl::Instance()->Quit,SIGNAL(clicked()),&w,SLOT(close()));

//    w.show();
//    return a.exec();
//}


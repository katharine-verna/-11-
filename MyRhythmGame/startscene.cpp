
#include "startscene.h"

StartScene::StartScene()
{
    mScene = new QGraphicsScene;//游戏开始场景
    mBackground = new QGraphicsPixmapItem;
    mTitle1 = new QGraphicsPixmapItem;
    mTitle2 = new QGraphicsPixmapItem;
    mTitle3 = new QPushButton;
    mXinhai1 = new QGraphicsPixmapItem;
    mXinhai2 = new QGraphicsPixmapItem;
}

void StartScene::LoadScene()
{
    //初始化主界面和开始场景
    mScene->setSceneRect(QRect(0,0,GameDefine::ScreenWidth,GameDefine::ScreenHeight));//场景大小
    mScene->setBackgroundBrush (QBrush(qRgb (0,0,0)));//场景颜色

    LoadPushButton();//PushButton初始化
    AddPicture();//添加元素图片
    LoadPos();//元素位置设定
    AddItem();//元素添加到场景
}

void StartScene::LoadPos()
{
    //初始化各个元素的位置
    mBackground->setPos(0,0);
    mTitle1->setPos(237,50);
    mTitle2->setPos(134,259);
    mTitle3->move(151,380);
    mXinhai1->setPos(10,500);
    mXinhai2->setPos(610,500);
    //mMusicSelect->move(151,300);
}

void StartScene::AddItem()
{
    //将各个元素添加到初始场景中
    mScene->addItem(mBackground);
    mScene->addItem(mTitle1);
    mScene->addItem(mTitle2);
    mScene->addWidget(mTitle3);
    mScene->addItem(mXinhai1);
    mScene->addItem(mXinhai2);
    //mScene->addItem(mMusicSelect);
}

void StartScene::AddPicture()
{
    //给背景和轨道设置图片
    mTitle1->setPixmap(QPixmap(":/img/Title1.png"));
    mTitle2->setPixmap(QPixmap(":/img/Title2.png"));
    mTitle3->setIcon(QIcon(":/img/Title4.png"));
    //mXinhai1->setPixmap(QPixmap(":/gif/xinhaichigua.gif"));
    mXinhai1->setScale(0.7);
    //mXinhai2->setPixmap(QPixmap(":/img/xongyongdexiao.jpg"));
    mXinhai2->setScale(0.18);
}

void StartScene::LoadPushButton()
{
    //PushButton创建
    mTitle3->resize(498,75);
    mTitle3->setIconSize(QSize(498,75));

    //mMusicSelect->resize(498,75);
    //mMusicSelect->setIconSize(498,75);

}

void StartScene::AddEffect()
{

}

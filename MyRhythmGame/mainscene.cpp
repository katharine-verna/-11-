
#include "mainscene.h"

MainScene::MainScene(MusicScore *MS,GameWidget *parent)
{
    mMS = MS;
    mScene = new QGraphicsScene;//游戏主要场景
    mBackground = new QGraphicsPixmapItem;
    mTrack1 = new QGraphicsPixmapItem;
    mTrack2 = new QGraphicsPixmapItem;
    mTrack3 = new QGraphicsPixmapItem;
    mTrack4 = new QGraphicsPixmapItem;
    mEmoji = new QGraphicsPixmapItem;
    mPoints = new QGraphicsTextItem;
    mLv = new QGraphicsTextItem;
    mComboNum = new QGraphicsTextItem;
    mCombo = new QGraphicsTextItem("Combo");
    mStatus = new QGraphicsTextItem;
    mBGOpacityEffect = new QGraphicsOpacityEffect(parent);//透明效果
    mBGBlurEffect = new QGraphicsBlurEffect(parent);//模糊效果
    stop = new QPushButton;
}

void MainScene::LoadScene()
{
    mScene->setSceneRect(QRect(0,0,GameDefine::ScreenWidth,GameDefine::ScreenHeight));//场景大小
    mScene->setBackgroundBrush (QBrush(qRgb (0,0,0)));//场景颜色
    LoadPushButton();//初始化按钮
    SettingItems();//初始化主场景元素
    AddPicture();//给主场景元素添加图片
    LoadPos();//设置主场景元素的位置
    AddItem();//将各元素添加到主场景
}

void MainScene::AddItem()
{
    mScene->addWidget(stop);//设置暂停按钮到场景
    mScene->addItem(mBackground);//设置背景图到场景
    mScene->addItem(mTrack1);//设置轨道到场景
    mScene->addItem(mTrack2);
    mScene->addItem(mTrack3);
    mScene->addItem(mTrack4);
    mScene->addItem(mPoints);//设置分数标签到场景
    mScene->addItem(mLv);//设置难度标签到场景
    mScene->addItem(mPName);//设置谱面名称标签到场景
    mScene->addItem(mCombo);//设置Combo标签到场景
    mScene->addItem(mComboNum);//设置连击数标签到场景
    mScene->addItem(mStatus);//设置状态显示到场景
    mScene->addItem(mEmoji);//设置状态表情到场景
}

void MainScene::AddPicture()
{
    //给背景和轨道设置图片
    mTrack1->setPixmap(QPixmap(":/img/TrackC75.png"));
    mTrack2->setPixmap(QPixmap(":/img/TrackC75.png"));
    mTrack3->setPixmap(QPixmap(":/img/TrackC75.png"));
    mTrack4->setPixmap(QPixmap(":/img/TrackC75.png"));

    mBackground->setPixmap(QPixmap(mMS->getBackGround()));
    AddEffect();//给背景图片添加效果
    mBackground->setGraphicsEffect(mBGBlurEffect);
    mBackground->setGraphicsEffect(mBGOpacityEffect);

    stop->setIcon(QIcon(":/img/StopButton50.png"));
}

void MainScene::AddEffect()
{
    mBGBlurEffect->setBlurRadius(30);
    mBGOpacityEffect->setOpacity(0.7);
}

void MainScene::SettingItems()
{
    //初始化分数
    mPoints->setPlainText(QString("%1").arg(mMS->getPoints(), 7, 10, QLatin1Char('0')));
    mPoints->setDefaultTextColor(QColor(255,255,255));//颜色
    mPoints->setFont(QFont("Courier New",18,100));//字体

    //初始化难度
    mLv->setPlainText(QString("Lv.%1").arg(mMS->getLevel()));
    mLv->setDefaultTextColor(QColor(255,255,255));//颜色
    mLv->setFont(QFont("Courier New",16,60));//字体

    //初始化谱面名称
    mPName = new QGraphicsTextItem;
    mPName->setPlainText(mMS->getName());
    mPName->setDefaultTextColor(QColor(255,255,255));//颜色
    mPName->setFont(QFont("Courier New",14,80));//字体

    //初始化combo标签
    mCombo->setDefaultTextColor(QColor(255,255,255));//颜色
    mCombo->setFont(QFont("Courier New",40,80));//字体

    //初始化连击数
    mComboNum->setPlainText(QString("%1").arg(mMS->getComboNum()));//初状态连击数
    mComboNum->setDefaultTextColor(QColor(255,255,255));//颜色
    mComboNum->setFont(QFont("Courier New",40,80));//字体

    //状态显示
    mStatus->setFont(QFont("Courier New",30,80));//字体
}

void MainScene::LoadPos()
{
    //初始化各个元素的位置
    mBackground->setPos(0,0);
    mTrack1->setPos(300,0);//各轨道位置
    mTrack2->setPos(380,0);
    mTrack3->setPos(460,0);
    mTrack4->setPos(540,0);
    mPoints->setPos(640,0);//分数位置
    mLv->setPos(700,565);//难度位置
    mPName->setPos(5,565);//谱面名称位置
    mCombo->setPos(60,150);
    qreal width1 = mCombo->boundingRect().width();//"Combo"宽度
    qreal width2 = mComboNum->boundingRect().width();//ComboNum宽度
    mComboNum->setPos(60+width1/2-width2/2,230);//初始化ComboNum位置(居中)
    stop->move(0,0);
    mEmoji->setPos(80,350);
}

void MainScene::LoadPushButton()
{
    stop->resize(50,50);
    stop->setIconSize(QSize(50,50));
}

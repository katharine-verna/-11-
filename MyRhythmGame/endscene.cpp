
#include "endscene.h"
#include "qaudiooutput.h"
#include <QMediaPlaylist>

 QGraphicsTextItem * EndScene::mScore=nullptr;
EndScene::EndScene(MusicScore *MS,GameWidget *parent)
{
    mMS = MS;
    mScene = new QGraphicsScene;//游戏主要场景

    mEndRect = new QGraphicsPixmapItem;
    mRank = new QGraphicsPixmapItem;

    mBackground = new QGraphicsPixmapItem;
    mMaxCombo = new QGraphicsTextItem("MaxCombo:");
    mAccuracy = new QGraphicsTextItem("Accuracy:");
    mPerfect = new QGraphicsTextItem("Perfect:");
    mGood = new QGraphicsTextItem("Good:");
    mBad = new QGraphicsTextItem("Bad:");
    mMiss = new QGraphicsTextItem("Miss:");
    mEndName = new QGraphicsTextItem;
    mScore = new QGraphicsTextItem;
    mMaxComboNum = new QGraphicsTextItem;
    mAccuracyNum = new QGraphicsTextItem;
    mPerfectNum = new QGraphicsTextItem;
    mGoodNum = new QGraphicsTextItem;
    mBadNum = new QGraphicsTextItem;
    mMissNum = new QGraphicsTextItem;

    BGMPlayer = new QMediaPlayer(parent);
    BGMPlayerList = new QMediaPlaylist(parent);

    mBGBlurEffect = new QGraphicsBlurEffect(parent);//模糊效果
    mBGOpacityEffect = new QGraphicsOpacityEffect(parent);//透明效果


    //End按钮我就直接加了,点击之后可以返回主线
    mEndButton = new QPushButton;
    mEndButton->setFixedSize(20,40);
    mEndButton->setText("End");
    connect(mEndButton,&QPushButton::clicked,this,[=]()
    {
        emit RhyGameEnd();
        return;
    });

}

void EndScene::LoadScene()
{
    mScene->setSceneRect(QRect(0,0,GameDefine::ScreenWidth,GameDefine::ScreenHeight));//场景大小
    mScene->setBackgroundBrush (QBrush(qRgb (0,0,0)));//场景颜色
    LoadBGM();//加载结算界面BGM
    AddPicture();//添加结算界面元素图片
    LoadPos();//设置结算界面元素位置
    AddItem();//将各元素添加到结算场景
}

void EndScene::LoadBGM()
{
    //初始化背景音乐
    //BGMPlayer->setSource(QUrl("qrc:/audio/EndBGM.mp3"));
    BGMPlayer->setVolume(GameDefine::EndBGMVolume);
    BGMPlayer->setPlaylist(BGMPlayerList);
    BGMPlayerList->addMedia(QUrl("qrc:/audio/EndBGM.mp3"));
    BGMPlayerList->setPlaybackMode(QMediaPlaylist::Loop);
    //设置循环播放
}

void EndScene::AddItem()
{
    mScene->addItem(mBackground);//设置背景图到场景
    mScene->addItem(mEndRect);
    mScene->addItem(mRank);
    mScene->addItem(mEndName);
    mScene->addItem(mScore);
    mScene->addItem(mMaxCombo);
    mScene->addItem(mMaxComboNum);
    mScene->addItem(mAccuracy);
    mScene->addItem(mAccuracyNum);
    mScene->addItem(mPerfect);
    mScene->addItem(mPerfectNum);
    mScene->addItem(mGood);
    mScene->addItem(mGoodNum);
    mScene->addItem(mBad);
    mScene->addItem(mBadNum);
    mScene->addItem(mMiss);
    mScene->addItem(mMissNum);
}

void EndScene::AddEffect()
{
    mBGBlurEffect->setBlurRadius(30);
    mBGOpacityEffect->setOpacity(0.7);
}

void EndScene::AddPicture()
{
    //初始化背景
    mBackground->setPixmap(QPixmap(mMS->getBackGround()));
    AddEffect();
    mBackground->setGraphicsEffect(mBGBlurEffect);
    mBackground->setGraphicsEffect(mBGOpacityEffect);

    //初始化矩形
    mEndRect->setPixmap(QPixmap(":/img/EndBackGround.png"));

    //初始化谱名
    mEndName->setPlainText(mMS->getName());
    mEndName->setDefaultTextColor(QColor(255,255,255));//颜色
    mEndName->setFont(QFont("Courier New",30,80));//字体

    //初始化分数
    mScore->setDefaultTextColor(QColor(255,255,255));//颜色
    mScore->setFont(QFont("Courier New",40,80));//字体

    //初始化最大连击数
    mMaxCombo->setDefaultTextColor(QColor(255,255,255));//颜色
    mMaxCombo->setFont(QFont("Dosis",15,80));//字体

    mMaxComboNum->setDefaultTextColor(QColor(255,255,255));//颜色
    mMaxComboNum->setFont(QFont("Courier New",30,80));//字体

    //初始化准度
    mAccuracy->setDefaultTextColor(QColor(255,255,255));//颜色
    mAccuracy->setFont(QFont("Dosis",15,80));//字体

    mAccuracyNum->setDefaultTextColor(QColor(255,255,255));//颜色
    mAccuracyNum->setFont(QFont("Courier New",30,80));//字体

    //初始化P
    mPerfect->setDefaultTextColor(QColor(255,255,255));//颜色
    mPerfect->setFont(QFont("Dosis",15,80));//字体

    mPerfectNum->setDefaultTextColor(QColor(255,255,255));//颜色
    mPerfectNum->setFont(QFont("Courier New",30,80));//字体

    //初始化G
    mGood->setDefaultTextColor(QColor(255,255,255));//颜色
    mGood->setFont(QFont("Dosis",15,80));//字体

    mGoodNum->setDefaultTextColor(QColor(255,255,255));//颜色
    mGoodNum->setFont(QFont("Courier New",30,80));//字体

    //初始化B
    mBad->setDefaultTextColor(QColor(255,255,255));//颜色
    mBad->setFont(QFont("Dosis",15,80));//字体

    mBadNum->setDefaultTextColor(QColor(255,255,255));//颜色
    mBadNum->setFont(QFont("Courier New",30,80));//字体

    //初始化M
    mMiss->setDefaultTextColor(QColor(255,255,255));//颜色
    mMiss->setFont(QFont("Dosis",15,80));//字体

    mMissNum->setDefaultTextColor(QColor(255,255,255));//颜色
    mMissNum->setFont(QFont("Courier New",30,80));//字体
}

void EndScene::LoadPushButton()
{

}

void EndScene::LoadPos()
{
    mEndRect->setPos(0,100);//矩形位置
    mRank->setPos(50,150);//Rank位置
    mEndName->setPos(5,100);//谱面名称位置
    mScore->setPos(400,170);//分数位置
    mMaxCombo->setPos(300,270);//最大连击数名称位置
    mMaxComboNum->setPos(360,300);//最大连击数位置
    mAccuracy->setPos(550,270);//准度名称位置
    mAccuracyNum->setPos(610,300);//准度位置
    mPerfect->setPos(5,400);//P名称位置
    mPerfectNum->setPos(50,425);//P位置
    mGood->setPos(200,400);//G名称位置
    mGoodNum->setPos(250,425);//G位置
    mBad->setPos(400,400);//B名称位置
    mBadNum->setPos(450,425);//B位置
    mMiss->setPos(600,400);//M名称位置
    mMissNum->setPos(650,425);//M位置
}

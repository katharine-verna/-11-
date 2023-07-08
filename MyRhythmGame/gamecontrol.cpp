
#include "gamecontrol.h"
#include <QMediaPlaylist>
GameControl* GameControl::instance = nullptr;

GameControl::GameControl()
{

}

GameControl *GameControl::Instance()
{
    if(instance == nullptr)
    {
        return instance = new GameControl();
    }
    return instance;
}
GameControl::~GameControl()
{
    if(instance != nullptr)
        delete instance;
    instance = nullptr;
}

void GameControl::setParent(GameWidget *Parent)
{
    this->parent = Parent;
}

void GameControl::GameInit()
{
    mGameView.setSceneRect(QRect(0,0,GameDefine::ScreenWidth,GameDefine::ScreenHeight));//游戏主界面大小
    LoadMS();//加载谱面文件
    CreateTimer();//创建计时器
    mStartScene.LoadScene();
    TimerConnect();//按钮、定时器功能连接
    mMainScene = new MainScene(mMS,parent);
    mMainScene->LoadScene();//初始化主场景
    mEndScene= new EndScene(mMS,parent);
    mEndScene->LoadScene();//初始化结算场景
    LoadStopScene();//初始化暂停场景

    //添加场景到视图
    mGameView.setScene(mStartScene.mScene);//先显示开始场景
    mGameView.setParent(parent);//设置视图的父类
    mGameView.show();
}

void GameControl::LoadMS()
{
    //打开谱面文件
    mMS = new MusicScore(parent);
    //qDebug() << "正在加载谱面文件" << endl;
    mMS->InitByFile(GameDefine::MSAddress);
}


void GameControl::CreateTimer()
{
    //创建计时器
    mMSTimer = new QTimer(parent);
    mDelay = new QTimer(parent);
    mDetectKeyTimer = new QTimer(parent);
    BGMDelay = new QTimer(parent);
    MSDelay = new QTimer(parent);
    MusicTimer = new QTimer(parent);
    stopDelay = new QTimer(parent);
}

void GameControl::TimerConnect()
{
    //按钮跳转事件和谱面计时器打开事件
    connect(mStartScene.mTitle3,&QToolButton::clicked,[this](){
        mGameView.setScene(mMainScene->mScene);
        mGameView.show();
        mDelay->start(GameDefine::MSDelay);//设置缓冲
        BGMDelay->start(GameDefine::Delay);//设置缓冲
    });

    //缓冲时间到后
    connect(mDelay,&QTimer::timeout,[this](){
        mMSTimer->start(GameDefine::MSTime);//打开谱面计时器
        mDetectKeyTimer->start(GameDefine::Border);//打开判定检测器
        MSDelay->start(mMS->getMusicLenth()+GameDefine::EndDelay);
        mMS->setparent(mMainScene->mScene);//添加谱面至场景
        mDelay->stop();
    });

    //BGM缓冲计时器
    connect(BGMDelay,&QTimer::timeout,[this](){
        mMS->BGMPlayer->play();
        MusicTimer->start(1);//开启播放时间计时器
        StopButtonConnect();
        BGMDelay->stop();
    });

    //谱面计时器
    connect(mMSTimer,&QTimer::timeout,[this](){
        mMS->notesMove(mMS->getSpeed());
    });

    //判定计时器
    connect(mDetectKeyTimer,&QTimer::timeout,this,&GameControl::judgeStatus);
    connect(mDetectKeyTimer,&QTimer::timeout,this,&GameControl::ShowStatus);//显示状态
    connect(mDetectKeyTimer,&QTimer::timeout,this,&GameControl::ShowComboNum);//显示连击数
    connect(mDetectKeyTimer,&QTimer::timeout,this,&GameControl::ShowPoints);//显示分数
    //边界判定
    connect(mDetectKeyTimer,&QTimer::timeout,[this](){
        mMS->JudgeBorder(mMainScene->mScene);
    });

    //播放时间计时器
    connect(MusicTimer,&QTimer::timeout,[this](){
        mMS->updateMusicTime();
    });

    //最终界面跳转计时器
    connect(MSDelay,&QTimer::timeout,[this](){
        mGameView.setScene(mEndScene->mScene);
        mMS->BGMPlayer->stop();
        ResetEnddata();
        mEndScene->BGMPlayer->play();  //播放结算音乐
        mGameView.show();
    });
}

void GameControl::judgeStatus()
{
    for(int keyCode : parent->mKeyList){
        switch(keyCode){
        case Qt::Key_S:
        {
            mMS->setStatus(mMS->JudgeStatus(1,mMainScene->mScene));//按键S->1轨道
            parent->mKeyList.removeOne(Qt::Key_S);
            break;
        }
        case Qt::Key_D:
        {
            mMS->setStatus(mMS->JudgeStatus(2,mMainScene->mScene));//按键D->2轨道
            parent->mKeyList.removeOne(Qt::Key_D);
            break;
        }
        case Qt::Key_J:
        {
            mMS->setStatus(mMS->JudgeStatus(3,mMainScene->mScene));//按键J->3轨道
            parent->mKeyList.removeOne(Qt::Key_J);
            break;
        }
        case Qt::Key_K:
        {
            mMS->setStatus(mMS->JudgeStatus(4,mMainScene->mScene)) ;//按键K->4轨道
            parent->mKeyList.removeOne(Qt::Key_K);
            break;
        }
        }
    }
}

void GameControl::ShowStatus()
{
    QString Status;
    switch(mMS->getStatus()){
    case 0:
    {
        Status = " ";
        mMainScene->mStatus->setPos(80,300);//状态显示位置
        mMainScene->mEmoji->setPixmap(QPixmap(" "));
        break;
    }
    case 1:
    {
        Status = "Perfect";
        mMainScene->mStatus->setDefaultTextColor(QColor(255,222,3));//颜色
        mMainScene->mStatus->setPos(80,300);//状态显示位置
        mMainScene->mEmoji->setPixmap(QPixmap(":/img/high.jpg"));
        mMainScene->mEmoji->setScale(0.15);
        break;
    }
    case 2:
    {
        Status = "Good";
        mMainScene->mStatus->setDefaultTextColor(QColor(160,255,255));//颜色
        mMainScene->mStatus->setPos(105,300);//状态显示位置
        mMainScene->mEmoji->setPixmap(QPixmap(":/img/good.jpg"));
        mMainScene->mEmoji->setScale(0.15);
        break;
    }
    case 3:
    {
        Status = "Bad";
        mMainScene->mStatus->setDefaultTextColor(QColor(255,255,255));//颜色
        mMainScene->mStatus->setPos(117,300);//状态显示位置
        mMainScene->mEmoji->setPixmap(QPixmap(":/img/yun.jpg"));
        mMainScene->mEmoji->setScale(0.2157);
        break;
    }
    case 4:
    {
        Status = "Miss";
        mMainScene->mStatus->setDefaultTextColor(QColor(255,255,255));//颜色
        mMainScene->mStatus->setPos(108,300);//状态显示位置
        mMainScene->mEmoji->setPixmap(QPixmap(":/img/angry.jpg"));
        mMainScene->mEmoji->setScale(0.15);
        break;
    }
    }
    mMainScene->mStatus->setPlainText(Status);
}

void GameControl::ShowComboNum()
{
    mMainScene->mComboNum->setPlainText(QString("%1").arg(mMS->getComboNum()));
}

void GameControl::ShowPoints()
{
    mMS->CalculatePoints();
    mMainScene->mPoints->setPlainText(QString("%1").arg(mMS->getPoints(), 7, 10, QLatin1Char('0')));
}

void GameControl::ResetEnddata()
{

    mMS->JudgeRank();
    mEndScene->mRank->setPixmap(QPixmap(mMS->getRank()));
    mEndScene->mScore->setPlainText(QString("%1").arg(mMS->getPoints(), 7, 10, QLatin1Char('0')));
    mEndScene->mMaxComboNum->setPlainText(QString("%1").arg(mMS->getMaxComboNum()));
    mEndScene->mAccuracyNum->setPlainText(QString("%1%").arg(mMS->getAcc()*100,0,'g',4));
    mEndScene->mPerfectNum->setPlainText(QString("%1").arg(mMS->getPerfectNum()));
    mEndScene->mGoodNum->setPlainText(QString("%1").arg(mMS->getGoodNum()));
    mEndScene->mBadNum->setPlainText(QString("%1").arg(mMS->getBadNum()));
    mEndScene-> mMissNum->setPlainText(QString("%1").arg(mMS->getMissNum()));


}

void GameControl::LoadStopScene()
{
    mEndScene->mScene->setSceneRect(QRect(0,0,GameDefine::ScreenWidth,GameDefine::ScreenHeight));//场景大小
    mEndScene->mScene->setBackgroundBrush (QBrush(qRgb (0,0,0)));//场景颜色

    LoadStopPushButton();//初始化按钮及大小
    LoadStopSettingItems();
    LoadStopPicture();//设置各元素图片
    LoadStopPos();//设置各元素位置
    LoadStopAddItem();//添加各元素至背景
    StopButtonConnect();//初始化按钮的连接

}

void GameControl::Stop()
{
    //关闭计时器
    mMSTimer->stop();//谱面移动计时器
    mDelay->stop();//开始前缓冲计时器
    mDetectKeyTimer->stop();//检测按键计时器(包括边界判定)
    MSDelay->stop();//结算界面计时器
    MusicTimer->stop();

    //暂停BGM
    mMS->BGMPlayer->pause();

    //弹出暂停界面
    mGameView.setScene(&mStopScene);
    mGameView.show();
}

void GameControl::GameContinue()
{
    //切屏
    mMainScene->mScene->addItem(&mStopRect);
    mMainScene->mScene->addItem(mStopCountdown);
    mGameView.setScene(mMainScene->mScene);
    mGameView.show();

    //开启延迟定时器
    stopDelay->start(3000);
    connect(stopDelay,&QTimer::timeout,[this](){
        stopDelay->stop();
        //恢复主场景
        mMainScene->mScene->removeItem(&mStopRect);
        mMainScene->mScene->removeItem(mStopCountdown);
        LoadStopAddItem();

        //打开计时器
        mMSTimer->start(GameDefine::MSTime);//打开谱面计时器
        mDetectKeyTimer->start(GameDefine::Border);//打开判定检测器
        MSDelay->start(mMS->getMusicLenth() - mMS->getMusicTime() + GameDefine::EndDelay);//结算界面计时器
        MusicTimer->start(1);

        //继续播放BGM
        mMS->BGMPlayer->play();
    });
}

void GameControl::LoadStopPicture()
{   LoadStopAddEffect();//给背景图片添加效果

    mStopRect.setPixmap(QPixmap(":/img/EndBackGround.png"));
    mStopRect.setGraphicsEffect(mStopRectBGOpacityEffect);

    mStopBackground.setPixmap(QPixmap(mMS->getBackGround()));
    mStopBackground.setGraphicsEffect(mSBGBlurEffect);
    mStopBackground.setGraphicsEffect(mSBGOpacityEffect);

    //给按钮添加图片
    Continue->setIcon(QIcon(":/img/ContinueButton.png"));
    Continue->setIconSize(QSize(75,75));
    Quit->setIcon(QIcon(":/img/QuitButton.png"));
    Quit->setIconSize(QSize(75,75));
}

void GameControl::LoadStopSettingItems()
{
    //标签初始化
    mStopCountdown = new QGraphicsTextItem("准备继续");
    mStopCountdown->setDefaultTextColor(QColor(255,255,255));//颜色
    mStopCountdown->setFont(QFont("幼圆",60,80));//字体

    mStopText = new QGraphicsTextItem("游戏暂停");
    mStopText->setDefaultTextColor(QColor(0,0,0));//颜色
    mStopText->setFont(QFont("幼圆",60,80));//字体

    mContinueText = new QGraphicsTextItem("继续游戏");
    mContinueText->setDefaultTextColor(QColor(0,0,0));//颜色
    mContinueText->setFont(QFont("幼圆",40,80));//字体

    mQuitText = new QGraphicsTextItem("退出游戏");
    mQuitText->setDefaultTextColor(QColor(0,0,0));//颜色
    mQuitText->setFont(QFont("幼圆",40,80));//字体


}

void GameControl::LoadStopPushButton()
{
    Continue = new QPushButton;
    Quit = new QPushButton;
    //设置按钮大小
    Continue->resize(75,75);
    Quit->resize(75,75);
}

void GameControl::LoadStopPos()
{
    mStopBackground.setPos(0,0);
    mStopRect.setPos(0,100);
    Continue->move(200,365);
    Quit->move(500,365);
    mStopText->setPos(225,115);
    mContinueText->setPos(125,275);
    mQuitText->setPos(440,275);
    mStopCountdown->setPos(250,250);
}

void GameControl::LoadStopAddItem()
{
    mStopScene.addItem(&mStopBackground);
    //mStopScene.addItem(&mStopRect);
    mStopScene.addWidget(Continue);
    mStopScene.addWidget(Quit);
    mStopScene.addItem(mStopText);
    mStopScene.addItem(mContinueText);
    mStopScene.addItem(mQuitText);
}

void GameControl::LoadStopAddEffect()
{
    mSBGBlurEffect = new QGraphicsBlurEffect(this);//模糊效果
    mSBGBlurEffect->setBlurRadius(30);

    mSBGOpacityEffect = new QGraphicsOpacityEffect(this);//透明效果
    mSBGOpacityEffect->setOpacity(0.7);

    mStopRectBGOpacityEffect = new QGraphicsOpacityEffect(this);//透明效果
    mStopRectBGOpacityEffect->setOpacity(0.7);
}

void GameControl::StopButtonConnect()
{
    //暂停按钮跳转暂停界面
    connect(mMainScene->stop,&QToolButton::clicked,this,&GameControl::Stop);
    //继续按钮跳转回主界面
    connect(Continue,&QToolButton::clicked,this,&GameControl::GameContinue);
}


#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "startscene.h"
#include "mainscene.h"
#include "endscene.h"

class GameControl:public QObject
{
    GameControl();//单例
    static GameControl* instance;
public:
    static GameControl* Instance();//创建单例
    ~GameControl();//析构函数

    //游戏初始化
    void setParent(GameWidget* Parent);//设置父亲指针
    void GameInit();

    void LoadMS();//获取谱面

    //计时器
    void CreateTimer();//创建计时器
    void TimerConnect();//计时器连接


    //其他函数
    void judgeStatus();//判断状态PGBM
    void ShowStatus();//显示状态PGBM
    void ShowComboNum();//显示连击数
    void ShowPoints();//显示分数
    void ResetEnddata();//在进入最终结算界面前重载数据

    //暂停界面
    void LoadStopScene();//加载暂停场景
    void Stop();
    void GameContinue();//继续游戏
    void LoadStopPicture();//给暂停场景元素添加图片
    void LoadStopSettingItems();//新建各元素
    void LoadStopPushButton();//初始化暂停场景中按钮
    void LoadStopPos();//初始化各元素位置
    void LoadStopAddItem();//初始化添加元素至场景
    void LoadStopAddEffect();//添加暂停背景效果
    void StopButtonConnect();

    QPushButton *Quit;//退出按钮
protected:
    MusicScore *mMS;//谱面

    GameWidget* parent;//场景的父亲指针

    QGraphicsView mGameView;//游戏主视图

    StartScene mStartScene;//游戏初始场景
    MainScene *mMainScene;//游戏主场景
    EndScene *mEndScene;

    QGraphicsScene mStopScene;//结束场景


    QGraphicsTextItem *mStopCountdown;//暂停倒计时
    QGraphicsTextItem *mStopText;
    QGraphicsTextItem *mContinueText;
    QGraphicsTextItem *mQuitText;

    QGraphicsPixmapItem mStopRect;//暂停界面黑色矩形底框
    QGraphicsPixmapItem mStopBackground;//暂停界面背景

    //按钮

    QPushButton *Continue;//继续按钮


    //计时器
    QTimer *mMSTimer;//谱面移动计时器
    QTimer *mDelay;//开始前缓冲计时器
    QTimer *mDetectKeyTimer;//检测按键计时器(包括边界判定)
    QTimer *BGMDelay;//BGM缓冲计时器
    QTimer *MSDelay;//结算界面计时器
    QTimer *MusicTimer;//音乐时间计时器
    QTimer *stopDelay;//暂停延时计时器

    //效果

    QGraphicsBlurEffect *mSBGBlurEffect;//暂停界面背景模糊效果
    QGraphicsOpacityEffect *mSBGOpacityEffect;//暂停界面背景透明效果
    QGraphicsOpacityEffect *mStopRectBGOpacityEffect;//暂停界面矩形背景透明效果



};

#endif // GAMECONTROL_H


#ifndef ENDSCENE_H
#define ENDSCENE_H
#include "gamescene.h"
#include "musicscore.h"

#include<QObject>
class EndScene : public GameScene
{
    Q_OBJECT
public:

signals:
    void RhyGameEnd();
public:
    EndScene(MusicScore *MS,GameWidget *parent);
    //结算界面
    void LoadScene();//初始化结算界面
    void LoadPos();//初始化各元素位置
    void AddItem();//初始化添加元素至场景
    void AddPicture();//添加结算背景元素图片
    void LoadPushButton();
    void AddEffect();//添加结算背景效果
    void LoadBGM();//初始化结算界面的BGM

    MusicScore *mMS;

    QGraphicsTextItem *mEndName;//结束界面谱面名字

    QGraphicsTextItem *mMaxCombo;//最大连击数
    QGraphicsTextItem *mMaxComboNum;
    QGraphicsTextItem *mAccuracy;//准度
    QGraphicsTextItem *mAccuracyNum;
    QGraphicsTextItem *mPerfect;
    QGraphicsTextItem *mPerfectNum;
    QGraphicsTextItem *mGood;
    QGraphicsTextItem *mGoodNum;
    QGraphicsTextItem *mBad;
    QGraphicsTextItem *mBadNum;
    QGraphicsTextItem *mMiss;
    QGraphicsTextItem *mMissNum;


    QGraphicsPixmapItem *mEndRect;//结束界面黑色矩形底框
    QGraphicsPixmapItem *mRank;//评级

    //音乐播放器
    QMediaPlaylist * BGMPlayerList;
    QMediaPlayer* BGMPlayer;

    //效果
    QGraphicsBlurEffect *mBGBlurEffect;//结算界面背景模糊效果
    QGraphicsOpacityEffect *mBGOpacityEffect;//结算界面背景透明效果

    //用于退出音乐游戏的按钮
    QPushButton* mEndButton;

    static QGraphicsTextItem *mScore;

};

#endif // ENDSCENE_H

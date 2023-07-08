
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "gamescene.h"


class MainScene : public GameScene
{
public:
    MainScene(MusicScore *MS,GameWidget *parent);

    //主界面
    void LoadScene();//初始化主要界面
    void LoadPos();//初始化各元素位置
    void AddItem();//初始化添加元素至场景
    void AddPicture();//添加主要背景元素图片
    void LoadPushButton();//按钮初始化
    void AddEffect();//添加主要背景效果
    void SettingItems();

    MusicScore *mMS;

    QGraphicsPixmapItem *mTrack1;//设置四个轨道
    QGraphicsPixmapItem *mTrack2;
    QGraphicsPixmapItem *mTrack3;
    QGraphicsPixmapItem *mTrack4;
    QGraphicsPixmapItem *mEmoji;//判定表情

    QGraphicsTextItem *mPoints;//分数
    QGraphicsTextItem *mAcc;//准度
    QGraphicsTextItem *mLv;//谱面难度
    QGraphicsTextItem *mPName;//谱面名字
    QGraphicsTextItem *mCombo;
    QGraphicsTextItem *mComboNum;//连击数
    QGraphicsTextItem *mStatus;//Perfect Good Bad Miss

    QPushButton *stop;//暂停按钮

    QGraphicsBlurEffect *mBGBlurEffect;//主界面背景模糊效果
    QGraphicsOpacityEffect *mBGOpacityEffect;//主界面背景透明效果
};

#endif // MAINSCENE_H

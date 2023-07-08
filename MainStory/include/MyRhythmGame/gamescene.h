
#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "gamedefine.h"
#include "gamewidget.h"
#include "musicscore.h"


class GameScene:public QGraphicsScene
{

public:
    GameScene();
    virtual ~GameScene();

    virtual void LoadScene() = 0;//加载场景
    virtual void LoadPos() = 0;//加载位置
    virtual void AddItem() = 0;//将元素添加到场景中去
    virtual void AddEffect() = 0;//添加效果
    virtual void AddPicture() = 0;//添加图片
    virtual void LoadPushButton() = 0;//加载按钮

    QGraphicsScene *mScene;//游戏场景
    QGraphicsPixmapItem *mBackground;//游戏背景
};

#endif // GAMESCENE_H

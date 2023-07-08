#ifndef STARTSCENE_H
#define STARTSCENE_H
#include "gamedefine.h"
class StartScene{
public:
    QGraphicsScene* mScene;
    QGraphicsPixmapItem* mBackground;
    QGraphicsPixmapItem* mTitle1;
    QGraphicsPixmapItem* mTitle2;
    QPushButton* mTitle3;
    QGraphicsPixmapItem* mXinhai1;
    QGraphicsPixmapItem* mXinhai2; 
    QPushButton* mMusicSelect;//挑选歌曲的按钮
public:
    StartScene();
    void LoadScene();
    void LoadPos();
    void AddItem();
    void AddPicture();
    void LoadPushButton();
    void AddEffect();
};

#endif // STARTSCENE_H

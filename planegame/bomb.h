
#ifndef BOMB_H
#define BOMB_H
#include<QPixmap>
#include<QVector>
#include<config.h>
class Bomb{
public:
    int x;//位置
    int y;
    QVector<QPixmap> bombPix;//爆炸图片数组
    int time;
    int index;//爆炸时播放的图片下标
    bool Played;//是否已经爆炸
    Bomb();
    void Play();//播放爆炸图片
};

#endif // BOMB_H


#ifndef BOMB_H
#define BOMB_H

#define BOMB_PATH ":/new/prefix1/picturefruit/bomb-%1.png"
//#define WMBOMB_PATH " "
//#define BNBOMB_PATH " "
//#define BOMBSOUND_PATH " "

#include<QPaintEvent>
#include<QPixmap>
#include<QVector>
#include<QString>
#include<QRectF>
//#include<QSound>

class Bomb
{

public:
    Bomb();
    void updateInfo();
    int x;
    int y;
    QVector<QPixmap> bombPix;
    int recored;
    int index;
    bool isPlayed;
    QRectF rectf;
};

#endif // BOMB_H


#ifndef BANANA_H
#define BANANA_H

#include"bomb.h"
#include<QPixmap>
#include<QRectF>



class Banana
{
public:
    Banana();
    Bomb bomb;
    float x;
    float y;
    bool isReverse;
    bool isFree;
    bool isDestroyed;
    bool isMissed;
    QPixmap banana;
    QPixmap Lslicedbanana;
    QPixmap Rslicedbanana;
    void updatePosition();
    QRectF rectf;
};

#endif // BANANA_H

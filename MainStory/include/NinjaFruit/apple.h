
#ifndef APPLE_H
#define APPLE_H

#include<QPixmap>
#include "bomb.h"
#include<QRectF>
#include<QLabel>



class Apple
{
public:
    Bomb bomb;
    Apple();
    float x;
    float y;
    bool isReverse;
    bool isFree;
    bool isDestroyed;
    bool isMissed;
    QPixmap apple;
    QPixmap Lslicedapple;
    QPixmap Rslicedapple;
    void updatePosition();
    void updatesliced();
    QRectF rectf;
};

#endif // APPLE_H

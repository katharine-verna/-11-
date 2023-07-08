
#ifndef WATERMELON_H
#define WATERMELON_H

#include"bomb.h"
#include<QPixmap>
#include<QRectF>


class Watermelon
{
public:
    Watermelon();
    Bomb bomb;
    float x;
    float y;
    bool isReverse;
    bool isFree;
    bool isDestroyed;
    bool isMissed;
    QPixmap watermelon;
    QPixmap Lslicedwatermelon;
    QPixmap Rslicedwatermelon;
    void updatePosition();
    QRectF rectf;
};

#endif // WATERMELON_H

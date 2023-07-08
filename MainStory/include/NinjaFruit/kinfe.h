
#ifndef KINFE_H
#define KINFE_H

#include<QPoint>
#include<QPixmap>
#include<QRectF>


class Kinfe
{
public:
    Kinfe();
    QPixmap myKinfe;
    int x;
    int y;
    int life;
    int recored;
    bool isPlayed;
    QRectF rectf;
};

#endif // KINFE_H

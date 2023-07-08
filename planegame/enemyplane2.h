
#ifndef ENEMYPLANE2_H
#define ENEMYPLANE2_H
#include<bullet.h>
#include<QPixmap>
#include<QRect>
#include<bomb.h>
#include<config.h>
class EnemyPlane2{
public:
    Bullet bullet1[BULLET_NUM];
    Bullet bullet2[BULLET_NUM];
    Bullet bullet3[BULLET_NUM];
    Bomb bomb;
    QPixmap enemyplane2;
    QRect rect;
    int life;
    int x;
    int y;
    int speed;
    bool Is_in;
    bool Is_destroyed;
    int time1;
    int time2;
    int power;
    EnemyPlane2();
    void shoot1();
    void shoot2();
    void Move();

};

#endif // ENEMYPLANE2_H

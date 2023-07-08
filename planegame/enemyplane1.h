
#ifndef ENEMYPLANE1_H
#define ENEMYPLANE1_H
#include<bullet.h>
#include<QRect>
#include<QPixmap>
#include<bomb.h>
#include<config.h>
class EnemyPlane1{
public:
    Bullet bullet[BULLET_NUM];
    Bomb bomb;//爆炸
    QPixmap enemyplane1;
    int life;
    int x;
    int y;
    int speed;
    QRect rect;
    bool Is_in;//在界面内部
    bool Is_destroyed;//被摧毁
    int time;
    EnemyPlane1();
    void shoot();
    void Move();

};

#endif // ENEMYPLANE1_H

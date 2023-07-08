
#ifndef BULLET_H
#define BULLET_H
#include<QString>
#include<QRect>
#include<config.h>
#include<QPixmap>
class Bullet{
public:
    QPixmap bullet;//自己子弹的图片
    QPixmap enemybullet1;//敌方飞机子弹图片
    QPixmap enemybullet2;//敌方飞机子弹图片
    int speed;//飞行速度
    int x;//位置x
    int y;//位置y
    bool Can_use;//某颗子弹是否可以被使用
    QRect m_rect;//矩形边框
    QRect e1_rect;
    QRect e2_rect;
    Bullet();
    void Move();//更新子弹坐标
    void EnemyMove();
    void EnemyMoveleft();
    void EnemyMoveright();

};

#endif // BULLET_H

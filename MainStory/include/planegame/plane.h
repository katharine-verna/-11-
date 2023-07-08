
#ifndef PLANE_H
#define PLANE_H
#include<bullet.h>
#include"config.h"
#include<QRect>
#include<QPixmap>
class Plane{
public:
    Bullet bullet[BULLET_NUM];//子弹配置
    QPixmap myplane;//图片
    QRect rect;//矩形边框
    int x;
    int y;//位置
    int life;//生命值
    double power;//积累的提高伤害的值
    int time;//标记时间，小于等于internal
    Plane();
    void shoot();
    void setPosition(int x,int y);//设置飞机位置

};

#endif // PLANE_H

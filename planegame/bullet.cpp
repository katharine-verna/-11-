
#include<bullet.h>
#include<config.h>

Bullet::Bullet(){
    bullet.load(BULLET_PATH);
    enemybullet1.load(EBULLET1_PATH);
    enemybullet2.load(EBULLET2_PATH);
    speed=BULLET_SPEED;
    Can_use=true;
    x=0;
    y=0;//不知道位置
    m_rect.setWidth(bullet.width());
    e1_rect.setWidth(enemybullet1.width());
    e2_rect.setWidth(enemybullet2.width());

    m_rect.setHeight(bullet.height());
    e1_rect.setHeight(enemybullet1.height());
    e2_rect.setHeight(enemybullet2.height());

    m_rect.moveTo(x,y);
    e1_rect.moveTo(x,y);
    e2_rect.moveTo(x,y);
}//构造函数
void Bullet::Move(){
    if(Can_use) return ;
    else{
        y-=BULLET_SPEED;//向上
        m_rect.moveTo(x,y);
    }
    if(y<=m_rect.height()){
        Can_use=true;
    }
}//我方飞机子弹移动函数
void Bullet::EnemyMove(){
    if(Can_use) return ;
    else{
        y+=BULLET_SPEED;
        e1_rect.moveTo(x,y);
        e2_rect.moveTo(x,y);
    }
    if(GAME_HEIGHT-y<=e1_rect.height()){
        Can_use=true;
    }//图片高度一样
}//敌方普通飞机子弹移动函数
void Bullet::EnemyMoveleft(){
    if(Can_use) return ;
    else{
        x-=2;
        y+=BULLET_SPEED;
        e1_rect.moveTo(x,y);
    }
    if(x<=e2_rect.width()||GAME_HEIGHT-y<=e1_rect.height()){
        Can_use=true;
    }
}
void Bullet::EnemyMoveright(){
    if(Can_use) return ;
    else{
        x+=2;
        y+=BULLET_SPEED;
        e1_rect.moveTo(x,y);
    }
    if(GAME_WIDTH-x<=e2_rect.width()||GAME_HEIGHT-y<=e1_rect.height()){
        Can_use=true;
    }
}//敌方大型飞机子弹移动函数


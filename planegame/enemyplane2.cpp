
#include<enemyplane2.h>
#include<config.h>

EnemyPlane2::EnemyPlane2(){
    enemyplane2.load(ENEMY2_PATH);
    x=0;
    y=0;
    life=5;
    Is_in=false;
    Is_destroyed=false;
    speed=ENEMY_SPEED;
    time1=0;
    time2=0;
    rect.setWidth(enemyplane2.width());
    rect.setHeight(enemyplane2.height());
    rect.moveTo(x,y);
}
void EnemyPlane2::shoot1(){
    time1++;
    if(time1<BULLET_INTERVAL1) return ;
    else{
        time1=0;
        for(int i=0;i<BULLET_NUM;i++){
            if(bullet1[i].Can_use){
                bullet1[i].x=x-5;
                bullet1[i].y=y+20;
                bullet1[i].Can_use=false;
                break;
            }
        }
        for(int i=0;i<BULLET_NUM;i++){
            if(bullet3[i].Can_use){
                bullet3[i].x=x+35;
                bullet3[i].y=y+20;
                bullet3[i].Can_use=false;
                break;
            }
        }
    }
}
void EnemyPlane2::shoot2(){
    time2++;
    if(time2<BULLET_INTERVAL2) return ;
    else{
        time2=0;
        for(int i=0;i<BULLET_NUM;i++){
            if(bullet2[i].Can_use){
                bullet2[i].x=x+20;
                bullet2[i].y=y+20;
                bullet2[i].Can_use=false;
                break;
            }
        }
    }
}
void EnemyPlane2::Move(){
    if(Is_in){
        y+=speed;
        rect.moveTo(x,y);
        if(y>GAME_HEIGHT+rect.height()){
            Is_destroyed=true;
            Is_in=false;
        }
    }
}


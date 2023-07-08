
#include<enemyplane1.h>
#include<config.h>

EnemyPlane1::EnemyPlane1(){
    enemyplane1.load(ENEMY1_PATH);
    x=0;
    y=0;
    life=1;
    Is_in=false;
    Is_destroyed=false;
    speed=ENEMY_SPEED;
    time=0;
    rect.setWidth(enemyplane1.width());
    rect.setHeight(enemyplane1.height());
    rect.moveTo(x,y);
}
void EnemyPlane1::shoot(){
    time++;
    if(time<BULLET_INTERVAL1) return ;
    else{
        time=0;
        for(int i=0;i<BULLET_NUM;i++){
            if(bullet[i].Can_use){
                bullet[i].Can_use=false;
                bullet[i].x=x+45;
                bullet[i].y=y+40;
                break;
            }
        }
    }
}
void EnemyPlane1::Move(){
    if(Is_in){
        y+=speed;
        rect.moveTo(x,y);
        if(y>GAME_HEIGHT+rect.height()){
            Is_destroyed=true;
            Is_in=false;
        }
    }//表示在场
    else return ;
}


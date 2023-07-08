
#include<bomb.h>
#include<config.h>

Bomb::Bomb(){
    for(int i=0;i<7;i++){
        QString str=QString(BOMB_PATH).arg(i);
        bombPix.push_back(QPixmap(str));
    }
    index=0;
    time=0;
    Played=false;//没有播放完毕
    x=0;
    y=0;
}
void Bomb::Play(){
    time++;
    if(time<BOMB_INTERVAL) return ;
    else{
        time=0;
        index++;
        if(index==BOMB_MAX-1){
            Played=true;
        }
    }
}


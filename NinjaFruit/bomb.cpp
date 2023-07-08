
#include "bomb.h"

Bomb::Bomb()
{
    for(int i = 0; i < 6;i++){
        QString str = QString(BOMB_PATH).arg(i);
        bombPix.push_back(str);
    }
    recored = 0;
    index = 0;
    x = 0;
    y = 0;
    isPlayed = false;
}

void Bomb::updateInfo(){
    recored++;
    if(recored == 12 && !isPlayed){
        //QSound *bombSound = new QSound(BOMBSOUND_PATH);
        //bombSound->play();
    }
    if(recored<20)
        return;
    recored = 0;
    index++;
    if(index > 5)
        isPlayed = true;
}



#include "watermelon.h"

Watermelon::Watermelon()
{
    watermelon.load(":/new/prefix1/picturefruit/watermelon.png");
    Lslicedwatermelon.load(":/new/prefix1/picturefruit/watermelonleft.png");
    Rslicedwatermelon.load(":/new/prefix1/picturefruit/watermelonright.png");
    x = rand()%2*(600-watermelon.width());
    y = 0;
    isFree = true;
    isMissed = false;
    isDestroyed = false;
    isReverse = 0;
    rectf.setHeight(watermelon.height());
    rectf.setWidth(watermelon.width());
    rectf.moveTo(x,y);
}

void Watermelon::updatePosition(){
    if(!isFree){
        if(isReverse == 0){
            x += 1.1;
            y += 0.004*x -1.2;
        }
        else{
            x -= 1.1;
            y += 0.004*(600 - x) - 1.2;
        }
    }
    if(y > 600 || x > 600 || x < 0 || y < 0){
        isFree = true;
        isMissed = true;
    }
}


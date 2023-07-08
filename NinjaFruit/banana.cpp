
#include "banana.h"

Banana::Banana()
{
    banana.load(":/new/prefix1/picturefruit/banana.png");
    Lslicedbanana.load(":/new/prefix1/picturefruit/bananaleft.png");
    Rslicedbanana.load(":/new/prefix1/picturefruit/bananaright.png");
    x = rand()%2*(600-banana.width());
    y = 0;
    isFree = true;
    isMissed = false;
    isDestroyed = false;
    isReverse = 0;
    rectf.setHeight(banana.height());
    rectf.setWidth(banana.width());
    rectf.moveTo(x,y);
}

void Banana::updatePosition(){
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

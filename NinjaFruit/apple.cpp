
#include "apple.h"

Apple::Apple()
{
    apple.load(":/new/prefix1/picturefruit/apple.png");
    Lslicedapple.load(":/new/prefix1/picturefruit/appleleft.png");
    Rslicedapple.load(":/new/prefix1/picturefruit/appleright.png");
    x = rand()%2*(600-apple.width());
    y = 0;
    isFree = true;
    isMissed = false;
    isDestroyed = false;
    isReverse = 0;
    rectf.setHeight(apple.height());
    rectf.setWidth(apple.width());
    rectf.moveTo(x,y);
}

void Apple::updatePosition(){
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


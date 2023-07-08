
#include "kinfe.h"

Kinfe::Kinfe()
{
    myKinfe.load(":/new/prefix1/picturefruit/knife.png");
    x = (650-myKinfe.width())*0.5;
    y = 600-myKinfe.height();
    recored = 0;
    isPlayed = false;
    life = 20;
    rectf.setHeight(myKinfe.height());
    rectf.setWidth(myKinfe.width());
    rectf.moveTo(x,y);
}

#include "mypushbutton.h"


myPushButton::myPushButton(QWidget *parent) : QPushButton(parent)
{
}

myPushButton::myPushButton(QString normalImg,QString pressImg)
{
    //初始化
    this->normalImgPath=normalImg;
    this->pressdImgPath=pressImg;
    //创建QPixmap对象
    QPixmap pix;
    //判断是否加载成功
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"加载图片失败";
    }
    pix=pix.scaled(200,200);

    //设置固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(pix.size());



}

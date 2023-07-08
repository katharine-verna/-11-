#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QDebug>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(QWidget *parent = nullptr);

    myPushButton(QString normalImg,QString pressImg="");

    QString normalImgPath;//默认显示图片路径
    QString pressdImgPath;//按下后显示图片路径

signals:

public slots:
};

#endif // MYPUSHBUTTON_H

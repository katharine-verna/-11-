
#ifndef NINJAFRUIT_H
#define NINJAFRUIT_H

#include <QWidget>
#include<QPushButton>
#include<QPainter>
#include<QPixmap>
#include<QImage>
#include<QPaintEvent>
#include<QLabel>
#include"ninja_fruit_global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NinjaFruit; }
QT_END_NAMESPACE

class NINJA_FRUIT_EXPORT NinjaFruit : public QWidget
{
    Q_OBJECT

    QPushButton *startGame;
    QPushButton *help;
    QPushButton *quit;
    QImage* background;
    QLabel* label;
    QLabel* label2;
    //paintEvent(QPaintEvent *event);
signals:
    void ninjaEneded();
public slots:
    void startClick();
    void helpClick();
    void quitClick();


public:
    NinjaFruit(QWidget *parent = nullptr);
    ~NinjaFruit();

private:
    Ui::NinjaFruit *ui;
};

#endif // NINJAFRUIT_H


#ifndef GAME_H
#define GAME_H


#include <QWidget>
#include<QTimer>
#include<kinfe.h>
#include<QPaintEvent>
#include<QPainter>
#include<QKeyEvent>
#include<QMouseEvent>
#include<banana.h>
#include<apple.h>
#include<watermelon.h>
#include<QLabel>
#include<endgame.h>
#include<trap.h>
//#include<QSound>

#define FDSOUND " "
#define SCORE "Score: %1"
#define LIFE "Life: %1"


class game : public QWidget
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = nullptr);
    bool win;
    bool winPlayed;
    int Score;
    //QSound *Player;
    QLabel *score;
    QLabel *life;
    Kinfe myKnife;
    QTimer Timer;
    Banana banana[20];
    Watermelon watermelon[20];
    Apple apple[20];
    int FruitRecorded;
    Trap trap[5];
    void initial();
    void startGame();
    void endGame();
    void updatePosition();
    void paintEvent(QPaintEvent *Event);
    void mouseMoveEvent(QMouseEvent *Event);
    void FruitShow();
    void GameWin();
    void collisionDetetion();
    int getDistanceBAK(Banana B,Kinfe K);
    int getDistanceWAK(Watermelon W,Kinfe K);
    int getDistanceAAK(Apple A,Kinfe K);
    int getDistanceTAK(Trap T,Kinfe K);
    ~game();

};

#endif // GAME_H

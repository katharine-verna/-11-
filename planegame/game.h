
#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include<plane.h>
#include<QPainter>
#include<QPaintEvent>
#include<QIcon>
#include<bullet.h>
#include<bomb.h>
#include<QPalette>
#include<config.h>
#include<enemyplane1.h>
#include<enemyplane2.h>
#include<QTimer>
#include<QMouseEvent>
#include<QWidget>
#include<QLabel>
#define SCORE "Score：%1"
#define LIFE "Life：%1"


class Game : public QWidget{

    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
    QLabel* lifeElement;
    QLabel* Score;
    int score;
    bool lambda;//确保lambda表达式只执行一次
    Plane myPlane;
    EnemyPlane1 enemy1[ENEMY1_NUM];
    EnemyPlane2 enemy2[ENEMY2_NUM];
    int Enemytime1;//1出场时间
    int Enemytime2;//2出场
    QTimer timer;
    void initial();//初始化
    void Startgame();//启动游戏
    void Update();//更新元素
    void paintEvent(QPaintEvent* );//绘制
    void mouseMoveEvent(QMouseEvent* );//鼠标移动
    void Enemy1Go();//敌机出场
    void Enemy2Go();
    void collisionCheck();
    void EndGame();
    bool allFinish();//判断所有飞机已经出场
};

#endif // GAME_H

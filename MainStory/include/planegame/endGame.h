
#ifndef ENDGAME_H
#define ENDGAME_H
#include<config.h>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#define SCO "SCORE：%1"

class endGame:public QWidget{
    Q_OBJECT
public slots:
    void quitClick();
public:
    QPushButton* quit;
    int Score;//分数
    int Life;//生命
    QLabel* score;
    QLabel* ach;//成就图
    QLabel* name;
    endGame(int life,int num,QWidget* parent=nullptr);
    ~endGame();
};

#endif // ENDGAME_H

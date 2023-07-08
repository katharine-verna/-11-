
#ifndef ENDGAME_H
#define ENDGAME_H


#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include"game.h"


class EndGame : public QWidget
{
    Q_OBJECT
public:
    explicit EndGame(QWidget *parent = nullptr);
    QPushButton *Again;
    QPushButton *Return;
    QLabel *Score;
    QLabel *Lose;
    EndGame(int x);
    ~EndGame();

public slots:
    void ReturnClicked();
    void AgainClicked();

};

#endif // ENDGAME_H

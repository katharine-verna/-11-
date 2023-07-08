#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "bomb.h"
#include "bullet.h"
#include "config.h"
#include "enemyplane1.h"
#include "enemyplane2.h"
#include "mainscene.h"
#include "mywidget.h"
#include "ninja_fruit_global.h"
#include "ninjafruit.h"
#include "plane.h"
#include "planegame_global.h"
#include "widget.h"

#include"include/MyRhythmGame/gamewidget.h"

namespace Ui {
class MainWidget;
}



class  MainScene;
class NinjaFruit;
class MainWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


    enum class GAME_TYPE{PUZZLE,PLANE_FIGHT,FRUIT_NINJA,MUSIC,MAIN_PAGE};


    void onPuzzleEnded();
    void onPLaneFightEnded();
    void onFruitEnded();
    void onMusicEneded();

private slots:
    void on_JigsawOpen_clicked();
    void on_PlaneOpen_clicked();
    void on_MusicGame_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWidget *ui;

    //GameWidget* music=nullptr;
    MainScene*  puzzle=nullptr;
    NinjaFruit* ninja=nullptr;
    MyWidget*   plane=nullptr;

    void onFirstSplashFinished();

    GAME_TYPE nextGame=GAME_TYPE::PUZZLE;

    void playFruitNinja();

    void fun1();



};

#endif // MAINWIDGET_H

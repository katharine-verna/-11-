#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QLabel>
#include "gameplayer.h"
#include "gamehelp.h"
#include "mypushbutton.h"
#include "jigsaw_copy_global.h"

namespace Ui {
class MainScene;
}

class JIGSAW_COPY_EXPORT MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();

    void loadImage( QString imagePath, int x,int y);//展示图片的函数

    gamePlayer* gameplayer=NULL;

    //static int jigsaw_main(int argc, char *argv[]);//接口

private:
    Ui::MainScene *ui;

signals:
    void JigsawEnd();//游戏结束释放信号
};

#endif // MAINSCENE_H

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H
#define ROW 3
#define COL 3
#define NUM 9
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QApplication>


struct Pos
{
    int x;
    int y;
};

namespace Ui {
class gamePlayer;
}

class gamePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit gamePlayer(QString url,QWidget *parent = 0);
    ~gamePlayer();

    void devideImg();//分割图片
    void randomImg();//打乱地图
    void placePix();//把pix放到label上
    bool eventFilter(QObject *watched, QEvent *event);//重写过滤器

    QPixmap game_Img;//完整的图片
    int game_Imgs_num[ROW][COL];//分割后图片的编号
    QLabel* game_label[ROW][COL];//分割后的9个label
    QPixmap game_pix[ROW][COL];//分割后的9个图片
    int game_count =0;//
    QTimer* timer;//计时器

    int flag = 0;//记录游戏的发生情况0代表正在进行 1代表暂停
    int game_stepNum = 0;//记录一共走了多少步
    int game_time = 0;//记录一局游戏所用时间

    Pos position[2];



signals:
    //返回的信号
    void returnSignal();
    void victorySignal();

private:
    Ui::gamePlayer *ui;
};

#endif // GAMEPLAYER_H

#include "mainscene.h"
#include "ui_mainscene.h"
#include "gamehelp.h"
#include "mypushbutton.h"
#include <QMediaPlayer>
#include <QTimer>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QMediaPlaylist>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //设置主页的大小
    this -> setFixedSize(490,490);

    //设置主页图标
    this ->setWindowIcon(QPixmap(":/res/p01.jpg"));

    //设置窗口标题
    this ->setWindowTitle("拼图小游戏");

    //选项-退出action实现
    connect(ui->quitAction,&QAction::triggered,[=]()
    {

        emit this->JigsawEnd();

    });

    //选项-帮助action实现
    connect(ui->helpAction,&QAction::triggered,[=]()
    {
        gamehelp *gameHelp=new gamehelp;//自定义的帮助类
        gameHelp->show();
    });

    //背景音乐
//    QMediaPlayer* player = new QMediaPlayer;
//    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//    player->setPlaybackRate();
//    player->setMedia(QUrl("qrc:/res/zood.mp3"));
//    player->setVolume(50);
//    player->play();

    QMediaPlaylist* playList = new QMediaPlaylist(this); //创建 播放列表
    QMediaPlayer* player = new QMediaPlayer(this);//创建播放器

    playList->addMedia(QUrl("qrc:/res/zood.mp3"));
    playList->setPlaybackMode(QMediaPlaylist::Loop);// 通过设置 播放列表循环 实现循环播放
    player->setPlaylist(playList);// 设置 播放列表到播放器
    player->setVolume(30); //设置播放器
    player->play(); //开始播放
\
    player->play();


    ui->musicContinue->setVisible(false);//在最开始隐藏“继续播放”

    connect(ui->musicQuit,&QAction::triggered,[=]()
    {
        player->stop();
        ui->musicQuit->setVisible(false);//停止播放音乐后隐藏“停止音乐”，并添加“继续播放”
        ui->musicContinue->setVisible(true);
    });

    connect(ui->musicContinue,&QAction::triggered,[=]()
    {
        player->play();
        ui->musicQuit->setVisible(true);//继续播放音乐后隐藏“继续播放”，并添加“停止音乐”
        ui->musicContinue->setVisible(false);
    });

    //加入图片


    loadImage(":/res/p01.jpg",30,30);//这里之前有一个bug，说不存在对应的loadImage，后来发现是声明loadImage时候忘记加const了
    loadImage(":/res/p02.jpg",260,30);
    loadImage(":/res/p03.jpg",30,260);
    loadImage(":/res/p04.jpg",260,260);





}

void MainScene::loadImage(QString imagePath, int x,int y)
{
    //mpb代表在主页展示的四张图片
    myPushButton *mpb = new myPushButton(imagePath);
    mpb->setParent(this);
    mpb->move(x,y);

    connect(mpb,&myPushButton::clicked,[=]()
    {
        //暂停0.5s进入游戏
        QTimer::singleShot(500,this,[=]()
        {
            this->hide();
            //接下来开始游戏
            gameplayer = new gamePlayer(imagePath);
            gameplayer->show();
            connect(gameplayer,&gamePlayer::returnSignal,[=]()
            {
                qDebug()<<"点击了返回主页";
                //返回主页后销毁本局游戏的信息
                QTimer::singleShot(500,this,[=]()
                {
                    gameplayer->hide();
                    this->show();
                    delete gameplayer;
                    gameplayer=NULL;
                });
            });

        });
    });
}

MainScene::~MainScene()
{
    delete ui;

}

//static int jigsaw_main(int argc, char *argv[])
//{
//    //解决电脑分辨率过高的问题
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QApplication a(argc, argv);
//    MainScene w;
//    w.show();

//    return a.exec();
//}




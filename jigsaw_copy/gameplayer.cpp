#include "gameplayer.h"
#include "ui_gameplayer.h"

#include <QSound>
#include <mypushbutton.h>
#include <QMultimedia>
#include <iostream>
#include <time.h>
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include <QMessageBox>
#include <QIcon>
#include <QTimer>
#include <QTime>


gamePlayer::gamePlayer(QString url,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamePlayer)
{
    ui->setupUi(this);
    //设置界面大小

    this->setFixedSize(916,762);
    timer= new QTimer(this);
    QPixmap pix1;
    pix1.load(url);
    ui->upperPicLabel->setPixmap(pix1);
    ui->upperPicLabel->setScaledContents(true);

    //把字显示全
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //设置标题图标
    QPixmap pix2;
    pix2.load(url);
    pix2=pix2.scaled(47,44);
    setWindowIcon(QIcon(pix2));

    //窗口标题
    setWindowTitle("Jigsaw Puzzle");

    //音效-目前还没有

    //PushButton功能实现
    //返回主页
    connect(ui->quitButton,&QPushButton::clicked,[=]()
    {
        emit this->returnSignal();
    });
    //开始游戏
    connect(ui->startButton,&QPushButton::clicked,[=]()
    {
        if(flag==0)
        {
            QMessageBox::information(this,"Begin","游戏就要开始了!");
            flag=1;
            ui->startButton->setText("暂停游戏");
            timer->start(1000);

        }
        else if(flag==1)
        {

            timer->stop();
            QMessageBox::information(this,"Begin","暂停一下，请马上回来！");
            flag=0;
            ui->startButton->setText("开始游戏");

        }
        else
        {
            qDebug()<<"flag错误";
        }
    });

    //超时函数
    connect(timer,&QTimer::timeout,[=]()
    {
        ui->timeLabel->setText(QString::number((this->game_time)++).append("s"));
    });

    for(int i=0;i<ROW;i++)
    {
        int x,y;

        for(int j=0;j<COL;j++)
        {
            x=30+j*210;
            y=118+i*210;

            game_label[i][j]= new QLabel(this);
            game_label[i][j]->move(x,y);
            game_label[i][j]->setFixedSize(200,200);
            game_label[i][j]->installEventFilter(this);//事件过滤器


        }
    }

    this->game_Img.load(url);

    randomImg();
    devideImg();
    placePix();

    connect(this,&gamePlayer::victorySignal,[=]()
    {
        timer->stop();
        flag=0;
        qDebug()<<"victory";
        int choice=QMessageBox::question(this,"Victory!!","恭喜你完成了拼图,\n请选择继续欣赏图片还是返回主页继续游玩","继续欣赏","返回主页继续游玩");
        ui->startButton->hide();
        if(choice)
        {
            emit this->returnSignal();
        }
    });



}

void gamePlayer::randomImg()
{
    int arr[NUM] ={0};
    int temp;
    srand((unsigned char)time(NULL));
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            temp=rand()%NUM;
            while(arr[temp])
            {
                temp=rand()%NUM;
            }
            game_Imgs_num[i][j]=temp;
            arr[temp]++;
            //qDebug()<<game_Imgs_num[i][j];

        }
    }
}

void gamePlayer::devideImg()
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            game_pix[i][j]=game_Img.copy(j*200,i*200,200,200);
            //qDebug()<<i<<" "<<j;
        }
    }
}

void gamePlayer::placePix()
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            this->game_label[i][j]->setPixmap(this->game_pix[this->game_Imgs_num[i][j]/ROW][this->game_Imgs_num[i][j]%ROW]);

        }
    }
}

bool gamePlayer::eventFilter(QObject *watched, QEvent *event)
{
    int t,f=1;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(flag==1&&watched==this->game_label[i][j])
            {
                if(event->type()==QEvent::MouseButtonPress)
                {
                    QMouseEvent *mouseevent = static_cast<QMouseEvent *>(event);
                    if(mouseevent->buttons()==Qt::LeftButton)
                    {
                        position[this->game_count].x=i;
                        position[this->game_count].y=j;
                        this->game_count++;
                        if(this->game_count==2)
                        {
                            if(position[0].x==position[1].x&&position[0].y==position[1].y)
                            {
                                QMessageBox::information(this,"错啦","请不要反复点击同一部位！");
                                this->game_count--;
                            }
                            else
                            {

                                this->game_stepNum++;
                                ui->stepNumLabel->setText(QString::number(this->game_stepNum)+"步");
                                t = this->game_Imgs_num[position[0].x][position[0].y];
                                this->game_Imgs_num[position[0].x][position[0].y]=
                                        this->game_Imgs_num[position[1].x][position[1].y];
                                this->game_Imgs_num[position[1].x][position[1].y]=t;
                                this->game_label[position[0].x][position[0].y]->setPixmap
                                        (this->game_pix[this->game_Imgs_num[position[0].x][position[0].y]/ROW]
                                        [this->game_Imgs_num[position[0].x][position[0].y]%COL]);
                                this->game_label[position[1].x][position[1].y]->setPixmap
                                        (this->game_pix[this->game_Imgs_num[position[1].x][position[1].y]/ROW]
                                        [this->game_Imgs_num[position[1].x][position[1].y]%COL]);
                                this->game_count=0;

                                for(int i=0;i<ROW;i++)
                                {
                                    for(int j=0;j<COL;j++)
                                    {
                                        if(this->game_Imgs_num[i][j]!=i*3+j)
                                        {
                                            f=0;
                                            break;
                                        }
                                        if(f==0)
                                        {
                                            break;
                                        }
                                    }
                                }
                                if(f==1)
                                {
                                    qDebug()<<"胜利！";
                                    emit this->victorySignal();
                                }


                            }
                        }
                    }

                }
                return QWidget::eventFilter(watched, event);
            }

        }
    }
}

gamePlayer::~gamePlayer()
{
    delete ui;
}




















#include "mainwidget.h"
#include "ui_mainwidget.h"

#include"imagedialog.h"
#include<mainscene.h>
#include"ninjafruit.h"
#include"gamewidget.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

MainWidget::MainWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);


}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_JigsawOpen_clicked()
{
    this->hide();
    MainScene* w_1 = new MainScene;
    w_1->show();
    connect(w_1, &MainScene::JigsawEnd,[=]()
    {
        //w_1->hide();
        this->show();
    });
}

void MainWidget::on_PlaneOpen_clicked()
{
    this->hide();
    MyWidget* w_2 = new MyWidget;
    w_2->show();
    connect(w_2, &MyWidget::quitClickSignal, [=](){
        w_2->hide();
        this->show();
    });

}

void MainWidget::on_MusicGame_clicked()
{
    this->hide();


}


void MainWidget::fun1()
{

}

int count=0;
void MainWidget::on_pushButton_clicked()
{


    auto dialog=new ImageDialog(this);
    dialog->setInterval(500);
    connect(dialog,&ImageDialog::playFinished,this,&MainWidget::onFirstSplashFinished);
    if(nextGame==GAME_TYPE::PUZZLE&&count==0){
        dialog->setWindowTitle("某个未知的早晨");

        dialog->addImage("qrc:/../res/part1-1-01.png");
        dialog->addImage("qrc:/../res/part1-1-02.png");
        dialog->addImage("qrc:/../res/part1-1-03.png");
        dialog->addImage("qrc:/../res/part1-1-04.png");
        dialog->addImage("qrc:/../res/part1-1-05.png");
        dialog->addImage("qrc:/../res/part1-1-06.png");
        dialog->addImage("qrc:/../res/part1-1-07.png");
        dialog->addImage("qrc:/../res/part1-1-08.png");
        dialog->addImage("qrc:/../res/part1-1-09.png");
        dialog->addImage("qrc:/../res/part1-1-10.png");
        dialog->addImage("qrc:/../res/part1-1-11.png");
        dialog->addImage("qrc:/../res/part1-1-12.png");
        dialog->addImage("qrc:/../res/part1-1-13.png");
        dialog->addImage("qrc:/../res/part1-1-14.png");
        dialog->addImage("qrc:/../res/part1-1-15.png");


        //QLabel* label_1=new QLabel(this);

        for(int i=0;i<=5;i++)
        {
            dialog->addImage("qrc:/../res/part1-2.png");
            //闹钟的响声，虽然并没有

        }
        for(int i=0;i<=5;i++) dialog->addImage("qrc:/../res/part1-3.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-4.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-5.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-6.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-7.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-8.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-9.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-10.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-11.png");
        for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part1-12.png");


    }
    else if(nextGame==GAME_TYPE::FRUIT_NINJA){
        dialog->setWindowTitle("午饭");
        for(int i=0;i<=5;i++) dialog->addImage("qrc:/../res/part2-1.png");
        for(int i=0;i<=5;i++) dialog->addImage("qrc:/../res/part2-2.png");
       // for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part2-3.png");
       // for(int i=0;i<=3;i++) dialog->addImage("qrc:/../res/part2-4.png");

    }else if(nextGame==GAME_TYPE::PLANE_FIGHT){
        dialog->setWindowTitle("图书馆的一角");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-1.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-2.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-3.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-4.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-5.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-6.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-7.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-8.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-9.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-10.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-11.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-12.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-13.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part3-14.png");

    }else if(nextGame==GAME_TYPE::MUSIC){
        dialog->setWindowTitle("入夜");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part4-1.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part4-2.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part4-3.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part4-4.png");
        dialog->addImage("qrc:/../res/part4-4-01.png");
        dialog->addImage("qrc:/../res/part4-4-02.png");
        dialog->addImage("qrc:/../res/part4-4-03.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part4-5.png");
        for(int i=0;i<=2;i++) dialog->addImage("qrc:/../res/part4-6.png");
    }


    dialog->setAttribute(Qt::WA_DeleteOnClose);
    this->hide();
    dialog->show();
    dialog->start();


}

void MainWidget::onFirstSplashFinished()
{
    this->show();

    auto dialog=qobject_cast<ImageDialog*>(sender());


    if(nextGame==GAME_TYPE::PUZZLE){
        puzzle=new MainScene(this);
        connect(puzzle,&MainScene::JigsawEnd,this,&MainWidget::onPuzzleEnded);
        puzzle->show();
    }else if(nextGame==GAME_TYPE::FRUIT_NINJA){
        this->ninja=new NinjaFruit(this);

        connect(ninja,&NinjaFruit::ninjaEneded,this,&MainWidget::onFruitEnded);
        ninja->setAttribute(Qt::WA_DeleteOnClose);
        ninja->setWindowModality(Qt::ApplicationModal);
        ninja->show();
    }else if(nextGame==GAME_TYPE::PLANE_FIGHT){
        qDebug()<<"plane fight";
        this->plane=new MyWidget(this);
        connect(plane,&MyWidget::quitClickSignal,this,&MainWidget::onPLaneFightEnded);
        plane->setAttribute(Qt::WA_DeleteOnClose);
        plane->setWindowModality(Qt::ApplicationModal);
        plane->show();
    }else if(nextGame==GAME_TYPE::MUSIC){
//        this->music=new GameWidget(this);

//        connect(music,&GameWidget::RhyGameQuit,this,&MainWidget::onMusicEneded);
//        music->setAttribute(Qt::WA_DeleteOnClose);
//        music->setWindowModality(Qt::ApplicationModal);
//        music->show();
    }

    dialog->close();
}

void MainWidget::onPuzzleEnded(){
    ui->pushButton->setText("continue Story");
    nextGame=GAME_TYPE::FRUIT_NINJA;
    this->show();
    puzzle->close();
    puzzle->deleteLater();
    qDebug()<<"puzzle finished";

}

void MainWidget::onFruitEnded(){
    qDebug()<<"fruit Eneded";
    nextGame=GAME_TYPE::PLANE_FIGHT;
    this->show();
    ninja->close();
    ninja->deleteLater();

}

void MainWidget::onPLaneFightEnded(){
    nextGame=GAME_TYPE::MUSIC;
    this->show();;
    plane->deleteLater();
    plane=nullptr;

}

void MainWidget::onMusicEneded(){
   // nextGame=GAME_TYPE::MAIN_PAGE;
   // this->show();;
   // music->deleteLater();
    //music=nullptr;
}

void MainWidget::playFruitNinja(){

}

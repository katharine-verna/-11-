#include "game.h"
#include<cmath>
#include<endGame.h>
#include<QIcon>
#include<QRect>
#include<config.h>


Game::~Game()
{

}
Game::Game(QWidget* parent):QWidget(parent){
    //窗口关闭，对象销毁
    setAttribute(Qt::WA_DeleteOnClose,true);
    //设置为模态框。(如果再设置无边框窗口，那么模态会失效，不会阻塞其他窗口，须重新设置)
    setAttribute(Qt::WA_ShowModal, true);
    QPixmap pixmap(GAME_BACK);
    QPalette pal=this->palette();
    setAutoFillBackground(true);
    pal.setBrush(QPalette::Window,QBrush(pixmap));
    setPalette(pal);
    score=0;
    lambda=false;
    initial();//初始化游戏资源
    lifeElement=new QLabel(this);
    Score=new QLabel(this);

    Score->setFont(QFont("幼圆",15));
    lifeElement->setFont(QFont("幼圆",15));

    Score->setStyleSheet("QLabel{background:transparent;color:white;}");
    lifeElement->setStyleSheet("QLabel{background:transparent;color:white;}");

    Score->setGeometry(QRect(20,50,200,70));
    lifeElement->setGeometry(QRect(20,90,200,110));

    Score->setText(QString(SCORE).arg(0));
    lifeElement->setText(QString(LIFE).arg(50));

    Startgame();
}
void Game::initial(){
    timer.setInterval(GAME_RATE);//设置定时器间隔，10ms刷新
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    Enemytime1=0;
    Enemytime2=0;
    srand((unsigned int)time(NULL));//随机数种子
}

void Game::Startgame(){
    timer.start();
    connect(&timer,&QTimer::timeout,this,[=](){
        if(!lambda){
            Enemy1Go();
            Enemy2Go();
            Update();//更新元素并绘制
            update();
            collisionCheck();
            EndGame();
        }
        else return ;
    });
}
void Game::Enemy1Go(){
    Enemytime1++;
    if(Enemytime1<ENEMY1_INTERVAL){
        return;
    }
    else{
        Enemytime1=0;
        for(int i=0;i<ENEMY1_NUM;i++){
            if(!enemy1[i].Is_in&&!enemy1[i].Is_destroyed){
                enemy1[i].Is_in=true;
                enemy1[i].x=rand()%(GAME_WIDTH-enemy1[i].rect.width());
                enemy1[i].y=-enemy1[i].rect.height();
                break;
            }
        }
    }
}
void Game::Enemy2Go(){
    Enemytime2++;
    if(Enemytime2<ENEMY2_INTERVAL){
        return;
    }
    else{
        Enemytime2=0;
        for(int i=0;i<ENEMY2_NUM;i++){
            if(!enemy2[i].Is_in&&!enemy2[i].Is_destroyed){
                enemy2[i].Is_in=true;
                enemy2[i].x=rand()%(GAME_WIDTH-enemy2[i].rect.width());
                enemy2[i].y=-enemy2[i].rect.height();
                break;
            }
        }
    }
}
void Game::collisionCheck(){
    for(int i=0;i<ENEMY1_NUM;i++){
        if(enemy1[i].Is_in&&!enemy1[i].Is_destroyed){//敌机1和我机碰撞
            if(enemy1[i].rect.intersects(myPlane.rect)){
                myPlane.life--;
                score+=10;
                enemy1[i].Is_destroyed=true;
            }
            for(int j=0;j<BULLET_NUM;j++){
                if(myPlane.bullet[j].Can_use){
                    continue;
                }
                else{//我机子弹击中敌机1
                    if(!enemy1[i].Is_destroyed&&myPlane.bullet[j].m_rect.intersects(enemy1[i].rect)){
                        myPlane.bullet[j].Can_use=true;
                        score+=10;
                        enemy1[i].Is_destroyed=true;
                    }
                }
            }
        }
        //敌机的子弹
        for(int j=0;j<BULLET_NUM;j++){
            //没有发射的
            if(enemy1[i].bullet[j].Can_use){
                continue;
            }
            else{//敌机1子弹击中我机
                if(myPlane.rect.intersects(enemy1[i].bullet[j].e1_rect)){
                    myPlane.life--;
                    enemy1[i].bullet[j].Can_use=true;
                }
            }
        }
    }
    for(int i=0;i<ENEMY2_NUM;i++){
        if(!enemy2[i].Is_destroyed&&enemy2[i].Is_in){
            //碰撞
            if(enemy2[i].rect.intersects(myPlane.rect)){
                myPlane.life--;
                enemy2[i].life--;
                if(enemy2[i].life<=0){
                    score+=20;
                    enemy2[i].Is_destroyed=true;
                }
            }
            for(int j=0;j<BULLET_NUM;j++){
                if(myPlane.bullet[j].Can_use){
                    continue;
                }
                else{//我机子弹击中敌机2
                    if(!enemy2[i].Is_destroyed&&myPlane.bullet[j].m_rect.intersects(enemy2[i].rect)){
                        enemy2[i].life--;
                        myPlane.bullet[j].Can_use=true;
                        if(enemy2[i].life<=0){
                            enemy2[i].Is_destroyed=true;
                            score+=20;
                        }
                    }
                }
            }
        }
        //敌机2三个弹夹击中我机
        for(int j=0;j<BULLET_NUM;j++){
            if(!enemy2[i].bullet1[j].Can_use){
                if(enemy2[i].bullet1[j].e1_rect.intersects(myPlane.rect)){
                    myPlane.life--;
                    enemy2[i].bullet1[j].Can_use=true;
                }
            }
            if(!enemy2[i].bullet2[j].Can_use){
                if(enemy2[i].bullet2[j].e2_rect.intersects(myPlane.rect)){
                    myPlane.life--;
                    enemy2[i].bullet2[j].Can_use=true;
                }
            }
            if(!enemy2[i].bullet3[j].Can_use){
                if(enemy2[i].bullet3[j].e1_rect.intersects(myPlane.rect)){
                    myPlane.life--;
                    enemy2[i].bullet3[j].Can_use=true;
                }
            }
        }
    }
}
void Game::Update(){
    myPlane.shoot();//发射子弹
    for(int i=0;i<30;i++){
        myPlane.bullet[i].Move();//子弹移动
    }
    //敌机移动
    for(int i=0;i<ENEMY1_NUM;i++){
        if(enemy1[i].Is_in&&!enemy1[i].Is_destroyed){
            enemy1[i].shoot();
            enemy1[i].Move();//更新位置，发射子弹
        }
        if(enemy1[i].Is_destroyed&&enemy1[i].Is_in){
            enemy1[i].bomb.Play();//爆炸图片
        }
        for(int j=0;j<BULLET_NUM;j++){
            enemy1[i].bullet[j].EnemyMove();//子弹移动
        }
    }
    for(int i=0;i<ENEMY2_NUM;i++){
        if(enemy2[i].Is_in&&!enemy2[i].Is_destroyed){
            enemy2[i].shoot1();
            enemy2[i].shoot2();
            enemy2[i].Move();
        }
        if(enemy2[i].Is_destroyed&&enemy2[i].Is_in){
            enemy2[i].bomb.Play();
        }
        for(int j=0;j<30;j++){
            enemy2[i].bullet1[j].EnemyMoveleft();//子弹移动
            enemy2[i].bullet2[j].EnemyMove();
            enemy2[i].bullet3[j].EnemyMoveright();
        }
    }
    lifeElement->setText(QString(LIFE).arg(myPlane.life));
    Score->setText(QString(SCORE).arg(score));
}
void Game::paintEvent(QPaintEvent* ){
    QPainter painter(this);
    painter.drawPixmap(myPlane.x,myPlane.y,myPlane.myplane);//飞机
    for(int i=0;i<BULLET_NUM;i++){
        if(!myPlane.bullet[i].Can_use){
            painter.drawPixmap(myPlane.bullet[i].x,myPlane.bullet[i].y,myPlane.bullet[i].bullet);
        }
    }
    for(int i=0;i<ENEMY1_NUM;i++){
        if(enemy1[i].Is_in){
            if(!enemy1[i].Is_destroyed){
                painter.drawPixmap(enemy1[i].x,enemy1[i].y,enemy1[i].enemyplane1);
            }
            else{
                if(!enemy1[i].bomb.Played){
                    painter.drawPixmap(enemy1[i].x,enemy1[i].y,enemy1[i].bomb.bombPix[enemy1[i].bomb.index]);
                }
            }//绘制爆炸
        }
        for(int j=0;j<BULLET_NUM;j++){
            if(!enemy1[i].bullet[j].Can_use){
                painter.drawPixmap(enemy1[i].bullet[j].x,enemy1[i].bullet[j].y,enemy1[i].bullet[j].enemybullet1);
            }
        }
    }
    for(int i=0;i<ENEMY2_NUM;i++){
        if(enemy2[i].Is_in){
            if(!enemy2[i].Is_destroyed){
                painter.drawPixmap(enemy2[i].x,enemy2[i].y,enemy2[i].enemyplane2);
            }
            else{
                if(!enemy2[i].bomb.Played){
                    painter.drawPixmap(enemy2[i].x,enemy2[i].y,enemy2[i].bomb.bombPix[enemy2[i].bomb.index]);
                }
            }
        }
        for(int j=0;j<BULLET_NUM;j++){
            if(!enemy2[i].bullet1[j].Can_use){
                painter.drawPixmap(enemy2[i].bullet1[j].x,enemy2[i].bullet1[j].y,enemy2[i].bullet1[j].enemybullet1);
            }
            if(!enemy2[i].bullet2[j].Can_use){
                painter.drawPixmap(enemy2[i].x+20,enemy2[i].bullet2[j].y,enemy2[i].bullet2[j].enemybullet2);
            }
            if(!enemy2[i].bullet3[j].Can_use){
                painter.drawPixmap(enemy2[i].bullet3[j].x,enemy2[i].bullet3[j].y,enemy2[i].bullet3[j].enemybullet1);
            }
        }
    }
}
void Game::mouseMoveEvent(QMouseEvent* e){
    int x=e->pos().rx()-myPlane.rect.width()*0.5;
    int y=e->pos().ry()-myPlane.rect.height()*0.5;
    if(x<=0){
        x=0;
    }
    if(x>=GAME_WIDTH-myPlane.rect.width()){
        x=GAME_WIDTH-myPlane.rect.width();
    }
    if(y<=0){
        y=0;
    }
    if(y>=GAME_HEIGHT-myPlane.rect.height()){
        y=GAME_HEIGHT-myPlane.rect.height();
    }
    myPlane.x=x;
    myPlane.y=y;
    myPlane.setPosition(x,y);
}
bool Game::allFinish(){
    for(int i=0;i<ENEMY1_NUM;i++){
        if(!enemy1[i].Is_destroyed) return false;
        else continue;
    }
    for(int i=0;i<ENEMY2_NUM;i++){
        if(!enemy2[i].Is_destroyed) return false;
        else continue;
    }
    return true;
}
void Game::EndGame(){
    if(myPlane.life<=0||allFinish()){
        endGame* e=new endGame(myPlane.life,score);
        e->show();
        this->close();
        lambda=true;
    }
}



#include "game.h"
#include<ctime>
#include<cmath>
#include<QMessageBox>
#include<QLabel>
#include<QVBoxLayout>
#include<QString>
#include<iostream>
//#include<QSound>
using namespace std;

game::game(QWidget *parent)
    : QWidget(parent)
{
    QWidget::setCursor(QCursor(Qt::BlankCursor));
    setAttribute(Qt::WA_DeleteOnClose,true);
    resize(600,550);
    this->setWindowIcon(QIcon(":/new/prefix1/picturefruit/icon-2.png"));
    this->setWindowTitle("FruitNinja");
    Score = 0;
    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap = QPixmap(":/new/prefix1/picturefruit/background.jpg").scaled(this->size());
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    setPalette(palette);
    life = new QLabel(this);
    score = new QLabel(this);
    life->setFont(QFont("Algerian",16));
    life->setStyleSheet("QLabel{background:transparent;color:white;}");
    score->setFont(QFont("Algerian",16));
    score->setStyleSheet("QLabel{background:transparent;color:white;}");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(life);
    layout->addWidget(score);
    //Player = new QSound(FDSOUND);
    setLayout(layout);
    win = false;
    winPlayed = false;
    initial();
}

game::~game(){
    setAttribute(Qt::WA_DeleteOnClose,true);
}

void game::initial(){
    Timer.setInterval(10);//设置定时器间隔，每10ms刷新一次
    FruitRecorded = 0;
    startGame();
    srand((unsigned int)time(NULL));
}

void game::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(myKnife.x,myKnife.y,myKnife.myKinfe);
    for(int i = 0; i < 20; i++){
        if(!banana[i].isFree && !banana[i].isDestroyed)

            painter.drawPixmap(banana[i].x,banana[i].y,banana[i].banana);
    }
    for(int i = 0; i < 20; i++){
        if(!apple[i].isFree && !apple[i].isDestroyed)
            painter.drawPixmap(apple[i].x,apple[i].y,apple[i].apple);
    }
    for(int i = 0; i < 20; i++){
        if(!watermelon[i].isFree && !watermelon[i].isDestroyed)
            painter.drawPixmap(watermelon[i].x,watermelon[i].y,watermelon[i].watermelon);
    }
    for(int i = 0; i < 5; i++){
        if(!trap[i].isFree &&trap[i].isDestroyed && !trap[i].bomb.isPlayed)
            painter.drawPixmap(trap[i].x,trap[i].y,trap[i].bomb.bombPix[trap[i].bomb.index]);
        else if(!trap[i].isFree && !trap[i].isDestroyed)
            painter.drawPixmap(trap[i].x,trap[i].y,trap[i].trap);
    }
    painter.drawPixmap(myKnife.x,myKnife.y,myKnife.myKinfe);
}

void game::mouseMoveEvent(QMouseEvent *Event){
    int x = Event->x();
    int y = Event->y();
    if(x > 0 && x < 600)
        myKnife.x = x;
    if(y > 0 && y < 550)
        myKnife.y = y;
    myKnife.rectf.moveTo(myKnife.x,myKnife.y);
    update();
}

void game::updatePosition(){
    life->setText(QString(LIFE).arg(myKnife.life));
    score->setText(QString(SCORE).arg(Score));
    for(int i = 0; i < 5; i++){
        if(!trap[i].isFree && !trap[i].isDestroyed){
            trap[i].updatePosition();
            trap[i].rectf.moveTo(trap[i].x,trap[i].y);
        }
        if(trap[i].isDestroyed &&! trap[i].isFree)
            trap[i].bomb.updateInfo();
    }
    for(int i = 0; i < 20; i++){
        if(!banana[i].isFree && !banana[i].isDestroyed){
            banana[i].updatePosition();
            banana[i].rectf.moveTo(banana[i].x,banana[i].y);
        }
        if(banana[i].isDestroyed && !banana[i].isFree){
            //Player->play();
            banana[i].isFree = true;
        }
    }
    for(int i = 0; i < 20; i++){
        if(!apple[i].isFree && !apple[i].isDestroyed){
            apple[i].updatePosition();
            apple[i].rectf.moveTo(apple[i].x,apple[i].y);
        }
        if(apple[i].isDestroyed && !apple[i].isFree){
            //Player->play();
            apple[i].isFree = true;
        }
    }
    for(int i = 0; i < 20; i++){
        if(!watermelon[i].isFree && !watermelon[i].isDestroyed){
            watermelon[i].updatePosition();
            watermelon[i].rectf.moveTo(watermelon[i].x,watermelon[i].y);
        }
        if(watermelon[i].isDestroyed && !watermelon[i].isFree){
             //Player->play();
             watermelon[i].isFree = true;
        }
    }
}

void game::startGame(){
    Timer.start();
        connect(&Timer,&QTimer::timeout,this,[=](){
            FruitShow();
            updatePosition();
            update();
            collisionDetetion();
            endGame();
        });
}

void game::FruitShow(){
    FruitRecorded++;
    if(FruitRecorded < 200)
        return;
    FruitRecorded = 0;
    int fruitcnt;
    fruitcnt= rand()%4 + 4;
    int trapcnt;
    trapcnt = rand()%2;
    int applecnt;
    applecnt = rand()%4;
    int watermeloncnt;
    watermeloncnt = rand()%(fruitcnt-trapcnt-applecnt+1);
    int bananacnt;
    bananacnt = fruitcnt-trapcnt-watermeloncnt-applecnt;
    /*
    for(int i = 0,j = 0; i < trapcnt&&(i+j<20);j++){
        if(trap[i+j].isFree){
             trap[i+j].isReverse = rand()%2;
             trap[i+j].isFree = false;
             trap[i+j].x = trap[i+j].isReverse*(600-trap[i+j].trap.width());
             trap[i+j].y = rand()%300+175;
             i++;
        }
    }
    for(int i = 0,j = 0; i < applecnt&&(i+j<20);j++){
        if(apple[i+j].isFree){
             apple[i+j].isReverse = rand()%2;
             apple[i+j].isFree = false;
             apple[i+j].isMissed = false;
             apple[i+j].isDestroyed = false;
             apple[i+j].x = apple[i+j].isReverse*(600-apple[i+j].apple.width());
             apple[i+j].y = rand()%300+175;
             i++;
        }
    }
    for(int i = 0,j = 0; i < bananacnt&&(i+j<20);j++){
        if(banana[i+j].isFree){
             banana[i+j].isReverse = rand()%2;
             banana[i+j].isFree = false;
             banana[i+j].isMissed = false;
             banana[i+j].isDestroyed = false;
             banana[i+j].x = banana[i+j].isReverse*(600-banana[i+j].banana.width());
             banana[i+j].y = rand()%300+175;
             i++;
        }
    }
    for(int i = 0,j = 0; i < watermeloncnt&&(i+j<20);j++){
        if(watermelon[i+j].isFree){
             watermelon[i+j].isReverse = rand()%2;
             watermelon[i+j].isFree = false;
             watermelon[i+j].isMissed = false;
             watermelon[i+j].isDestroyed = false;
             watermelon[i+j].x = watermelon[i+j].isReverse*(600-watermelon[i+j].watermelon.width());
             watermelon[i+j].y = rand()%300+175;
             i++;
        }
    }
    */
    for(int i = 0; i < trapcnt;i++){
        if(trap[i].isFree){
             trap[i].isReverse = rand()%2;
             trap[i].isFree = false;
             trap[i].isDestroyed = false;
             trap[i].x = trap[i].isReverse*(600-trap[i].trap.width());
             trap[i].y = rand()%300+175;
        }
    }
    for(int i = 0; i < applecnt;i++){
        if(apple[i].isFree){
             apple[i].isReverse = rand()%2;
             apple[i].isFree = false;
             apple[i].isMissed = false;
             apple[i].isDestroyed = false;
             apple[i].x = apple[i].isReverse*(600-apple[i].apple.width());
             apple[i].y = rand()%300+175;
        }
    }
    for(int i = 0; i < bananacnt;i++){
        if(banana[i].isFree){
             banana[i].isReverse = rand()%2;
             banana[i].isFree = false;
             banana[i].isMissed = false;
             banana[i].isDestroyed = false;
             banana[i].x = banana[i].isReverse*(600-banana[i].banana.width());
             banana[i].y = rand()%300+175;
        }
    }
    for(int i =0; i < watermeloncnt;i++){
        if(watermelon[i].isFree){
             watermelon[i].isReverse = rand()%2;
             watermelon[i].isFree = false;
             watermelon[i].isMissed = false;
             watermelon[i].isDestroyed = false;
             watermelon[i].x = watermelon[i].isReverse*(600-watermelon[i].watermelon.width());
             watermelon[i].y = rand()%300+175;
        }
    }
}

void game::collisionDetetion(){
    for(int i = 0; i < 20; i++){
        if(!apple[i].isFree && !apple[i].isDestroyed){
             /*
             if(getDistanceAAK(apple[i],myKnife)<20){
                 score++;
                 apple[i].isDestroyed = true;
             }
             */
             if((apple[i].rectf).intersects(myKnife.rectf)){
                 Score++;
                 apple[i].isDestroyed = true;

             }
        }
        else if(apple[i].isMissed){
             myKnife.life--;
             apple[i].isMissed = false;
        }
    }
    for(int i = 0; i < 20; i++){
        if(!banana[i].isFree && !banana[i].isDestroyed){
             /*
             if(getDistanceBAK(banana[i],myKnife)<20){
                 score++;
                 banana[i].isDestroyed = true;
             }
             */
             if((banana[i].rectf).intersects(myKnife.rectf)){
                 Score++;
                 banana[i].isDestroyed = true;
             }
        }
        else if(banana[i].isMissed){
             myKnife.life--;
             banana[i].isMissed = false;
        }
    }
    for(int i = 0; i < 20; i++){
        if(!watermelon[i].isFree && !watermelon[i].isDestroyed){
             /*
             if(getDistanceWAK(watermelon[i],myKnife)<20){
                 score++;
                 watermelon[i].isDestroyed = true;
             }
             */
             if((watermelon[i].rectf).intersects(myKnife.rectf)){
                 Score++;
                 watermelon[i].isDestroyed = true;
             }
        }
        else if(watermelon[i].isMissed){
             myKnife.life--;
             watermelon[i].isMissed = false;
        }
    }
    for(int i = 0; i < 5; i++){
        if(!trap[i].isFree && !trap[i].isDestroyed){
             /*
             if(getDistanceTAK(trap[i],myKnife)<20){
                 myKnife.life--;
                 trap[i].isDestroyed = true;
                 trap[i].bomb.x = trap[i].x;
                 trap[i].bomb.y = trap[i].y;
             }
             */
             if((trap[i].rectf).intersects(myKnife.rectf)){
                 myKnife.life--;
                 trap[i].isDestroyed = true;
                 trap[i].bomb.x = trap[i].x;
                 trap[i].bomb.y = trap[i].y;
             }
        }
    }
}

void game::endGame(){
    if(myKnife.life<=0 && !myKnife.isPlayed){
        myKnife.isPlayed = true;
        EndGame *end = new EndGame(Score);
        cout << myKnife.life;
        cout << myKnife.isPlayed;
        cout << winPlayed;
        end->show();
        this->close();
    }
}

int game::getDistanceAAK(Apple A, Kinfe K){
    return sqrt((A.x-10-K.x)*(A.x-10-K.x)+(A.y+10-K.y)*(A.y+10-K.y));
}

int game::getDistanceBAK(Banana B, Kinfe K){
    return sqrt((B.x-10-K.x)*(B.x-10-K.x)+(B.y+10-K.y)*(B.y+10-K.y));
}

int game::getDistanceWAK(Watermelon W, Kinfe K){
    return sqrt((W.x-10-K.x)*(W.x-10-K.x)+(W.y+10-K.y)*(W.y+10-K.y));
}

int game::getDistanceTAK(Trap T, Kinfe K){
    return sqrt((T.x-10-K.x)*(T.x-10-K.x)+(T.y+10-K.y)*(T.y+10-K.y));
}

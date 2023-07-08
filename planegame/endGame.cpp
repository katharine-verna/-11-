#include<endGame.h>
#include<QFont>
#include<config.h>
#include<QVBoxLayout>


endGame::endGame(int life,int num,QWidget* parent):QWidget(parent){
    setFixedSize(300,300);
    quit=new QPushButton("Quit");
    quit->setStyleSheet("QPushButton{background-image:url();}""QPushButton:hover{color:white;}");
    quit->setFont(QFont("宋体",16));

    Score=num;
    Life=life;
    score=new QLabel(this);
    score->setText(QString(SCO).arg(Score));
    score->setFont(QFont("幼圆",25));
    score->setStyleSheet("QLabel{background:transparent;color:white;}");

    ach=new QLabel(this);
    name=new QLabel(this);
    if(Life<=0){
        name->setText("LOSE ALL LIFE");
        name->setStyleSheet("QLabel{background:transparent;color:red;}");
        name->setFont(QFont("幼圆",25));

        QString str=QString(ACH).arg(0);
        QPixmap pixmap(str);
        ach->setPixmap(pixmap);
        ach->setScaledContents(true);
    }
    else{
        if(Score<=100){
            name->setText("头脑不太清醒……");
            name->setStyleSheet("QLabel{background:transparent;color:white;}");
            name->setFont(QFont("幼圆",16));

            QString str=QString(ACH).arg(1);
            QPixmap pixmap(str);
            ach->setPixmap(pixmap);
            ach->setScaledContents(true);
        }
        else if(Score<=300){
            name->setText("初级飞行员，大概是");
            name->setStyleSheet("QLabel{background:transparent;color:white;}");
            name->setFont(QFont("幼圆",16));

            QString str=QString(ACH).arg(2);
            QPixmap pixmap(str);
            ach->setPixmap(pixmap);
            ach->setScaledContents(true);
        }
        else if(Score<=500){
            name->setText("全部都可以打败！");
            name->setStyleSheet("QLabel{background:transparent;color:white;}");
            name->setFont(QFont("幼圆",16));

            QString str=QString(ACH).arg(3);
            QPixmap pixmap(str);
            ach->setPixmap(pixmap);
            ach->setScaledContents(true);
        }
    }
    QVBoxLayout* lay=new QVBoxLayout;
    lay->addWidget(score);
    lay->addWidget(ach);
    lay->addWidget(name);
    lay->addWidget(quit);
    setLayout(lay);

    setAutoFillBackground(true);
    QPalette pal;
    QPixmap pix(EndPic);
    pal.setBrush(QPalette::Window,QBrush(pix));
    setPalette(pal);

    connect(quit,&QPushButton::clicked,this,&endGame::quitClick);
}

void endGame::quitClick(){
    this->close();
}

endGame::~endGame(){

}

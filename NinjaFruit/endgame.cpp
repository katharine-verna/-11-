
#include "endgame.h"
#include<QVBoxLayout>
#include"game.h"

EndGame::EndGame(QWidget *parent)
    : QWidget{parent}
{

}

EndGame::EndGame(int x){
    resize(320,500);
    this->setWindowIcon(QIcon(":/new/prefix1/picturefruit/icon-1.png"));
    this->setWindowTitle("FruitNinja--End");
    Again = new QPushButton("Again");
    Return = new QPushButton("Return");
    Score = new QLabel(this);
    Score->setText(QString(SCORE).arg(x));
    Lose = new QLabel(this);
    Lose->setText("Game Over");
    Lose->setAlignment(Qt::AlignCenter);
    Again->setFont(QFont("Algerian",18));
    Again->setStyleSheet("QPushButton{background:transparent;color:white;}"
                         "QPushButton:hover{color:blue;}");
    Return->setFont(QFont("Algerian",18));
    Return->setStyleSheet("QPushButton{background:transparent;color:white;}"
                          "QPushButton:hover{color:blue;}");
    Score->setFont(QFont("Algerian",18));
    Score->setStyleSheet("QLabel{background:transparent;color:orange;}");
    Lose->setFont(QFont("Algerian",18));
    Lose->setStyleSheet("QLabel{background:transparent;color:white;}");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(Lose);
    layout->addWidget(Score);
    layout->addWidget(Again);
    layout->addWidget(Return);
    setLayout(layout);
    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/picturefruit/backgroundgreen1.jpg");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    setPalette(palette);

    connect(Again,&QPushButton::clicked,this,&EndGame::AgainClicked);
    connect(Return,&QPushButton::clicked,this,&EndGame::ReturnClicked);
}

EndGame::~EndGame(){

}

void EndGame::AgainClicked(){
    game *G = new game;
    G->show();
    this->close();
}

void EndGame::ReturnClicked(){
    this->close();
}

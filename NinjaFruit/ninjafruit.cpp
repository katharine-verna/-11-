
#include "ninjafruit.h"
#include "ui_ninjafruit.h"

#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPalette>
#include<QBrush>
#include<game.h>
#include<help.h>


NinjaFruit::NinjaFruit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NinjaFruit)
{
    ui->setupUi(this);
    resize(500,600);
    this->setWindowIcon(QIcon(":/new/prefix1/picturefruit/icon.png"));
    this->setWindowTitle("FruitNinja--start");
    startGame = new QPushButton("Start Game");
    startGame->setFont(QFont("Algerian",18));
    startGame->setStyleSheet("QPushButton{background:transparent;color:white;}"
                             "QPushButton:hover{color:red}");//设置QPushButton在普通状态下的样式和在鼠标悬停状态下的样式
    help = new QPushButton("Help");
    help->setFont(QFont("Algerian",18));
    help->setStyleSheet("QPushButton{background:transparent;color:white;}"
                        "QPushButton:hover{color:green}");//设置QPushButton在普通状态下的样式和在鼠标悬停状态下的样式
    quit = new QPushButton("Quit");
    quit->setFont(QFont("Algerian",18));
    quit->setStyleSheet("QPushButton{background:transparent;color:white;}"
                        "QPushButton:hover{color:yellow}");

    label = new QLabel(this);
    label->setText("                 Fruit Ninja");
    label->setFont(QFont("Algerian",24));
    label->setStyleSheet("QLabel{background:transparent;color:white;}");

    label2 = new QLabel(this);
    QPixmap pixmap1(":/new/prefix1/picturefruit/icon-3.png");
    pixmap1 = pixmap1.scaled(256,167,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    label2->setPixmap(pixmap1);
    label2->setAlignment(Qt::AlignCenter);

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(label);
    lay->addWidget(label2);
    lay->addWidget(startGame);
    lay->addWidget(help);
    lay->addWidget(quit);
    setLayout(lay);

    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap = QPixmap(":/new/prefix1/picturefruit/background.jpg").scaled(this->size());
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    setPalette(palette);

    connect(startGame,&QPushButton::clicked,this,&NinjaFruit::startClick);
    connect(quit,&QPushButton::clicked,this,&NinjaFruit::quitClick);
    connect(help,&QPushButton::clicked,this,&NinjaFruit::helpClick);
}

void NinjaFruit::startClick(){
    game *G = new game;
    G->show();
    this->close();
}

void NinjaFruit::quitClick(){
    emit ninjaEneded();
    this->close();
}

void NinjaFruit::helpClick(){
    Help *H = new Help;
    H->show();
}

NinjaFruit::~NinjaFruit()
{
    delete ui;
}



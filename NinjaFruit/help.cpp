
#include "help.h"
#include<QVBoxLayout>

Help::Help(QWidget *parent):
    QWidget(parent)
{
    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/picturefruit/background.jpg");
    resize(500,400);
    this->setWindowTitle("FruitNinja--Help");
    this->setWindowIcon(QIcon(":/new/prefix1/picturefruit/icon-3.png"));
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    setPalette(palette);

    label1 = new QLabel("                       FuiitNinja     ");
    label1->setFont(QFont("Algerian",20));
    label1->setStyleSheet("QLabel{background:transparent;color:white;}");

    label2 = new QLabel("本游戏为水果忍者的简单尝试");
    label2->setFont(QFont("楷体",18));
    label2->setStyleSheet("QLabel{background:transparent;color:white;}");

    label3 = new QLabel("在游戏中你可以通过鼠标拖拽移动刀片");
    label3->setFont(QFont("楷体",18));
    label3->setStyleSheet("QLabel{background:transparent;color:white;}");

    label4 = new QLabel("和经典游戏一样，切到水果会得分");
    label4->setFont(QFont("楷体",18));
    label4->setStyleSheet("QLabel{background:transparent;color:white;}");

    label5 = new QLabel("但遗漏或切到炸弹会使生命值降低");
    label5->setFont(QFont("楷体",18));
    label5->setStyleSheet("QLabel{background:transparent;color:white;}");

    label6 = new QLabel("      祝你好运      ");
    label6->setFont(QFont("楷体",18));
    label6->setStyleSheet("QLabel{background:transparent;color:white;}");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(label4);
    layout->addWidget(label5);
    layout->addWidget(label6);
    setLayout(layout);
}

Help::~Help(){

}

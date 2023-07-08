#include<config.h>
#include<helpwidget.h>
#include<QVBoxLayout>
#include<QPixmap>

HelpWidget::HelpWidget(QWidget* parent):QWidget(parent){
    setFixedSize(300,300);
    setAttribute(Qt::WA_DeleteOnClose,true);
    QPixmap pixmap(SHEET);
    QPalette pal;
    pal.setBrush(QPalette::Window,QPixmap(pixmap));
    setPalette(pal);

    label1=new QLabel(this);
    label1->setWordWrap(true);//自动换行
    label1->setFont(QFont("幼圆",20));
    label1->setText("Plane War游戏帮助");

    label2=new QLabel(this);
    label2->setWordWrap(true);
    label2->setText("鼠标拖动屏幕下方飞机，可以改变飞机位置，躲避子弹的攻击。"
                    "敌方普通飞机生命值为1，特殊飞机生命值为5，子弹和碰撞会使生命值减一。"
                    "当自己的生命值为零或者所有的敌方飞机已经出场时，游戏结束。");

    QVBoxLayout* lay=new QVBoxLayout;
    lay->addWidget(label1);
    lay->addWidget(label2);
    setLayout(lay);
}
HelpWidget::~HelpWidget(){

}

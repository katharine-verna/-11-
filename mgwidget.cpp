#include "mgwidget.h"
#include "ui_mgwidget.h"

MGWidget::MGWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MGWidget)
{
    ui->setupUi(this);
}

MGWidget::~MGWidget()
{
    delete ui;
}

void MGWidget::keyPressEvent(QKeyEvent *event)
{


    switch(event->key()){//添加对应按键组合
       case Qt::Key_S:
       case Qt::Key_D:
       case Qt::Key_J:
       case Qt::Key_K:
           mKeyList.append(event->key());
           break;
       }

}

void MGWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(mKeyList.contains(event->key())){//移除对应按键组合
            mKeyList.removeOne(event->key());
        }
}


#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<plane.h>
#include<QPainter>
#include<QPaintEvent>
#include<QIcon>
#include<bullet.h>
#include<bomb.h>
#include<QPalette>
#include<config.h>
#include<enemyplane1.h>
#include<enemyplane2.h>
#include<QTimer>
#include<QBrush>
#include<QMouseEvent>
#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include "planegame_global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class PLANEGAME_EXPORT MyWidget : public QWidget

{
    Q_OBJECT

public slots:
    void startClick();
    void helpClick();
    void quitClick();

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    QPushButton* startGame;//按钮
    QPushButton* Help;
    QPushButton* quit;
    QLabel* label;//图片

private:
    Ui::MyWidget *ui;

signals:
    void quitClickSignal();
};


#endif // MYWIDGET_H

#include "widget.h"
#include "ui_widget.h"
#include "mainscene.h"
#include "mywidget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{




}

Widget::~Widget()
{
    delete ui;
}


#ifndef HELP_H
#define HELP_H

#include<QWidget>
#include<QLabel>
#include<QPixmap>
#include<QPalette>
#include <QIcon>


class Help:public QWidget
{
    Q_OBJECT
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLabel *label8;
    QLabel *label9;
    QLabel *label10;
    QLabel *label11;
public:
    explicit Help(QWidget *parent = 0);
    ~Help();
};

#endif // HELP_H

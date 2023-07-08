
#ifndef HELPWIDGET_H
#define HELPWIDGET_H
#include<config.h>
#include<QPushButton>
#include<QLabel>

class HelpWidget:public QWidget{
    Q_OBJECT
public:
    QLabel* label1;
    QLabel* label2;
    HelpWidget(QWidget* parent=nullptr);
    ~HelpWidget();
};

#endif // HELPWIDGET_H

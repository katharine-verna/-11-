#include "gamehelp.h"
#include "ui_gamehelp.h"



gamehelp::gamehelp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamehelp)
{
    ui->setupUi(this);
    connect(ui->helpexitButton,&QPushButton::clicked,[=]
    {
        this->hide();
    });
//    setWindowIcon(QIcon());
}

gamehelp::~gamehelp()
{
    delete ui;
}

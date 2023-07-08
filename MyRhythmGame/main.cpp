
#include "gamecontrol.h"
#include "widget.h"
#include <QApplication>



void MG_main(int argc, char *argv[])
{



 //   QApplication a(argc, argv);
    Widget w;
    //PushButton样式读取
    QFile stylefile(GameDefine::PushButtonStyle);
    stylefile.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(stylefile.readAll());
    a.setStyleSheet(styleSheet);
    stylefile.close();

    GameControl::Instance()->setParent(&w);
    GameControl::Instance()->GameInit();

    //退出按钮直接退出
    QObject::connect(GameControl::Instance()->Quit,SIGNAL(clicked()),&w,SLOT(close()));

    w.show();

}

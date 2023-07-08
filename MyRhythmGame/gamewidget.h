#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "autoresize.h"
#include "gamedefine.h"
#include "myrhythmgame_global.h"



namespace Ui {
class GameWidget;
}

class MYRHYTHMGAME6_0_EXPORT GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

private:
    Ui::GameWidget *ui;

public:
    QList<int> mKeyList;

    void MG_main(int argc, char *argv[]);//

public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
private:
    AutoResize *m_autoResizeHandler;


signals:
    void RhyGameQuit();

};

#endif // WIDGET_H







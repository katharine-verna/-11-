#ifndef MGWIDGET_H
#define MGWIDGET_H

#include <QWidget>
#include "autoresize.h"
#include "gamedefine.h"

namespace Ui {
class MGWidget;
}

class MGWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MGWidget(QWidget *parent = 0);
    ~MGWidget();

private:
    Ui::MGWidget *ui;



public:
    QList<int> mKeyList;

public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
private:
    AutoResize *m_autoResizeHandler;

signals:

};


#endif // MGWIDGET_H

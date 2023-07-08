#ifndef GAMEHELP_H
#define GAMEHELP_H

#include <QWidget>

namespace Ui {
class gamehelp;
}

class gamehelp : public QWidget
{
    Q_OBJECT

public:
    explicit gamehelp(QWidget *parent = 0);
    ~gamehelp();

private:
    Ui::gamehelp *ui;
};

#endif // GAMEHELP_H

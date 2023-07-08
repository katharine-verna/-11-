#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QWidget>
#include<QImage>
#include<QDialog>
#include<QTimer>
#include<QObject>

#include<QLabel>

class ImageDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ImageDialog(QWidget *parent = nullptr);

    void addImage(const QString& image);

    void setInterval(int interval);

    void start(){isRunning=true;timer->start();}

    void stop(){isRunning=false;}


signals:

    void playFinished();

public slots:

 private:

    QTimer* timer=nullptr;

    int interval=100;

    QVector<QString> images;
    int             currentIndex=0;

    bool isRunning=false;
public:
    QLabel* label=nullptr;
    QLabel* label_t=nullptr;

};

#endif // IMAGEDIALOG_H

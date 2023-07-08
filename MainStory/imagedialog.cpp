#include "imagedialog.h"
#include<QDialog>
#include<QTimer>
#include<QLabel>
#include<QHBoxLayout>
#include<QFile>
#include<QDebug>
#include<QFont>
ImageDialog::ImageDialog(QWidget *parent) : QDialog(parent)
{


   resize(500,500);
   timer=new QTimer(this);
   label=new QLabel(this);
//   label_t=new QLabel(this);
//   QFont font("楷体", 18);
//   label_t->setFont(font);
//   label_t->setText("什么东西");
//   label_t->move(0, 400); // 设置标签的位置

   connect(timer,&QTimer::timeout,this,[=](){
       qDebug()<<"timeout";

       if(!isRunning){
           timer->stop();
           return;
       }
       currentIndex++;
       if(!(currentIndex<images.size())){
           isRunning=false;
           timer->stop();
           currentIndex=0;
           emit playFinished();
           return;
       }
       QFile file{images[currentIndex]};
       file.open(QIODevice::ReadOnly);

       QImage image=QImage::fromData(file.readAll());
       label->setPixmap(QPixmap::fromImage(image));
   });



   QHBoxLayout* layout=new QHBoxLayout(this);

   layout->addWidget(label);
   this->setLayout(layout);

}


void ImageDialog::addImage(const QString& image ){
    this->images.push_back(image);
}


void ImageDialog::setInterval(int interval){
    this->interval=interval;
    timer->setInterval(interval);
}




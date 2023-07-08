
#ifndef NOTE_H
#define NOTE_H


#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QAudioOutput>

class Note : public QGraphicsPixmapItem
{
public:
    explicit Note();

    void setNote(int track,double beatnum,double BPM);
    //轨道、第几拍、BPM
    void setSpeed(double speed);//设置速度
    void setparent(QGraphicsScene *Scene);//设置场景
    void deleteScene(QGraphicsScene *Scene);//从场景中删除
    void PlaySoundEffects();

    bool getStatus();
    void setStatus(bool judge);
    int getTrack();

protected:
    double speed;//下落速度
    int track;//轨道：1、2、3、4--S、D、J、K键位
    double beatnum;//第几拍下落的音符：第1拍、第4.5拍
    bool status = false;//是否被判定过了(是否删除)
    float soundVolume;

    QMediaPlayer *SoundEffects;
    QAudioOutput *SEOutput;
signals:

};

#endif // NOTE_H

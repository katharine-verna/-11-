
#include "note.h"
#include "qgraphicsscene.h"

Note::Note()
{

}

void Note::setNote(int track,double beatnum,double BPM){
    this->setPixmap(QPixmap(":/img/Note.png"));
    this->setPos(220+80*track,-40-(beatnum - 1)*60000/BPM);
    this->track = track;
    SoundEffects = new QMediaPlayer;
    SoundEffects->setMedia(QUrl("qrc:/audio/HitSoundEffect.wav"));
//    SEOutput = new QAudioOutput;
//    SEOutput->setVolume(1);
//    SoundEffects->setAudioOutput(SEOutput);
}

void Note::setSpeed(double speed)
{
    this->speed = speed;
}

void Note::setparent(QGraphicsScene *Scene)
{
    Scene->addItem(this);
}

void Note::deleteScene(QGraphicsScene *Scene)
{
    Scene->removeItem(this);
    //delete SoundEffects;
}

void Note::PlaySoundEffects()
{
    SoundEffects->play();
}

bool Note::getStatus()
{
    return status;
}

void Note::setStatus(bool judge)
{
    status = judge;
}

int Note::getTrack()
{
    return track;
}



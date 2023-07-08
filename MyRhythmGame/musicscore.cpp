
#include "musicscore.h"
#include "gamedefine.h"
#include <QFile>
#include <QDebug>

MusicScore::MusicScore(QWidget *parent)
    : QWidget{parent}
{
    notenum = 0;
    holdnum = 0;
    Snum = 0;
    beatnum = 0;
    speed = 5;
    points = 0;
    ComboNum = 0;
    MaxComboNum = 0;
    PerfectNum = 0;
    GoodNum = 0;
    BadNum = 0;
    MissNum = 0;
    acc = 0;
    MusicTime = 0;
    Notelist = nullptr;
    BGMPlayer = nullptr;
}

bool MusicScore::InitByFile(QString fileName)
{
    QFile file(fileName);//创建文件对象
    if(!file.open(QIODevice::ReadOnly)){
        return false;//打开失败
    }
    //读取所有内容
    QByteArray arrALL = file.readAll();
    arrALL.replace("\r\n","\n");
    QList<QByteArray> lineList = arrALL.split('\n');
    Snum = lineList.size() - 1;//除去第一行
    for(int i = 0;i <= Snum;i++){
        QList<QByteArray> colList = lineList[i].split(',');
        if(i == 0){
            name = colList[0];//名字
            level = colList[1].toInt();//难度
            BackGround = colList[2];//背景图片地址
            BPM = colList[3].toDouble();//BPM
            notenum = colList[4].toInt();//note数量
            holdnum = colList[5].toInt();//hold数量
            Notelist = new Note[notenum];
            //这里以后加上hold的定义
            Music = colList[6];//音乐地址
            BGMPlayer = new QMediaPlayer;
            BGMPlayer->setMedia(QUrl::fromLocalFile(Music));
            BGMPlayer->setVolume(GameDefine::MSBGMVolume);
//            BGMOutput = new QAudioOutput;
//            BGMOutput->setVolume(0.3);
//            BGMPlayer->setAudioOutput(BGMOutput);
            MusicLenth = colList[7].toInt();//时长
        }
        else{//i>=1
            if(colList[0].toInt() == 1){//如果是note
                if(colList[2].toInt() == 0){//如果不双压
                    beatnum += colList[3].toDouble();
                }
                Notelist[i - 1].setNote(colList[1].toInt(),beatnum,BPM);
            }//文件顺序:类型、track、bool双压、duration
            //else if(coList[0].toInt() == 2) //后面实现hold
        }
    }
    file.close();
    return true;
}

void MusicScore::setparent(QGraphicsScene *Scene)
{
    for(int i = 0;i < notenum;i++){
        Notelist[i].setparent(Scene);
    }
}

void MusicScore::notesMove(int distance)
{
    for(int i = 0;i < notenum;i++){
        Notelist[i].moveBy(0,distance);
    }
}

int MusicScore::JudgeStatus(int track,QGraphicsScene *Scene)
{
    for(int i = 0;i < notenum;i++){
        if(!Notelist[i].getStatus()){//首先对象没有删除
            if(Notelist[i].getTrack() == track){//其次轨道必须相同
                qreal ju = 550 - Notelist[i].y();
                if(abs(ju)<= 5 * speed){//Perfect判定 50ms
                    Notelist[i].PlaySoundEffects();//播放音效
                    Notelist[i].setStatus(true);//已经判定过，删除
                    Notelist[i].deleteScene(Scene);
                    ComboNum++;//连击数+1
                    PerfectNum++;
                    MaxComboNum = std::max(ComboNum,MaxComboNum);
                    return 1;
                }
                else if(abs(ju)> 5 * speed && abs(ju)<= 10 * speed){//Good判定 100ms
                    Notelist[i].PlaySoundEffects();//播放音效
                    Notelist[i].setStatus(true);//已经判定过，删除
                    Notelist[i].deleteScene(Scene);
                    ComboNum++;//连击数+1
                    GoodNum++;
                    MaxComboNum = std::max(ComboNum,MaxComboNum);
                    return 2;
                }
                else if(ju > 10 * speed && ju<= 15 * speed){//Bad判定 100~150ms
                    Notelist[i].setStatus(true);//已经判定过，删除
                    Notelist[i].deleteScene(Scene);
                    ComboNum = 0;//连击中断
                    BadNum++;
                    return 3;
                }
                else if(ju < -10 * speed){//Miss判定 100ms以上
                    Notelist[i].setStatus(true);//已经判定过，删除
                    Notelist[i].deleteScene(Scene);
                    ComboNum = 0;//连击中断
                    MissNum++;
                    return 4;
                }
            }
        }
    }
    return 0;//空判定
}

void MusicScore::setSpeed(int speed)
{
    this->speed = speed;
}

void MusicScore::JudgeBorder(QGraphicsScene *Scene)
{
    for(int i = 0;i < notenum;i++){
        if(!Notelist[i].getStatus()){//首先对象没有删除
            if(Notelist[i].y()>600){
                Notelist[i].setStatus(true);//已经判定过，删除
                Notelist[i].deleteScene(Scene);
                ComboNum = 0;//连击中断
                MissNum++;
                status = 4;
            }
        }
    }
}

void MusicScore::CalculatePoints()
{
    points = ((PerfectNum+0.65*GoodNum)*900000+MaxComboNum*100000)/Snum;
    acc = (PerfectNum+0.65*GoodNum)/Snum;

}

void MusicScore::JudgeRank()
{
    if(points < 700000){
        Rank = ":/img/F.png";
    }
    else if(points >= 700000&&points<820000){
        Rank = ":/img/C.png";
    }
    else if(points >= 820000&&points<880000){
        Rank = ":/img/B.png";
    }
    else if(points >= 880000&&points<920000){
        Rank = ":/img/A.png";
    }
    else if(points >= 920000&&points<960000){
        Rank = ":/img/S.png";
    }
    else if(points >= 960000&&points<1000000){
        Rank = ":/img/V.png";
    }
    else if(points == 1000000){
        Rank = ":/img/phi.png";
    }
}

void MusicScore::updateMusicTime()
{
    MusicTime++;
}

QString MusicScore::getBackGround()
{
    return BackGround;
}

QString MusicScore::getName()
{
    return name;
}

QString MusicScore::getRank()
{
    return Rank;
}

int MusicScore::getPoints()
{
    return points;
}

int MusicScore::getLevel()
{
    return level;
}

int MusicScore::getComboNum()
{
    return ComboNum;
}

int MusicScore::getMusicLenth()
{
    return MusicLenth;
}

int MusicScore::getSpeed()
{
    return speed;
}

int MusicScore::getPerfectNum()
{
    return PerfectNum;
}

int MusicScore::getGoodNum()
{
    return GoodNum;
}

int MusicScore::getBadNum()
{
    return BadNum;
}

int MusicScore::getMissNum()
{
    return MissNum;
}

int MusicScore::getStatus()
{
    return status;
}

void MusicScore::setStatus(int newstatus)
{
    status = newstatus;
}

int MusicScore::getMaxComboNum()
{
    return MaxComboNum;
}

int MusicScore::getMusicTime()
{
    return MusicTime;
}

double MusicScore::getAcc()
{
    return acc;
}


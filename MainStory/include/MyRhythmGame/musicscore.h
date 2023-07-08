
#ifndef MUSICSCORE_H
#define MUSICSCORE_H


#include <QWidget>
#include "note.h"


class MusicScore : public QWidget
{
    Q_OBJECT
public:
    explicit MusicScore(QWidget *parent = nullptr);

    bool InitByFile(QString filename);//实现文件读取
    void setparent(QGraphicsScene *Scene);//设置场景
    void notesMove(int distance);//note移动函数
    int JudgeStatus(int track,QGraphicsScene *Scene);//判定
    void setSpeed(int speed);//设置速度
    void JudgeBorder(QGraphicsScene *Scene);
    void CalculatePoints();
    void JudgeRank();
    void updateMusicTime();//实时更新乐谱时间

    QString getBackGround();
    QString getName();
    QString getRank();
    int getPoints();
    int getLevel();
    int getComboNum();
    int getMusicLenth();
    int getSpeed();
    int getPerfectNum();
    int getGoodNum();
    int getBadNum();
    int getMissNum();
    int getStatus();
    void setStatus(int newstatus);
    int getMaxComboNum();
    int getMusicTime();
    double getAcc();


    QMediaPlayer *BGMPlayer;//背景音乐播放器
    //QAudioOutput *BGMOutput;

protected:
    Note *Notelist;//Note类数组，存储Note类信息

    QString name;//谱面名称
    QString BackGround;//背景地址
    QString Music;//音乐地址
    QString Rank;//评级


    int notenum;//Note的总个数（不包括hold）
    int holdnum;//Hold的总个数
    int Snum;//总个数
    int level;//难度
    double beatnum;//第几拍下落的音符：第1拍、第4.5拍
    double BPM;
    double acc;//准度
    int speed;//速度
    int status;//表示状态：1、2、3、4——P、G、B、M
    int points;//分数
    int ComboNum;//连击数
    int MaxComboNum;//最大连击数
    int PerfectNum;//P的个数
    int GoodNum ;//G的个数
    int BadNum ;//B的个数
    int MissNum;//M的个数
    int MusicLenth;//音乐的长度(单位ms)
    int MusicTime;//音乐的实时播放时间

signals:

};

#endif // MUSICSCORE_H

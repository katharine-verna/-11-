#ifndef GAMEDEFINE_H
#define GAMEDEFINE_H
#include <QGraphicsPixmapItem>//图形元素
#include <QGraphicsView>//视图
#include <QGraphicsScene>//场景
#include <QRect>
#include <QColor>
#include <QGraphicsTextItem>
#include <QString>
#include <QDebug>
#include <QGraphicsBlurEffect>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QTimer>
#include <QToolButton>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QUrl>
#include <QFile>
#include <QKeyEvent>




//游戏定义类 定义游戏相关属性
class GameDefine
{
public:
    GameDefine();

    static const int MSTime = 10;//谱面计时器初始化值
    static const int MSDelay = 2420;//谱面延时初始化值（原来的mDelay）
    static const int Delay = 3000;//缓冲事件（原来的BGMDelay）
    static const int DetectKeyTime = 3;//按键检测计时器初始化值
    static const int Border = 3;//边界判定计时器初始化值
    static const int EndDelay = 3000;//结算界面计时器初始化值

    static QString MSAddress;//谱面地址
    static QString PushButtonStyle;//PushButton样式地址

    //屏幕宽高
    static const int ScreenWidth = 800;//宽
    static const int ScreenHeight = 600;//高

    //游戏音量
    static float MSBGMVolume;//谱面BGM音量
    static float EndBGMVolume;//结算界面BGM音量
    static float HitSoundEffectVolume;//打击音量

};

#endif // GAMEDEFINE_H

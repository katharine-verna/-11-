
#ifndef CONFIG_H
#define CONFIG_H

#define GAME_HEIGHT 800   //游戏高度
#define GAME_WIDTH 500   //游戏宽度
#define GAME_TITLE "飞机大战"
#define GAME_RES_PATH "./plane.rcc"  //rcc文件路径
#define GAME_ICON ":/res/app.ico"
#define GAME_RATE 10  //定时器刷新间隔10ms
#define GAME_BACK ":/res/background.png"

#define PLANE_PATH ":/res/myplane.png"
#define ENEMY1_PATH ":/res/enemyplane1.png"
#define ENEMY2_PATH ":/res/enemyplane2.png"
#define ENEMY_SPEED 2  //移动速度
#define ENEMY1_INTERVAL 150  //出场间隔
#define ENEMY2_INTERVAL 500
#define ENEMY1_NUM 30
#define ENEMY2_NUM 10

#define BULLET_PATH ":/res/mybullet.png"
#define EBULLET1_PATH ":/res/enemybullet.png"
#define EBULLET2_PATH ":/res/enemybullet2.png"
#define BULLET_SPEED 5  //子弹移动速度
#define BULLET_NUM 30  //弹匣中子弹的数量
#define BULLET_INTERVAL1 30  //子弹发射间隔
#define BULLET_INTERVAL2 80

#define BOMB_PATH ":/res/bomb-%1.png"  //爆炸图片数组
#define BOMB_NUM 12
#define BOMB_MAX 7
#define BOMB_INTERVAL 10  //切换图片时间

#define ACH ":/res/ach-%1.png"  //成就图片
#define EndPic ":/res/EndPic.png"  //结束界面图片
#define SHEET ":/res/sheet.png"  //开始和help界面背景


#endif // CONFIG_H

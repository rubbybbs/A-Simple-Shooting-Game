#pragma once

#pragma region 头文件引用

// Windows 头文件: 
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")


// TODO:  在此处引用程序需要的其他头文件
#include <vector>
#include <math.h>


#pragma endregion


#pragma region 宏定义

#define WINDOW_WIDTH			1280		//游戏窗口宽度
#define WINDOW_HEIGHT			960		//游戏窗口高度
#define WINDOW_TITLEBARHEIGHT	32		//标题栏高度

#define STAGE_STARTMENU			0		//开始画面的ID
#define STAGE_1					1		//第一个游戏场景的ID
#define STAGE_2					2		//第二个游戏场景的ID
#define STAGE_HELP				5		//帮助画面的ID


#define HERO_SIZE_X				32		//主角的宽度
#define HERO_SIZE_Y				32		//主角的高度
#define HERO_FRAME_NUMBER		12		//主角的动画帧数量
#define HERO_ACCELERATION		0.3		//主角加速度
#define HERO_MAXSPEED			6.0		//主角最大速度

#define BulletHero_SIZE_X		16		//主角子弹的宽度
#define BulletHero_SIZE_Y		16		//主角子弹的高度
#define	BulletHero_FRAME_NUMBER	12		//主角子弹的动画帧数量
#define BulletHero_SPEED		5.0		//主角子弹的速度

#define ENEMY_SIZE_X			32		//小兵的宽度
#define ENEMY_SIZE_Y			32		//小兵的高度
#define ENEMY_SPEED				3.0		//小兵的速度
#define BulletEnemy_SIZE_X		16		//小兵子弹的宽度
#define BulletEnemy_SIZE_X		16		//小兵子弹的高度

#define BUTTON_STARTGAME			1001	//开始游戏按钮ID
#define BUTTON_PAUSE				1002	//暂停游戏按钮ID
#define BUTTON_BACK					1003	//返回游戏按钮ID
#define BUTTON_EXIT					1004	//退出游戏按钮ID
#define BUTTON_HELP					1005	//帮助游戏按钮ID
#define BUTTON_MAINMENU				1006	//主菜单游戏按钮ID
#define BUTTON_RESTART				1007	//重新开始游戏按钮ID
#define BUTTON_STAGE1				1008	//第一关按钮ID
#define BUTTON_STAGE2				1009	//第二关按钮ID
#define BUTTON_STAGEBACK			1010	//选关返回按钮ID
#define BUTTON_STARTGAME_WIDTH		371	//开始游戏按钮宽度
#define BUTTON_STARTGAME_HEIGHT		117		//开始游戏按钮高度


#define TIMER_GAMETIMER				1	//游戏的默认计时器ID
#define TIMER_HEROBULLETTIMER		2	//主角子弹的默认计时器ID
#define TIMER_ENEMYBULLETTIMER		3	//小兵子弹的默认计时器ID
#define TIMER_ENEMYRATETIMER		4	//小兵刷新率计时器ID
#define TIMER_BOSSBULLETIMER		5	//BOSS弹幕默认计时器ID
#define TIMER_BOSSBORNTIMER			6	//BOSS出现默认计时器ID
#define TIMER_HEROIVCIBLETIMER		7	//主角无敌时间计时器ID
#define TIMER_ELITERATETIMER		8	//精英刷新率计时器ID
#define TIMER_ELITEBULLETTIMER		9	//精英子弹计时器ID
#define TIMER_BOSSIVCIBLETIMER		10	//BOSS无敌时间计时器ID
#define TIMER_BOSSBSTOPTIMER		11	//BOSS子弹停滞计时器ID
#define TIMER_HEROSKILLTIMER		12	//主角技能冷却计时器ID
#define TIMER_HEROSKILL2TIMER       13	//主角技能2冷却计时器ID
#define TIMER_BOSSBORNANIMETIMER	14	//BOSS出生动画计时器
#define TIMER_BOSSBORNAGAPTIMER		15	//BOSS出生动画播放间隔计时器
#define TIMER_WINLOSETIMER			16	//输赢计时器ID

#define TIMER_GAMETIMER_ELAPSE		10	//默认计时器刷新间隔的毫秒数


#pragma endregion


#pragma region 结构体声明

// 场景结构体
struct Stage
{
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）
	int maxEnmyNum;		//最大同屏敌人数

};


// 按钮结构体
struct Button
{
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度
};

// 主角结构体
struct Hero
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	double x0;
	double y0;
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值
	bool exist;		//是否存活
	bool wudi;		//是否无敌
};

//子弹(主角)结构体
struct BulletHero
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	double x0;		//精确坐标x
	double y0;		//精确坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	double vx;		//速度x
	double vy;		//速度y
	double cx;		//方向系数x
	double sy;		//方向系数y
	int damage;		//伤害值
	bool exist;
};

//小兵结构体
struct Enemy
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	double x0;
	double y0;
	int x;			//坐标x
	int y;			//坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	double vx;		//速度x
	double vy;		//速度y
	double cx;		//方向系数x
	double sy;		//方向系数y
	int health;		//生命值
	bool exist;
	bool elite;
};

//小兵弹幕结构体
struct EnemyBullet
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	double x0;		//精确坐标x
	double y0;		//精确坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	double vx;		//速度x
	double vy;		//速度y
	double cx;		//方向系数x
	double sy;		//方向系数y
	int damage;		//伤害值
	bool exist;
};

//精英弹幕结构体
struct EliteBullet
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	double x0;		//精确坐标x
	double y0;		//精确坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	double vx;		//速度x
	double vy;		//速度y
	double cx;		//方向系数x
	double sy;		//方向系数y
	int damage;		//伤害值
	bool exist;
};

//Boss结构体
struct Boss
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	double x0;		//精确坐标x
	double y0;		//精确坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	double vx;		//速度x
	double vy;		//速度y
	double cx;		//速度横向系数x
	double sy;		//速度纵向系数y
	int health;		//生命值
	bool exist;
	int stage;		//第几关的?
	bool wudi;		//是否无敌
};

//Boss弹幕结构体
struct BossBullet
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	double x0;		//精确坐标x
	double y0;		//精确坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	double vx;		//速度x
	double vy;		//速度y
	double cx;		//方向系数x
	double sy;		//方向系数y
	int damage;		//伤害值
	bool enable;	//是否可被破坏
};


//砖块（可破坏）结构体
struct BlockY
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	int health;		//生命值
	bool SGL;		//是否陷阱
};

//砖块（不可破坏）结构体
struct BlockN
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int cenx;		//中心坐标x
	int ceny;		//中心坐标y
	bool trap;
};

//生命值结构体
struct Health
{
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	bool exist;
};


//TODO: 添加游戏需要的更多种数据（子弹、砖块、敌人、弹幕等）


#pragma endregion


#pragma region 事件处理函数声明


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region 其它游戏状态处理函数声明

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// 添加主角函数
Hero* CreateHero(HBITMAP img, int x, int y, int health, HWND hWnd);

//添加小兵函数
Enemy* CreateEnemy(HBITMAP img, int x, int y, int health, bool elite, HWND hWnd);

//添加Boss函数
Boss* CreateBoss(HBITMAP img, int x, int y, int health, int stage, HWND hWnd);

//添加砖块(可破坏)函数
void CreateBlockY(HBITMAP img, int health, bool sgl,  HWND hWnd);

//添加砖块(不可破坏)函数
void CreateBlockN(HBITMAP img, bool trap, HWND hWnd);

//添加主角子弹函数
void CreateHeroBullet(HWND hWnd);

//添加小兵子弹函数
void CreateBulletEnemy(HWND hWnd);

//添加Boss弹幕函数
void CreateBulletBoss(HWND hWnd);

//添加精英子弹函数
void CreateBulletElite(HWND hWnd);

// 初始化场景函数
void InitStage(HWND hWnd, int stageID);

// 刷新主角状态函数
void UpdateHero(HWND hWnd);

// 计算主角的当前帧数
int GetHeroFrame(double dirX, double dirY);

//刷新主角子弹状态函数
void UpdateBulletHero(HWND hWnd);

//刷新小兵状态函数
void UpdateEnemy(HWND hWnd);

//刷新小兵弹幕状态函数
void UpdateBulletEnemy(HWND hWnd);

//刷新精英弹幕状态函数
void UpdateBulletElite(HWND hWnd);

//刷新Boss状态函数
void UpdateBoss(HWND hWnd);

//刷新Boss弹幕状态函数
void UpdateBulletBoss(HWND hWnd);

//计算距离平方函数
int caudis(int cenx1, int cenx2, int ceny1, int ceny2);

//TODO: 添加游戏需要的更多函数

#pragma endregion


#pragma region 绘图函数声明

// 绘图函数
void Paint(HWND hWnd);

#pragma endregion
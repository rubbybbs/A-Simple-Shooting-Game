#pragma once

#pragma region ͷ�ļ�����

// Windows ͷ�ļ�: 
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// ��Դͷ�ļ�
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <vector>
#include <math.h>


#pragma endregion


#pragma region �궨��

#define WINDOW_WIDTH			1280		//��Ϸ���ڿ��
#define WINDOW_HEIGHT			960		//��Ϸ���ڸ߶�
#define WINDOW_TITLEBARHEIGHT	32		//�������߶�

#define STAGE_STARTMENU			0		//��ʼ�����ID
#define STAGE_1					1		//��һ����Ϸ������ID
#define STAGE_2					2		//�ڶ�����Ϸ������ID
#define STAGE_HELP				5		//���������ID


#define HERO_SIZE_X				32		//���ǵĿ��
#define HERO_SIZE_Y				32		//���ǵĸ߶�
#define HERO_FRAME_NUMBER		12		//���ǵĶ���֡����
#define HERO_ACCELERATION		0.3		//���Ǽ��ٶ�
#define HERO_MAXSPEED			6.0		//��������ٶ�

#define BulletHero_SIZE_X		16		//�����ӵ��Ŀ��
#define BulletHero_SIZE_Y		16		//�����ӵ��ĸ߶�
#define	BulletHero_FRAME_NUMBER	12		//�����ӵ��Ķ���֡����
#define BulletHero_SPEED		5.0		//�����ӵ����ٶ�

#define ENEMY_SIZE_X			32		//С���Ŀ��
#define ENEMY_SIZE_Y			32		//С���ĸ߶�
#define ENEMY_SPEED				3.0		//С�����ٶ�
#define BulletEnemy_SIZE_X		16		//С���ӵ��Ŀ��
#define BulletEnemy_SIZE_X		16		//С���ӵ��ĸ߶�

#define BUTTON_STARTGAME			1001	//��ʼ��Ϸ��ťID
#define BUTTON_PAUSE				1002	//��ͣ��Ϸ��ťID
#define BUTTON_BACK					1003	//������Ϸ��ťID
#define BUTTON_EXIT					1004	//�˳���Ϸ��ťID
#define BUTTON_HELP					1005	//������Ϸ��ťID
#define BUTTON_MAINMENU				1006	//���˵���Ϸ��ťID
#define BUTTON_RESTART				1007	//���¿�ʼ��Ϸ��ťID
#define BUTTON_STAGE1				1008	//��һ�ذ�ťID
#define BUTTON_STAGE2				1009	//�ڶ��ذ�ťID
#define BUTTON_STAGEBACK			1010	//ѡ�ط��ذ�ťID
#define BUTTON_STARTGAME_WIDTH		371	//��ʼ��Ϸ��ť���
#define BUTTON_STARTGAME_HEIGHT		117		//��ʼ��Ϸ��ť�߶�


#define TIMER_GAMETIMER				1	//��Ϸ��Ĭ�ϼ�ʱ��ID
#define TIMER_HEROBULLETTIMER		2	//�����ӵ���Ĭ�ϼ�ʱ��ID
#define TIMER_ENEMYBULLETTIMER		3	//С���ӵ���Ĭ�ϼ�ʱ��ID
#define TIMER_ENEMYRATETIMER		4	//С��ˢ���ʼ�ʱ��ID
#define TIMER_BOSSBULLETIMER		5	//BOSS��ĻĬ�ϼ�ʱ��ID
#define TIMER_BOSSBORNTIMER			6	//BOSS����Ĭ�ϼ�ʱ��ID
#define TIMER_HEROIVCIBLETIMER		7	//�����޵�ʱ���ʱ��ID
#define TIMER_ELITERATETIMER		8	//��Ӣˢ���ʼ�ʱ��ID
#define TIMER_ELITEBULLETTIMER		9	//��Ӣ�ӵ���ʱ��ID
#define TIMER_BOSSIVCIBLETIMER		10	//BOSS�޵�ʱ���ʱ��ID
#define TIMER_BOSSBSTOPTIMER		11	//BOSS�ӵ�ͣ�ͼ�ʱ��ID
#define TIMER_HEROSKILLTIMER		12	//���Ǽ�����ȴ��ʱ��ID
#define TIMER_HEROSKILL2TIMER       13	//���Ǽ���2��ȴ��ʱ��ID
#define TIMER_BOSSBORNANIMETIMER	14	//BOSS����������ʱ��
#define TIMER_BOSSBORNAGAPTIMER		15	//BOSS�����������ż����ʱ��
#define TIMER_WINLOSETIMER			16	//��Ӯ��ʱ��ID

#define TIMER_GAMETIMER_ELAPSE		10	//Ĭ�ϼ�ʱ��ˢ�¼���ĺ�����


#pragma endregion


#pragma region �ṹ������

// �����ṹ��
struct Stage
{
	int stageID;		//�������
	HBITMAP bg;			//����ͼƬ
	int timeCountDown;	//��Ϸʱ�䵹��ʱ
	bool timerOn;		//��ʱ���Ƿ����У���Ϸ�Ƿ���ͣ��
	int maxEnmyNum;		//���ͬ��������

};


// ��ť�ṹ��
struct Button
{
	int buttonID;	//��ť���
	bool visible;	//��ť�Ƿ�ɼ�
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	int width;		//���
	int height;		//�߶�
};

// ���ǽṹ��
struct Hero
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	int cenx;		//��������x
	int ceny;		//��������y
	double x0;
	double y0;
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	int health;		//����ֵ
	bool exist;		//�Ƿ���
	bool wudi;		//�Ƿ��޵�
};

//�ӵ�(����)�ṹ��
struct BulletHero
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	double x0;		//��ȷ����x
	double y0;		//��ȷ����y
	int cenx;		//��������x
	int ceny;		//��������y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	double cx;		//����ϵ��x
	double sy;		//����ϵ��y
	int damage;		//�˺�ֵ
	bool exist;
};

//С���ṹ��
struct Enemy
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	double x0;
	double y0;
	int x;			//����x
	int y;			//����y
	int cenx;		//��������x
	int ceny;		//��������y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	double cx;		//����ϵ��x
	double sy;		//����ϵ��y
	int health;		//����ֵ
	bool exist;
	bool elite;
};

//С����Ļ�ṹ��
struct EnemyBullet
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	double x0;		//��ȷ����x
	double y0;		//��ȷ����y
	int cenx;		//��������x
	int ceny;		//��������y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	double cx;		//����ϵ��x
	double sy;		//����ϵ��y
	int damage;		//�˺�ֵ
	bool exist;
};

//��Ӣ��Ļ�ṹ��
struct EliteBullet
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	double x0;		//��ȷ����x
	double y0;		//��ȷ����y
	int cenx;		//��������x
	int ceny;		//��������y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	double cx;		//����ϵ��x
	double sy;		//����ϵ��y
	int damage;		//�˺�ֵ
	bool exist;
};

//Boss�ṹ��
struct Boss
{
	HBITMAP img;	//ͼƬ
	int frame;		//��ǰ��ʾ��֡��
	int x;			//����x
	int y;			//����y
	double x0;		//��ȷ����x
	double y0;		//��ȷ����y
	int cenx;		//��������x
	int ceny;		//��������y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	double cx;		//�ٶȺ���ϵ��x
	double sy;		//�ٶ�����ϵ��y
	int health;		//����ֵ
	bool exist;
	int stage;		//�ڼ��ص�?
	bool wudi;		//�Ƿ��޵�
};

//Boss��Ļ�ṹ��
struct BossBullet
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	double x0;		//��ȷ����x
	double y0;		//��ȷ����y
	int cenx;		//��������x
	int ceny;		//��������y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	double cx;		//����ϵ��x
	double sy;		//����ϵ��y
	int damage;		//�˺�ֵ
	bool enable;	//�Ƿ�ɱ��ƻ�
};


//ש�飨���ƻ����ṹ��
struct BlockY
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	int cenx;		//��������x
	int ceny;		//��������y
	int health;		//����ֵ
	bool SGL;		//�Ƿ�����
};

//ש�飨�����ƻ����ṹ��
struct BlockN
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	int cenx;		//��������x
	int ceny;		//��������y
	bool trap;
};

//����ֵ�ṹ��
struct Health
{
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	bool exist;
};


//TODO: �����Ϸ��Ҫ�ĸ��������ݣ��ӵ���ש�顢���ˡ���Ļ�ȣ�


#pragma endregion


#pragma region �¼�����������


// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region ������Ϸ״̬����������

// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// ������Ǻ���
Hero* CreateHero(HBITMAP img, int x, int y, int health, HWND hWnd);

//���С������
Enemy* CreateEnemy(HBITMAP img, int x, int y, int health, bool elite, HWND hWnd);

//���Boss����
Boss* CreateBoss(HBITMAP img, int x, int y, int health, int stage, HWND hWnd);

//���ש��(���ƻ�)����
void CreateBlockY(HBITMAP img, int health, bool sgl,  HWND hWnd);

//���ש��(�����ƻ�)����
void CreateBlockN(HBITMAP img, bool trap, HWND hWnd);

//��������ӵ�����
void CreateHeroBullet(HWND hWnd);

//���С���ӵ�����
void CreateBulletEnemy(HWND hWnd);

//���Boss��Ļ����
void CreateBulletBoss(HWND hWnd);

//��Ӿ�Ӣ�ӵ�����
void CreateBulletElite(HWND hWnd);

// ��ʼ����������
void InitStage(HWND hWnd, int stageID);

// ˢ������״̬����
void UpdateHero(HWND hWnd);

// �������ǵĵ�ǰ֡��
int GetHeroFrame(double dirX, double dirY);

//ˢ�������ӵ�״̬����
void UpdateBulletHero(HWND hWnd);

//ˢ��С��״̬����
void UpdateEnemy(HWND hWnd);

//ˢ��С����Ļ״̬����
void UpdateBulletEnemy(HWND hWnd);

//ˢ�¾�Ӣ��Ļ״̬����
void UpdateBulletElite(HWND hWnd);

//ˢ��Boss״̬����
void UpdateBoss(HWND hWnd);

//ˢ��Boss��Ļ״̬����
void UpdateBulletBoss(HWND hWnd);

//�������ƽ������
int caudis(int cenx1, int cenx2, int ceny1, int ceny2);

//TODO: �����Ϸ��Ҫ�ĸ��ຯ��

#pragma endregion


#pragma region ��ͼ��������

// ��ͼ����
void Paint(HWND hWnd);

#pragma endregion
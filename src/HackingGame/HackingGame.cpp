// HackingGame.cpp : ����Ӧ�ó������ڵ㡣
//

#include "HackingGame.h"
#include <time.h>

using namespace std;



#pragma region ȫ�ֱ���

#define MAX_LOADSTRING			100		

// ȫ�ֱ���: 
HINSTANCE hInst; // ��ǰ����ʵ��
WCHAR szTitle[MAX_LOADSTRING]; // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING]; // ����������


// TODO: �ڴ��������ȫ�ֱ���

HBITMAP bmp_Background; //����ͼ����Դ
HBITMAP bmp_Pause;		//��ͣͼ����Դ
HBITMAP bmp_StageSelect;	//ѡ��ͼ����Դ
HBITMAP bmp_StartButton; //��ʼ��ťͼ����Դ
HBITMAP bmp_Hero; //����ͼ����Դ
HBITMAP bmp_HeroW;	//�޵�ʱ����ͼ����Դ
HBITMAP bmp_BulletHero; //�ӵ�(����)ͼ����Դ
HBITMAP bmp_Enemy; //С��ͼ����Դ
HBITMAP bmp_BulletEnemy; //С����Ļͼ����Դ
HBITMAP bmp_Boss;	//Bossͼ����Դ
HBITMAP bmp_BulletBossY; //Boss��Ļ1ͼ����Դ
HBITMAP bmp_BulletBossN; //Boss��Ļ2ͼ����Դ
HBITMAP bmp_BlockY;		//ש��(���ƻ�)ͼ����Դ
HBITMAP bmp_BlockN;		//ש��(�����ƻ�)ͼ����Դ
HBITMAP bmp_BlockN2;	//ש��(�����ƻ�)2ͼ����Դ
HBITMAP bmp_BackButton;	//���ذ�ťͼ����Դ
HBITMAP bmp_RestartButton;	//���¿�ʼ��ťͼ����Դ
HBITMAP bmp_MainmenuButton;	//�������˵���ťͼ����Դ
HBITMAP bmp_ExitButton;		//������Ϸ��ťͼ����Դ
HBITMAP bmp_HelpButton;		//�����ĵ���ťͼ����Դ
HBITMAP bmp_PauseButton;	//��ͣ��ťͼ����Դ
HBITMAP bmp_temp;			//��ͣʱ�ݴ�ͼ��
HBITMAP bmp_Stage1;			//��һ��ͼ����Դ
HBITMAP bmp_Stage2;			//�ڶ���ͼ����Դ
HBITMAP bmp_Life;			//����ֵͼ����Դ
HBITMAP bmp_EliteEnemy;		//��ӢС��ͼ����Դ
HBITMAP bmp_EliteBullet;	//��Ӣ�ӵ�ͼ����Դ
HBITMAP bmp_BulletEliteEnemy;	//��ӢС���ӵ�ͼ����Դ
HBITMAP bmp_BlockSGL;		//ˢ��ש��ͼ����Դ
HBITMAP bmp_Boss2;			//��2��Bossͼ����Դ
HBITMAP bmp_Stage1Button;	//��һ�ذ�ťͼ����Դ
HBITMAP bmp_Stage2Button;	//�ڶ��ذ�ťͼ����Դ
HBITMAP bmp_Boss1W;			//Boss1�޵�ͼ����Դ
HBITMAP bmp_Boss2W;			//Boss2�޵�ͼ����Դ
HBITMAP bmp_HeroSkill;		//���Ǽ���ͼ����Դ
HBITMAP bmp_HeroSkill2;		//���Ǽ���2ͼ����Դ
HBITMAP bmp_BossBorn[30];	//BOSS��������ͼ����Դ
HBITMAP bmp_WinStage1;		//��һ��ʤ��ͼ����Դ
HBITMAP bmp_WinStage2;		//�ڶ���ʤ��ͼ����Դ
HBITMAP bmp_Lose;			//ʧ��ͼ����Դ
HBITMAP bmp_StageHelp;		//��������ͼ����Դ
HBITMAP bmp_StageSelectS;

Stage* currentStage = NULL; //��ǰ����״̬
Hero* theHero = NULL; //����״̬
BulletHero thebh[50];	//�����ӵ�״̬
Enemy* theEnmy[10] = {NULL};  //С��״̬
EnemyBullet* thebe[50] = {NULL};  //С���ӵ�״̬
EliteBullet* thebelt[50] = {NULL};//��Ӣ�ӵ�״̬
Boss* theBoss = NULL;	//Boss״̬
BossBullet* thebbs[155] = {NULL};//Boss��Ļ״̬
BlockY*		theblky[15] = {NULL};//���ƻ�ש��״̬
BlockN*		theblkn[15] = {NULL};//�����ƻ�ש��״̬
Health*		theHealth[7] = {NULL};	//����ֵ״̬
vector<Button*> buttons; //��ť

int mouseX = 0;
int mouseY = 0;
int BulletHNum = 0;		 //��ǰ�����ӵ�������
int countEnmy1 = 6;     //С����������һ�أ�
int KilledEnmy1 = 0;	//�Ѿ���ɱ��С������(��һ��)
int NowEnmyNum = 0;		//ͬ��Ļ��ͬʱ���ֵ�С������
int NowEliteNum = 0;	//ͬ��Ļ��ͬʱ���ֵľ�Ӣ����
int BulletENum = 0;		//��ǰС���ӵ�������
int BulletBNum = 0;	//��ǰBoss��Ļ�ӵ�������
int angle = 0;			//Boss��Ļ�ǶȲ���
int judgebossb = 0;		//�ж�Boss�����ӵ��������
int recordEnemyDeathX = 0;//��¼��ȥ��С��X����
int recordEnemyDeathY = 0;//��¼��ȥ��С��Y����
int escnum = 0;			//�㰴ESC�Ĵ���
int SGLx = 0;			//ˢ��������
int SGLNum = 0;			//ˢ��������
int bossborn = 1;		//BOSS������������
int bossborn_TIMER = 0;	//BOSS����������ʱ��
bool EnemyDeath = false;
bool mouseDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool keyZDown = false;
bool GamePause = false;
bool StageSelect = false;
bool BossChange = false;
bool BulletBStop = false;
bool HeroSkill = true;
bool HeroSKill2 = true;
bool BossAnime = false;
bool Lose = false;
bool Win = false;



double const PI = acos(double(-1));
#pragma endregion



#pragma region Win32������



// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_HACKINGGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HACKINGGAME));

    MSG msg;

    // ����Ϣѭ��: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HACKINGGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindow(szWindowClass, szTitle,
	   WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // ���ô�����ʽ�����ɸı��С���������,
	   CW_USEDEFAULT, 
	   CW_USEDEFAULT,
	  WINDOW_WIDTH,
	   WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
	   nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		// ��ʼ����Ϸ����
		InitGame(hWnd, wParam, lParam);
		break;
	case WM_KEYDOWN:
		// ���̰����¼�
		KeyDown(hWnd, wParam, lParam);
		break;
	case WM_KEYUP:
		// �����ɿ��¼�
		KeyUp(hWnd, wParam, lParam);
		break;
	case WM_MOUSEMOVE:
		// ����ƶ��¼�
		MouseMove(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONDOWN:
		// �����������¼�
		LButtonDown(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONUP:
		// �������ɿ��¼�
		LButtonUp(hWnd, wParam, lParam);
		break;
	case WM_TIMER:
		// ��ʱ���¼�
		if(currentStage!=NULL && currentStage->timerOn) 
			TimerUpdate(hWnd, wParam, lParam);
		break;
    case WM_PAINT:
		// ��ͼ
		Paint(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


#pragma endregion




#pragma region �¼�������

// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam) 
{
	//����ͼ����Դ
	bmp_Background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BG0));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_START));
	bmp_Hero = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, 
MAKEINTRESOURCE(IDB_BITMAP_HERO));
	bmp_HeroW = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HEROWUDI));
	bmp_BulletHero = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
MAKEINTRESOURCE(IDB_BITMAP_BULLETHERO));
	bmp_Enemy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ENEMY));
	bmp_BulletEnemy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BULLETENEMY));
	bmp_Boss = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BOSS));
	bmp_BulletBossY = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BULLETBOSS1));
	bmp_BulletBossN = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BULLETBOSS2));
	bmp_BlockY = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BLOCKY));
	bmp_BlockN = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BLOCKN));
	bmp_BackButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACK));
	bmp_ExitButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_EXIT));
	bmp_HelpButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HELP));
	bmp_MainmenuButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_MAINMENU));
	bmp_Pause = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_PAUSE));
	bmp_RestartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_RESTART));
	bmp_Stage1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE1));
	bmp_Life = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_LIFE));
	bmp_EliteEnemy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ELITEENEMY));
	bmp_BulletEliteEnemy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ELITEENEMYBULLET0));
	bmp_BlockSGL = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BLOCKSGL));
	bmp_Boss2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BOSS2));
	bmp_StageSelectS = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGESELECT));
	bmp_Stage1Button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE1BUTTON));
	bmp_Stage2Button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE2BUTTON));
	bmp_EliteBullet = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ELITEBULLET));
	bmp_Boss1W = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BOSS1WUDI));
	bmp_Boss2W = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BOSS2WUDI));
	bmp_BlockN2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BLOCKN2));
	bmp_HeroSkill = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HEROSKILL1));
	bmp_HeroSkill2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HEROSKILL2));
	for(int i=1;i<=29;i++)
	{
		bmp_BossBorn[i] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(174 + i));
	}
	bmp_WinStage1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WINSTAGE1));
	bmp_WinStage2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WINSTAGE2));
	bmp_Lose = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_LOSE));
	bmp_Stage2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE2));
	bmp_StageHelp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGEHELP));
	bmp_StageSelect = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGES));


	//��Ӱ�ť
	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 462, 421);
	buttons.push_back(startButton);
	Button* backButton = CreateButton(BUTTON_BACK, bmp_BackButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 462, 400);
	buttons.push_back(backButton);
	Button* exitButton = CreateButton(BUTTON_EXIT, bmp_ExitButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 462, 701);
	buttons.push_back(exitButton);
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_HelpButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 462, 561);
	buttons.push_back(helpButton);
	Button* mainmenuButton = CreateButton(BUTTON_MAINMENU, bmp_MainmenuButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 462, 680);
	buttons.push_back(mainmenuButton);
	Button* restartButton = CreateButton(BUTTON_RESTART, bmp_RestartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 462, 540);
	buttons.push_back(restartButton);
	Button* stage1selectButton = CreateButton(BUTTON_STAGE1, bmp_Stage1Button, 435, 635, 30, 300);
	buttons.push_back(stage1selectButton);
	Button* stage2selectButton = CreateButton(BUTTON_STAGE2, bmp_Stage2Button, 435, 635, 820, 300);
	buttons.push_back(stage2selectButton);
	Button* stagebackButton = CreateButton(BUTTON_STAGEBACK, bmp_BackButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT,900, 20);
	buttons.push_back(stagebackButton);


	//��ʼ����ʼ����
	InitStage(hWnd, STAGE_STARTMENU);

	//��ʼ������ʱ��
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);

	
	srand( (unsigned)time( NULL ));

	
}

// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = true;
		break;
	case VK_DOWN:
		keyDownDown = true;
		break;
	case VK_LEFT:
		keyLeftDown = true;
		break;
	case VK_RIGHT:
		keyRightDown = true;
		break;
	case 'W':
		keyUpDown = true;
		break;
	case 'S':
		keyDownDown = true;
		break;
	case 'A':
		keyLeftDown = true;
		break;
	case 'D':
		keyRightDown = true;
		break;
	case'Z':
		keyZDown = true;
		break;
	case VK_ESCAPE:
		if(currentStage->stageID == STAGE_1 || currentStage->stageID == STAGE_2)
		{	
			escnum++;
			if(escnum%2 != 0)
			{
				GamePause = true;
				//��ʾ��ͣ����İ�ť
				for(int i=0;i<buttons.size();i++)
				{
					Button* button = buttons[i];
					if (button->buttonID == BUTTON_RESTART || button->buttonID == BUTTON_BACK || button->buttonID == BUTTON_MAINMENU) 
					{
						button->visible = true;
					}
					else
					{
						button->visible = false;
					}
				}
			}
			else
			{	
				GamePause = false;
				for(int i=0;i<buttons.size();i++)
				{
					Button* button = buttons[i];
					if (button->buttonID == BUTTON_RESTART || button->buttonID == BUTTON_BACK || button->buttonID == BUTTON_MAINMENU) 
						button->visible = false;
				}

			}
		}
		else if(StageSelect)
		{
			StageSelect = false;
			InitStage(hWnd, STAGE_STARTMENU);
			break;
		}
		else
		{
			PostQuitMessage(0);
		}
		break;
	case VK_SPACE:
		if(HeroSkill && theHero != NULL)
		{	
			theHero->wudi = true;
			HeroSkill = false;
			SetTimer(hWnd, TIMER_HEROIVCIBLETIMER, 4000, NULL);
			SetTimer(hWnd, TIMER_HEROSKILLTIMER, 14000, NULL);
		}
		break;
	case VK_SHIFT:
		if(HeroSKill2 && theHero != NULL)
		{
			HeroSKill2 = false;
			if(theHero->health<5 && theHero->health>0)
			{
				theHero->health++;
				theHealth[theHero->health]->exist = true;
			}
			SetTimer(hWnd, TIMER_HEROSKILL2TIMER, 10000, NULL);
		}
	default:
		break;
	}
}

// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = false;
		break;
	case VK_DOWN:
		keyDownDown = false;
		break;
	case VK_LEFT:
		keyLeftDown = false;
		break;
	case VK_RIGHT:
		keyRightDown = false;
		break;
	case 'W':
		keyUpDown = false;
		break;
	case 'S':
		keyDownDown = false;
		break;
	case 'A':
		keyLeftDown = false;
		break;
	case 'D':
		keyRightDown = false;
		break;
	case'Z':
		keyZDown = false;
		break;
	default:
		break;
	}
}

// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hWnd, TIMER_HEROBULLETTIMER, 250, NULL);
	
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;
	if(theHero!=NULL && !GamePause)
		CreateHeroBullet(hWnd);
	for(int i=0;i<buttons.size();i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID)
				{
					case BUTTON_STARTGAME:
						StageSelect = true;
						InitStage(hWnd, STAGE_STARTMENU);
						break;
					case BUTTON_EXIT:
						{
							PostQuitMessage(0);
						}
						break;
					case BUTTON_BACK:
						{
							escnum++;
							GamePause = false;
							currentStage->bg = bmp_Background;
							for(int i=0;i<buttons.size();i++)
							{
								Button* button = buttons[i];
								if (button->buttonID == BUTTON_RESTART || button->buttonID == BUTTON_BACK || button->buttonID == BUTTON_MAINMENU) 
									button->visible = false;
							}
						}
						break;
					case BUTTON_RESTART:
						{
							escnum++;
							GamePause = false;
							currentStage->bg = bmp_Background;
							for(int i=0;i<buttons.size();i++)
							{
								Button* button = buttons[i];
								if (button->buttonID == BUTTON_RESTART || button->buttonID == BUTTON_BACK || button->buttonID == BUTTON_MAINMENU) 
									button->visible = false;
							}
							KillTimer(hWnd, TIMER_HEROBULLETTIMER);
							KillTimer(hWnd, TIMER_BOSSBORNTIMER);
							KillTimer(hWnd, TIMER_BOSSBULLETIMER);
							KillTimer(hWnd, TIMER_ENEMYRATETIMER);
							KillTimer(hWnd, TIMER_ENEMYBULLETTIMER);
							KillTimer(hWnd, TIMER_ELITEBULLETTIMER);
							KillTimer(hWnd, TIMER_ELITERATETIMER);
							InitStage(hWnd, currentStage->stageID);
						}//case
						break;
					case BUTTON_MAINMENU:
						escnum++;
						GamePause = false;
						KillTimer(hWnd, TIMER_HEROBULLETTIMER);
						KillTimer(hWnd, TIMER_BOSSBORNTIMER);
						KillTimer(hWnd, TIMER_BOSSBULLETIMER);
						KillTimer(hWnd, TIMER_ENEMYRATETIMER);
						KillTimer(hWnd, TIMER_ENEMYBULLETTIMER);
						KillTimer(hWnd, TIMER_ELITEBULLETTIMER);
						KillTimer(hWnd, TIMER_ELITERATETIMER);
						InitStage(hWnd, STAGE_STARTMENU);
						break;
					case BUTTON_STAGE1:
						StageSelect = false;
						InitStage(hWnd, STAGE_1);
						break;
					case BUTTON_STAGE2:
						StageSelect = false;
						InitStage(hWnd, STAGE_2);
						break;
					case BUTTON_STAGEBACK:
						StageSelect = false;
						InitStage(hWnd, STAGE_STARTMENU);
						break;
					case BUTTON_HELP:
						InitStage(hWnd, STAGE_HELP);
						break;
				}
			}
		}
	}

}

// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
	KillTimer(hWnd, TIMER_HEROBULLETTIMER);
}

// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
		case TIMER_GAMETIMER:
			if(!GamePause)
			{
				UpdateHero(hWnd);
				UpdateBulletHero(hWnd);
				if(theBoss != NULL)
				{	
					if(theBoss->exist)
					{
						UpdateBoss(hWnd);	
					}
				}
				UpdateBulletBoss(hWnd);
				UpdateEnemy(hWnd);
				UpdateBulletEnemy(hWnd);
				UpdateBulletElite(hWnd);
			}
			break;
		case TIMER_HEROBULLETTIMER:
			if(!GamePause)
			{
				CreateHeroBullet(hWnd);
			}
			break;
		case TIMER_BOSSBULLETIMER:
			if(!GamePause && theBoss->exist)
			{
				CreateBulletBoss(hWnd);
			}
			break;
		case TIMER_ELITEBULLETTIMER:
			if(!GamePause)
			{
				CreateBulletElite(hWnd);
			}
			break;
		case TIMER_ENEMYRATETIMER:
			if(!GamePause)
			{	
				for(int i=1;i<10;i++)
				{
					if(theEnmy[i]==NULL && NowEnmyNum<currentStage->maxEnmyNum && theBoss->health > 0)
					{
						theEnmy[i] = CreateEnemy(bmp_Enemy, 1, 1, 1, 0,hWnd);
						break;
					}
				}
			}
			break;
		case TIMER_ENEMYBULLETTIMER:
			if(!GamePause)
			CreateBulletEnemy(hWnd);
			break;
		case TIMER_BOSSBORNTIMER:
			if(!GamePause)
			{
				theBoss->exist = true;
				KillTimer(hWnd, TIMER_BOSSBORNTIMER);
			}
			break;
		case TIMER_BOSSBORNANIMETIMER:
			BossAnime = true;
			SetTimer(hWnd, TIMER_BOSSBORNAGAPTIMER, 50, NULL);
			KillTimer(hWnd, TIMER_BOSSBORNANIMETIMER);
			break;
		case TIMER_BOSSBORNAGAPTIMER:
			bossborn++;
			if(bossborn>=30)
			{
				BossAnime = false;
				KillTimer(hWnd, TIMER_BOSSBORNAGAPTIMER);
			}
		case TIMER_HEROIVCIBLETIMER:
			if(!GamePause)
			{
				theHero->wudi = false;
				KillTimer(hWnd, TIMER_HEROIVCIBLETIMER);
			}
			break;
		case TIMER_HEROSKILLTIMER:
			if(!GamePause)
			{
				HeroSkill = true;
				KillTimer(hWnd, TIMER_HEROSKILLTIMER);
			}
			break;
		case TIMER_HEROSKILL2TIMER:
			if(!GamePause)
			{
				HeroSKill2 = true;
				KillTimer(hWnd, TIMER_HEROSKILL2TIMER);
			}
			break;
		case TIMER_BOSSIVCIBLETIMER:
			if(!GamePause)
			{
				if(theBoss != NULL)
					theBoss->wudi = false;
				KillTimer(hWnd, TIMER_BOSSIVCIBLETIMER);
			}
			break;
		
		case TIMER_WINLOSETIMER:
			if(!GamePause)
			{
				Lose = false;
				Win = false;
				KillTimer(hWnd, TIMER_WINLOSETIMER);
				KillTimer(hWnd, TIMER_HEROBULLETTIMER);
				KillTimer(hWnd, TIMER_BOSSBORNTIMER);
				KillTimer(hWnd, TIMER_BOSSBULLETIMER);
				KillTimer(hWnd, TIMER_ENEMYRATETIMER);
				KillTimer(hWnd, TIMER_ENEMYBULLETTIMER);
				KillTimer(hWnd, TIMER_ELITEBULLETTIMER);
				KillTimer(hWnd, TIMER_ELITERATETIMER);
				InitStage(hWnd, STAGE_STARTMENU);
			}
			break;
		case TIMER_ELITERATETIMER:
			if(!GamePause && SGLNum != 0)
			{
				SGLx = rand()%2;
				if(SGLx == 0)
				{
					if(theblky[0] != NULL)
					{
						for(int i=1;i<10;i++)
						{
							if(theEnmy[i]==NULL && NowEnmyNum<currentStage->maxEnmyNum && NowEliteNum<2)
							{
								theEnmy[i] = CreateEnemy(bmp_EliteEnemy, theblky[0]->x+50, theblky[0]->y - 50, 2, 1 ,hWnd);
								break;
							}
						}
					}
					else
					{
						for(int i=1;i<10;i++)
						{
							if(theEnmy[i]==NULL && NowEnmyNum<currentStage->maxEnmyNum)
							{
								theEnmy[i] = CreateEnemy(bmp_EliteEnemy, theblky[1]->x+50, theblky[1]->y -50, 2, 1 ,hWnd);
								break;
							}
						}
					}
				}
			else
			{
				if(theblky[1] != NULL)
				{
					for(int i=1;i<10;i++)
					{
						if(theEnmy[i]==NULL && NowEnmyNum<currentStage->maxEnmyNum)
						{
							theEnmy[i] = CreateEnemy(bmp_EliteEnemy, theblky[1]->x+50, theblky[1]->y -50, 2, 1 ,hWnd);
							break;
						}
					}
				}
				else
				{
					for(int i=1;i<10;i++)
					{
						if(theEnmy[i]==NULL && NowEnmyNum<currentStage->maxEnmyNum)
						{
							theEnmy[i] = CreateEnemy(bmp_EliteEnemy, theblky[0]->x+50, theblky[0]->y -50, 2, 1 ,hWnd);
							break;
						}
					}
				}
			}	
		}
			break;
	}

	//ˢ����ʾ
	InvalidateRect(hWnd, NULL, FALSE);
}


#pragma endregion


#pragma region ������Ϸ״̬������



//TODO: �����Ϸ��Ҫ�ĸ��ຯ��

// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;

	button->visible = false;
	return button;
}

// ������Ǻ���
Hero* CreateHero(HBITMAP img, int x, int y, int health, HWND hWnd)
{
	Hero* hero = new Hero();
	hero->img = img;
	hero->x = x;
	hero->y = y;
	hero->cenx = x+16;
	hero->ceny = y+16;
	hero->frame = 0;
	hero->vx = 0;
	hero->vy = 0;
	hero->health = health;
	hero->exist = true;
	hero->wudi = true;
	SetTimer(hWnd, TIMER_HEROIVCIBLETIMER, 3000, NULL);
	return hero;
}

//���С������
Enemy* CreateEnemy(HBITMAP img, int x, int y, int health, bool elite, HWND hWnd)
{
	Enemy* enemy = new Enemy();
	enemy->img = img;
	enemy->elite = elite;
	if(!enemy->elite)
	{
		enemy->x0 = rand()%(WINDOW_WIDTH-50+1);
		enemy->y0 = rand()%(WINDOW_HEIGHT-42+1);
		enemy->x = enemy->x0;
		enemy->y = enemy->y0;
		int a = caudis(theHero->x, enemy->x, theHero->y, enemy->y);
		while(a<=5000)
		{
			enemy->x = rand()%(WINDOW_WIDTH-50+1);
			enemy->y = rand()%(WINDOW_HEIGHT-42+1);
			a = caudis(theHero->x, enemy->x, theHero->y, enemy->y);
		}
		enemy->vx = 0;
		enemy->vy = 0;
		enemy->health = health;
		enemy->exist = true;
		NowEnmyNum++;
		return enemy;
	}
	else
	{
		enemy->x0 = x;
		enemy->y0 = y;
		enemy->x = x;
		enemy->y = y;
		enemy->vx = 0;
		enemy->vy = 0;
		enemy->health = health;
		enemy->exist = true;
		NowEnmyNum++;
		NowEliteNum++;
		return enemy;
	}
}

//���С���ӵ�����
void CreateBulletEnemy(HWND hwnd)
{
	for(int i=1;i<10;i++)
	{
		if(theEnmy[i] != NULL)
		{
			if(theEnmy[i]->elite)
				continue;
			for(int j=1;j<50;j++)
			{
				if(thebe[j] == NULL)
				{
					thebe[j] = new EnemyBullet();
					thebe[j]->x0 = theEnmy[i]->x;	
					thebe[j]->y0 = theEnmy[i]->y;
					thebe[j]->x = theEnmy[i]->x;	
					thebe[j]->y = theEnmy[i]->y;	
					double chang, kuan, xie;
					chang = theHero->x - theEnmy[i]->x;
					kuan = theHero->y - theEnmy[i]->y;
					xie = sqrt(chang*chang + kuan*kuan);
					if(xie!=0)
					{
						thebe[j]->cx = chang/xie;
						thebe[j]->sy = kuan/xie;
					}
					else
					{
						thebe[j]->cx = 1;
						thebe[j]->sy = 1;
					}
					BulletENum++;					
					break;
				}//if
			}//for
		}
	}
}

//��Ӿ�Ӣ�ӵ�����
void CreateBulletElite(HWND hwnd)
{
	for(int i=1;i<10;i++)
	{
		if(theEnmy[i] != NULL)
		{
			if(!theEnmy[i]->elite)
				continue;
			for(int j=1;j<50;j++)
			{
				if(thebelt[j] == NULL)
				{
					thebelt[j] = new EliteBullet();
					thebelt[j]->x0 = theEnmy[i]->x;	
					thebelt[j]->y0 = theEnmy[i]->y;
					thebelt[j]->x = theEnmy[i]->x;	
					thebelt[j]->y = theEnmy[i]->y;			
					break;
				}//if
			}//for
		}
	}
}

//���Boss����
Boss* CreateBoss(HBITMAP img, int x, int y, int health, int stage, HWND hWnd)
{
	Boss* boss = new Boss();
	boss->img = img;
	boss->stage = stage;
	if(boss->stage == 2)
		boss->wudi = true;
	boss->x = rand()%(WINDOW_WIDTH-100+1);
	boss->y = rand()%(WINDOW_HEIGHT-100+1);
	boss->x0 = boss->x;
	boss->y0 = boss->y;
	boss->cenx = boss->x +16;
	boss->ceny = boss->y +16;
	boss->vx = 0;
	boss->vy = 0;
	boss->health = health;
	boss->exist = false;
	if(boss->stage == 1)
		SetTimer(hWnd, TIMER_BOSSBULLETIMER, 180, NULL);
	if(boss->stage == 2)
		SetTimer(hWnd, TIMER_BOSSBULLETIMER, 80, NULL);
	return boss;
}

//���Boss��Ļ����
void CreateBulletBoss(HWND hWnd)
{
	if(theBoss != NULL && theBoss->health > 5)
	{
		for(int i=1;i<150;i++)
		{

			if(thebbs[i] == NULL)
			{
			
				thebbs[i] = new BossBullet();
				thebbs[i]->x = theBoss->x;	
				thebbs[i]->y = theBoss->y;	
				thebbs[i]->x0 = theBoss->x;	
				thebbs[i]->y0 = theBoss->y;
				thebbs[i]->cx = cos(angle*PI/180);
				thebbs[i]->sy = -sin(angle*PI/180);
				judgebossb = rand()%5;
				if(judgebossb == 0)
				{
					thebbs[i]->img = bmp_BulletBossN;
					thebbs[i]->enable = false;
				}
				else
				{
					thebbs[i]->img = bmp_BulletBossY;
					thebbs[i]->enable = true;
				}
				angle += 20;
				if(angle>=360)
					angle = 0;		
				BulletBNum++;					
				break;
			}
		}
	}

	else if(theBoss != NULL && theBoss->health <= 5)
	{
		for(int k=0;k<18;k++)
		{
			for(int i=1;i<150;i++)
			{

				if(thebbs[i] == NULL)
				{

					thebbs[i] = new BossBullet();
					thebbs[i]->x = theBoss->x;	
					thebbs[i]->y = theBoss->y;	
					thebbs[i]->x0 = theBoss->x;	
					thebbs[i]->y0 = theBoss->y;
					thebbs[i]->cx = cos(angle*PI/180);
					thebbs[i]->sy = -sin(angle*PI/180);
					judgebossb = rand()%5;
					if(judgebossb == 0)
					{
						thebbs[i]->img = bmp_BulletBossN;
						thebbs[i]->enable = false;
					}
					else
					{
						thebbs[i]->img = bmp_BulletBossY;
						thebbs[i]->enable = true;
					}
					angle += 20;
					if(angle>=360)
						angle = 0;		
					BulletBNum++;					
					break;
				}
			}
		}
	}
}



//���ש��(���ƻ�)����
void CreateBlockY(HBITMAP img, int health, bool sgl ,HWND hWnd)
{
	for(int i=0;i<10;i++)
	{
		if(theblky[i] == NULL)
		{
			theblky[i] = new BlockY();
			theblky[i]->SGL = sgl;
			if(theblky[i]->SGL)
				theblky[i]->img = bmp_BlockSGL;
			else
				theblky[i]->img = bmp_BlockY;
			theblky[i]->x = rand()%(WINDOW_WIDTH-100-100+1);
			theblky[i]->y = rand()%(WINDOW_HEIGHT-100-100+1);
			theblky[i]->cenx = theblky[i]->x + 25;
			theblky[i]->ceny = theblky[i]->y + 25;
			int a, b, c;
			a = caudis(theblky[i]->cenx, theHero->x, theblky[i]->ceny, theHero->y);
			b = caudis(theblky[i]->cenx, theBoss->cenx, theblky[i]->ceny, theBoss->ceny);
			while(1)
			{
				if(a<=30000 || b<=30000 || theblky[i]->x<=50 || theblky[i]->y<=50)
				{
					theblky[i]->x = rand()%(WINDOW_WIDTH-100-100+1);
					theblky[i]->y = rand()%(WINDOW_HEIGHT-100-100+1);
					theblky[i]->cenx = theblky[i]->x + 25;
					theblky[i]->ceny = theblky[i]->y + 25;
					a = caudis(theblky[i]->cenx, theHero->x, theblky[i]->ceny, theHero->y);
					b = caudis(theblky[i]->cenx, theBoss->cenx, theblky[i]->ceny, theBoss->ceny);
				}
				else
					break;
			}
			theblky[i]->health = health;
			for(int j=0;j<10;j++)
			{
				if(i == j)
					continue;
				if(theblky[j] == NULL)
					continue;
				int n = caudis(theblky[i]->cenx, theblky[j]->cenx, theblky[i]->ceny, theblky[j]->ceny);
				if(n<=25000)
				{
					delete theblky[i];
					theblky[i] = NULL;
					CreateBlockY(bmp_BlockY, 15, sgl, hWnd);
					break;
				}

			}
			break;
		}
	}
}

//���ש��(�����ƻ�)����
void CreateBlockN(HBITMAP img, bool trap, HWND hWnd)
{
	for(int i=0;i<10;i++)
	{
		if(theblkn[i] == NULL)
		{
			theblkn[i] = new BlockN();
			theblkn[i]->trap = trap;
			if(!theblkn[i]->trap)
				theblkn[i]->img = bmp_BlockN;
			else
				theblkn[i]->img = bmp_BlockN2;
			theblkn[i]->x = rand()%(WINDOW_WIDTH-100-100+1);
			theblkn[i]->y = rand()%(WINDOW_HEIGHT-100-100+1);
			theblkn[i]->cenx = theblkn[i]->x + 25;
			theblkn[i]->ceny = theblkn[i]->y + 25;
			int a, b, c;
			a = caudis(theblkn[i]->cenx, theHero->x, theblkn[i]->ceny, theHero->y);
			b = caudis(theblkn[i]->cenx, theBoss->cenx, theblkn[i]->ceny, theBoss->ceny);
			while(1)
			{
				if(a<=30000 || b<=30000 || theblkn[i]->x<=50 || theblkn[i]->y<=50)
				{
					theblkn[i]->x = rand()%(WINDOW_WIDTH-100-100+1);
					theblkn[i]->y = rand()%(WINDOW_HEIGHT-100-100+1);
					theblkn[i]->cenx = theblkn[i]->x + 25;
					theblkn[i]->ceny = theblkn[i]->y + 25;
					a = caudis(theblkn[i]->cenx, theHero->x, theblkn[i]->ceny, theHero->y);
					b = caudis(theblkn[i]->cenx, theBoss->cenx, theblkn[i]->ceny, theBoss->ceny);
				}
				else
					break;
			}
			
			for(int j=0;j<10;j++)
			{
				if(theblky[j] == NULL)
					continue;
				int n = caudis(theblkn[i]->cenx, theblky[j]->cenx, theblkn[i]->ceny, theblky[j]->ceny);
				if(n<=25000)
				{
					delete theblkn[i];
					theblkn[i] = NULL;
					CreateBlockN(bmp_BlockN, trap, hWnd);
					break;
				}
			}

			for(int j=0;j<10;j++)
			{
				if(i == j)
					continue;
				if(theblkn[i] == NULL)
					break;
				if(theblkn[j] == NULL)
					continue;
				int n = caudis(theblkn[i]->cenx, theblkn[j]->cenx, theblkn[i]->ceny, theblkn[j]->ceny);
				if(n<=40000)
				{
					delete theblkn[i];
					theblkn[i] = NULL;
					CreateBlockN(bmp_BlockN, trap, hWnd);
					break;
				}
			}

			break;
		}
	}
}

//��������ӵ�����
void CreateHeroBullet(HWND hWnd)
{
	for(int i=1;i<50;i++)
	{

		if(!thebh[i].exist)
		{
			thebh[i].x = theHero->x;	//�����ӵ�x����
			thebh[i].y = theHero->y;	//�����ӵ�y����
			thebh[i].x0 = theHero->x;	//�����ӵ�x����
			thebh[i].y0 = theHero->y;
			double chang, kuan, xie;
			chang = mouseX - thebh[i].x;
			kuan = mouseY - thebh[i].y;
			xie = sqrt(chang*chang + kuan*kuan);
			if(xie != 0)
			{
				thebh[i].cx = chang/xie;
				thebh[i].sy = kuan/xie;
			}
			else
			{
				thebh[i].cx = 0;
				thebh[i].sy = 0;
			}
			thebh[i].exist = true;		
			BulletHNum++;					//�ۼ������ӵ�����Ŀ
			break;
		}
	}
}

// ��ʼ����Ϸ��������
void InitStage(HWND hWnd, int stageID)
{
	// ��ʼ������ʵ��
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;


	if (stageID == STAGE_STARTMENU)
	{
		if(StageSelect)
			currentStage->bg = bmp_StageSelect;
		else
			currentStage->bg = bmp_Background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		if(!StageSelect)
			PlaySound(L"bg.wav",0,SND_LOOP | SND_ASYNC | SND_FILENAME);
		//��ʾ��ʼ����İ�ť
		if(!StageSelect)
		{
			for(int i=0;i<buttons.size();i++)
			{
				Button* button = buttons[i];
				if (button->buttonID == BUTTON_STARTGAME || button->buttonID == BUTTON_EXIT || button->buttonID == BUTTON_HELP) 
				{
					button->visible = true;
				}
				else
				{
					button->visible = false;
				}
			}
		}
		//��ʾѡ�ؽ���İ�ť
		else if (StageSelect)
		{
			for(int i=0;i<buttons.size();i++)
			{
				Button* button = buttons[i];
				if (button->buttonID == BUTTON_STAGE1 || button->buttonID == BUTTON_STAGE2 || button->buttonID == BUTTON_STAGEBACK) 
				{
					button->visible = true;
				}
				else
				{
					button->visible = false;
				}
			}
		}

	}

	else if(stageID>= STAGE_HELP && stageID <= STAGE_HELP)
	{
		currentStage->bg = bmp_StageHelp;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STAGEBACK) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}

	}
	else if(stageID>= STAGE_1 && stageID <= STAGE_1) //TODO����Ӷ����Ϸ����
	{
		currentStage->bg = bmp_Stage1;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;
		currentStage->maxEnmyNum = 4;
		BossChange = false;
		HeroSkill = true;
		HeroSKill2 = true;
		BossAnime = false;
		Lose = false;
		Win = false;
		NowEnmyNum = 0;
		bossborn = 1;
		SetTimer(hWnd, TIMER_ENEMYRATETIMER, 4000, NULL);
		SetTimer(hWnd, TIMER_ENEMYBULLETTIMER, 1200, NULL);
		SetTimer(hWnd, TIMER_BOSSBORNTIMER, 10000, NULL);
		SetTimer(hWnd, TIMER_BOSSBORNANIMETIMER, 8000, NULL);
		PlaySound(L"bg1.wav",0,SND_LOOP | SND_ASYNC | SND_FILENAME);
		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (false) //TODO��������Ϸ������Ҫ�İ�ť
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}

		// ��ʼ������
		if (theHero != NULL) delete theHero;
		theHero = CreateHero(bmp_Hero, 400, 300, 5, hWnd);

		//��ʼ��BOSS
		if(theBoss != NULL)
			delete theBoss;
		theBoss = CreateBoss(bmp_Boss, 1, 1, 10, 1, hWnd);
		//��ʼ��ש��(���ƻ�)
		for(int i=0;i<10;i++)
		{
			if(theblky[i] != NULL)
			{
					delete theblky[i];
					theblky[i] = NULL;
			}
		}
		for(int k=0;k<5;k++)
		{
			CreateBlockY(bmp_BlockY, 15, 0, hWnd);
		}

		//��ʼ��ש��(�����ƻ�)
		for(int i=0;i<10;i++)
		{
			if(theblkn[i] != NULL)
			{
				delete theblkn[i];
				theblkn[i] = NULL;
			}
		}
		for(int k=0;k<5;k++)
		{
			CreateBlockN(bmp_BlockN, 0, hWnd);
		}

		//��ʼ�������ӵ�
		//��ʼ�������ӵ�
		for(int i=1;i<50;i++)
		{
			if(thebh[i].exist)
			{
				thebh[i].x = theHero->x;	//�����ӵ�x����
				thebh[i].y = theHero->y;	//�����ӵ�y����
				thebh[i].x0 = theHero->x;	//�����ӵ�x����
				thebh[i].y0 = theHero->y;
				thebh[i].exist = false;
			}
		}

		//��ʼ��С���ӵ�
		for(int i=0;i<50;i++)
		{
			if(thebe[i] != NULL)
			{
				delete thebe[i];
				thebe[i] = NULL;
			}
		}

		//��ʼ��BOSS�ӵ�
		for(int i=0;i<155;i++)
		{
			if(thebbs[i] != NULL)
			{
				delete thebbs[i];
				thebbs[i] = NULL;
			}
		}
	
		//��ʼ��С��
		for(int i=0;i<10;i++)
		{
			if(theEnmy[i] != NULL)
			{
				delete theEnmy[i];
				theEnmy[i] = NULL;
			}
		}

		//��ʼ������ֵ��ʾ
		for(int i=1;i<=5;i++)
		{
			if(theHealth[i] != NULL)
			{
				delete theHealth[i];
				theHealth[i] = NULL;
			}
		}
		for(int i=1;i<=5;i++)
		{
			if(i == 1)
			{
				theHealth[i] = new Health();
				theHealth[i]->x = 90;
				theHealth[i]->y = 20;
				theHealth[i]->exist = true;
			}
			else
			{
				theHealth[i] = new Health();
				theHealth[i]->x = theHealth[i-1]->x + 32;
				theHealth[i]->y = 20;
				theHealth[i]->exist = true;
			}
		}
	}

	else if(stageID>= STAGE_2 && stageID <= STAGE_2)
	{
		currentStage->bg = bmp_Stage2;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;
		currentStage->maxEnmyNum = 5;
		BossChange = false;
		HeroSkill = true;
		HeroSKill2 = true;
		BossAnime = false;
		Lose = false;
		Win = false;
		NowEnmyNum = 0;
		NowEliteNum = 0;
		SGLNum = 0;
		bossborn = 1;
		PlaySound(L"bg2.wav",0,SND_LOOP | SND_ASYNC | SND_FILENAME);
		SetTimer(hWnd, TIMER_ENEMYRATETIMER, 5000, NULL);
		SetTimer(hWnd, TIMER_ENEMYBULLETTIMER, 1500, NULL);
		SetTimer(hWnd, TIMER_ELITEBULLETTIMER, 2000, NULL);
		SetTimer(hWnd, TIMER_ELITERATETIMER, 4000, NULL);
		SetTimer(hWnd, TIMER_BOSSBORNTIMER, 10000, NULL);
		SetTimer(hWnd, TIMER_BOSSBORNANIMETIMER, 8000, NULL);
		//��ʾ��Ϸ����İ�ť
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (false) //TODO��������Ϸ������Ҫ�İ�ť
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}

		// ��ʼ������
		if (theHero != NULL) delete theHero;
		theHero = CreateHero(bmp_Hero, 400, 300, 5, hWnd);

		//��ʼ��BOSS
		if(theBoss != NULL)
			delete theBoss;
		theBoss = CreateBoss(bmp_Boss, 1, 1, 10, 2, hWnd);
		//��ʼ��ש��(���ƻ�)
		for(int i=0;i<10;i++)
		{
			if(theblky[i] != NULL)
			{
				delete theblky[i];
				theblky[i] = NULL;
			}
		}
		for(int k=0;k<2;k++)
		{
			CreateBlockY(bmp_BlockY, 15, 1, hWnd);
			SGLNum++;
		}
		for(int k=0;k<5;k++)
		{
			CreateBlockY(bmp_BlockY, 15, 0, hWnd);
		}
		
		//��ʼ��ש��(�����ƻ�)
		for(int i=0;i<10;i++)
		{
			if(theblkn[i] != NULL)
			{
				delete theblkn[i];
				theblkn[i] = NULL;
			}
		}
		for(int k=0;k<2;k++)
		{
			CreateBlockN(bmp_BlockN, 1, hWnd);
		}
		for(int k=0;k<5;k++)
		{
			CreateBlockN(bmp_BlockN, 0, hWnd);
		}

		//��ʼ�������ӵ�
		//��ʼ�������ӵ�
		for(int i=1;i<50;i++)
		{
			if(thebh[i].exist)
			{
				thebh[i].x = theHero->x;	//�����ӵ�x����
				thebh[i].y = theHero->y;	//�����ӵ�y����
				thebh[i].x0 = theHero->x;	//�����ӵ�x����
				thebh[i].y0 = theHero->y;
				thebh[i].exist = false;
			}
		}

		//��ʼ��С���ӵ�
		for(int i=0;i<50;i++)
		{
			if(thebe[i] != NULL)
			{
				delete thebe[i];
				thebe[i] = NULL;
			}
		}

		//��ʼ����Ӣ�ӵ�
		for(int i=0;i<50;i++)
		{
			if(thebelt[i] != NULL)
			{
				delete thebelt[i];
				thebelt[i] = NULL;
			}
		}

		//��ʼ��BOSS�ӵ�
		for(int i=0;i<155;i++)
		{
			if(thebbs[i] != NULL)
			{
				delete thebbs[i];
				thebbs[i] = NULL;
			}
		}

		//��ʼ��С��
		for(int i=0;i<10;i++)
		{
			if(theEnmy[i] != NULL)
			{
				delete theEnmy[i];
				theEnmy[i] = NULL;
			}
		}

		//��ʼ������ֵ��ʾ
		for(int i=1;i<=5;i++)
		{
			if(theHealth[i] != NULL)
			{
				delete theHealth[i];
				theHealth[i] = NULL;
			}
		}
		for(int i=1;i<=5;i++)
		{
			if(i == 1)
			{
				theHealth[i] = new Health();
				theHealth[i]->x = 90;
				theHealth[i]->y = 20;
				theHealth[i]->exist = true;
			}
			else
			{
				theHealth[i] = new Health();
				theHealth[i]->x = theHealth[i-1]->x + 32;
				theHealth[i]->y = 20;
				theHealth[i]->exist = true;
			}
		}
	}

	//ˢ����ʾ
	InvalidateRect(hWnd, NULL, FALSE);
}


// ˢ������״̬����
void UpdateHero(HWND hWnd)
{
	if (theHero != NULL) {
		//y�����ٶ�
		if (keyUpDown && !keyDownDown && theHero->vy > -1 * HERO_MAXSPEED)
			theHero->vy -= HERO_ACCELERATION;
		else if (!keyUpDown && keyDownDown && theHero->vy < HERO_MAXSPEED)
			theHero->vy += HERO_ACCELERATION;
		else if (theHero->vy > 0)theHero->vy -= HERO_ACCELERATION;
		else if (theHero->vy < 0)theHero->vy += HERO_ACCELERATION;

		//x�����ٶ�
		if (keyLeftDown && !keyRightDown && theHero->vx > -1 * HERO_MAXSPEED)
			theHero->vx -= HERO_ACCELERATION;
		else if (!keyLeftDown && keyRightDown && theHero->vx < HERO_MAXSPEED)
			theHero->vx += HERO_ACCELERATION;
		else if (theHero->vx > 0)theHero->vx -= HERO_ACCELERATION;
		else if (theHero->vx < 0)theHero->vx += HERO_ACCELERATION;
		theHero->x += (int)(theHero->vx); 
		theHero->y += (int)(theHero->vy);
		theHero->cenx = theHero->x + HERO_SIZE_X / 2;
		theHero->ceny = theHero->y + HERO_SIZE_Y / 2;
		if(theHero->x<=0)
		{
				theHero->x=0;
				if(keyLeftDown==1)
					theHero->vx=0;
		}
		else if(theHero->x>=WINDOW_WIDTH-50)
		{
				theHero->x=WINDOW_WIDTH-50;
				if(keyRightDown==1)
					theHero->vx=0;
		}
		if(theHero->y<=0)
		{
			theHero->y=0;
			if(keyUpDown==1)
				theHero->vy=0;
		}
		else if(theHero->y>=WINDOW_HEIGHT-42)
		{	
			theHero->y=WINDOW_HEIGHT-42;
			if(keyDownDown==1)
				theHero->vy=0;
		}
		for(int i=0;i<10;i++)
		{
			if(theblky[i] == NULL)
				continue;
			if(theHero->ceny>=(theblky[i]->y - 5) && theHero->ceny<=(theblky[i]->y+55) && theblky[i]->cenx - theHero->cenx <= 41 && theblky[i]->cenx - theHero->cenx >= 0)
			{
				theHero->cenx = theblky[i]->cenx - 41;
				theHero->x = theHero->cenx - 16;
				if(keyRightDown==1)
					theHero->vx=0;
			}
			else if(theHero->ceny>=(theblky[i]->y - 5) && theHero->ceny<=(theblky[i]->y+55) && theHero->cenx - theblky[i]->cenx <= 41 && theHero->cenx - theblky[i]->cenx >= 0)
			{
				theHero->cenx = theblky[i]->cenx + 41;
				theHero->x = theHero->cenx - 16;
				if(keyLeftDown==1)
					theHero->vx=0;
			}

			if(theHero->cenx>=(theblky[i]->x - 5) && theHero->cenx <= (theblky[i]->x+55) && theblky[i]->ceny - theHero->ceny <=41 && theblky[i]->ceny - theHero->ceny >= 0)
			{
				theHero->ceny = theblky[i]->ceny - 41;
				theHero->y = theHero->ceny - 16;
				if(keyDownDown==1)
					theHero->vy=0;
			}
			else if(theHero->cenx>=(theblky[i]->x - 5) && theHero->cenx <= (theblky[i]->x+55) && theHero->ceny - theblky[i]->ceny <=41 && theHero->ceny - theblky[i]->ceny >= 0)
			{
				theHero->ceny = theblky[i]->ceny + 41;
				theHero->y = theHero->ceny - 16;
				if(keyUpDown==1)
					theHero->vy=0;
			}
		}

		for(int i=0;i<10;i++)
		{
			if(theblkn[i] == NULL)
				continue;
			if(theHero->ceny>=(theblkn[i]->y - 5) && theHero->ceny<=(theblkn[i]->y+55) && theblkn[i]->cenx - theHero->cenx <= 41 && theblkn[i]->cenx - theHero->cenx >= 0)
			{
				theHero->cenx = theblkn[i]->cenx - 41;
				theHero->x = theHero->cenx - 16;
				if(keyRightDown==1)
					theHero->vx=0;
			}
			else if(theHero->ceny>=(theblkn[i]->y - 5) && theHero->ceny<=(theblkn[i]->y+55) && theHero->cenx - theblkn[i]->cenx <= 41 && theHero->cenx - theblkn[i]->cenx >= 0)
			{
				theHero->cenx = theblkn[i]->cenx + 41;
				theHero->x = theHero->cenx - 16;
				if(keyLeftDown==1)
					theHero->vx=0;
			}

			if(theHero->cenx>=(theblkn[i]->x - 5) && theHero->cenx <= (theblkn[i]->x+55) && theblkn[i]->ceny - theHero->ceny <=41 && theblkn[i]->ceny - theHero->ceny >= 0)
			{
				theHero->ceny = theblkn[i]->ceny - 41;
				theHero->y = theHero->ceny - 16;
				if(keyDownDown==1)
					theHero->vy=0;
			}
			else if(theHero->cenx>=(theblkn[i]->x - 5) && theHero->cenx <= (theblkn[i]->x+55) && theHero->ceny - theblkn[i]->ceny <=41 && theHero->ceny - theblkn[i]->ceny >= 0)
			{
				theHero->ceny = theblkn[i]->ceny + 41;
				theHero->y = theHero->ceny - 16;
				if(keyUpDown==1)
					theHero->vy=0;
			}
			int m = caudis(theHero->cenx, theblkn[i]->cenx, theHero->ceny, theblkn[i]->ceny);
			if(m<=2000)
			{
				if(!theHero->wudi && theblkn[i]->trap && !Win)
				{	
					int j = theHero->health;
					if(j>0)
					{
						theHealth[j]->exist = false;
					}
					theHero->health--;
					if(theHero->health > 0)
					{
						theHero->wudi = true;
						SetTimer(hWnd, TIMER_HEROIVCIBLETIMER, 1500, NULL);
					}
					else
					{
						Lose = true;
						SetTimer(hWnd, TIMER_WINLOSETIMER, 3000, NULL);
						theHero->exist = false;
					}
				}
			}
		}
		if(theHero->wudi)
			theHero->img = bmp_HeroW;
		else
			theHero->img = bmp_Hero;
		int centerX = theHero->x + HERO_SIZE_X / 2;
		int centerY = theHero->y + HERO_SIZE_Y / 2;

		double dirX = mouseX - centerX;
		double dirY = mouseY - centerY;
		theHero->frame = GetHeroFrame(dirX, dirY);

	}
}

//ˢ�������ӵ�״̬����
void UpdateBulletHero(HWND hWnd)
{
	for(int i=1;i<50;i++)
	{	
		if(thebh[i].exist)
		{
			thebh[i].x0 += (10.0*thebh[i].cx);
			thebh[i].y0 += (10.0*thebh[i].sy);
			thebh[i].x = thebh[i].x0;
			thebh[i].y = thebh[i].y0;
			thebh[i].cenx = thebh[i].x + 16;
			thebh[i].ceny = thebh[i].y + 16;
			if(thebh[i].x <= -32 || thebh[i].x >= WINDOW_WIDTH-8 || thebh[i].y <= -32 || thebh[i].y >= WINDOW_HEIGHT-10)
			{
				BulletHNum--;
				thebh[i].exist = false;
				thebh[i].x = theHero->x;
				thebh[i].y = theHero->y;
			}
			for(int j=1;j<100;j++)
			{
				if(thebbs[j] == NULL || !thebbs[j]->enable)
					continue;
				if(!thebh[i].exist)
					break;
				int a, b, c;
				a = thebh[i].cenx - thebbs[j]->cenx;
				b = thebh[i].ceny - thebbs[j]->ceny;
				c = a*a + b*b;
				if(c<=128)
				{
					thebh[i].exist = false;
					thebh[i].x = theHero->x;
					thebh[i].y = theHero->y;
					delete thebbs[j];
					thebbs[j] = NULL;
					BulletBNum--;
					BulletHNum--;
					break;
				}
			}//for
			
			for(int k=1;k<10;k++)
			{
				if(!thebh[i].exist)
					break;
				if(theEnmy[k] != NULL)
				{
					int a, b, c;
					a = thebh[i].cenx - theEnmy[k]->cenx;
					b = thebh[i].ceny - theEnmy[k]->ceny;
					c= a*a + b*b;
					if(c<=128)
					{
						theEnmy[k]->health--;
						thebh[i].exist = false;
						thebh[i].x = theHero->x;
						thebh[i].y = theHero->y;
						BulletHNum--;
						if(theEnmy[k]->health==0)
						{
							if(theEnmy[k]->elite)
								NowEliteNum--;
							NowEnmyNum--;
							EnemyDeath = true;
							recordEnemyDeathX = theEnmy[k]->cenx;
							recordEnemyDeathY = theEnmy[k]->ceny;
							if(NowEnmyNum == 0 && theBoss->health<=0)
							{
								Win = true;
								SetTimer(hWnd, TIMER_WINLOSETIMER, 3000, NULL);
							}
							delete theEnmy[k];
							theEnmy[k] = NULL;
							KilledEnmy1++;
						}
						break;
					}
				}
			}//for

			for(int j=1;j<50;j++)
			{
				if(!thebh[i].exist)
					break;
				if(thebe[j] != NULL)
				{
					int a,b,c;
					a = thebh[i].cenx - thebe[j]->cenx;
					b = thebh[i].ceny - thebe[j]->ceny;
					c = a*a + b*b;
					if(c<=128)
					{
						thebh[i].exist = false;
						thebh[i].x = theHero->x;
						thebh[i].y = theHero->y;
						BulletHNum--;
						delete thebe[j];
						thebe[j] = NULL;
						BulletENum--;
						break;
					}
				}
			}//for

			for(int j=1;j<50;j++)
			{
				if(!thebh[i].exist)
					break;
				if(thebelt[j] != NULL)
				{
					int a,b,c;
					a = thebh[i].cenx - thebelt[j]->cenx;
					b = thebh[i].ceny - thebelt[j]->ceny;
					c = a*a + b*b;
					if(c<=128)
					{
						thebh[i].exist = false;
						thebh[i].x = theHero->x;
						thebh[i].y = theHero->y;
						BulletHNum--;
						delete thebelt[j];
						thebelt[j] = NULL;
						break;
					}
				}
			}//for
			
			if(theBoss!=NULL)
			{
				double l, w, k;
				l = thebh[i].cenx - theBoss->cenx;
				w = thebh[i].ceny - theBoss->ceny;
				k = l*l + w*w;
				if(k<128 && thebh[i].exist && theBoss->exist && !theBoss->wudi)
				{
					theBoss->health--;
					theBoss->wudi = true;
					SetTimer(hWnd, TIMER_BOSSIVCIBLETIMER, 2000, NULL);
					if(currentStage->stageID == 2 && theBoss->health == 1)
						SetTimer(hWnd, TIMER_BOSSBULLETIMER, 40, NULL);
					thebh[i].exist = false;
					thebh[i].x = theHero->x;
					thebh[i].y = theHero->y;
					BulletHNum--;
				}
			}//if

			for(int j=0;j<10;j++)
			{
				if(!thebh[i].exist)
					break;
				if(theblky[j] != NULL)
				{
					int a;
					a = caudis(theblky[j]->cenx, thebh[i].cenx, theblky[j]->ceny, thebh[i].ceny);
					if(a<=800)
					{
						theblky[j]->health--;
						thebh[i].exist = false;
						thebh[i].x = theHero->x;
						thebh[i].y = theHero->y;
						BulletHNum--;
						if(theblky[j]->health==0)
						{
							if(theblky[j]->SGL)
								SGLNum--;
							delete theblky[j];
							theblky[j] = NULL;
							if(SGLNum == 0)
							{
								theBoss->wudi = false;
								KillTimer(hWnd, TIMER_ELITERATETIMER);
							}
						}
						break;
					}
				}
			}//for

			for(int j=0;j<10;j++)
			{
				if(!thebh[i].exist)
					break;
				if(theblkn[j] != NULL)
				{
					int a;
					a = caudis(theblkn[j]->cenx, thebh[i].cenx, theblkn[j]->ceny, thebh[i].ceny);
					if(a<=1600)
					{
						while(a<=1600)
						{
							thebh[i].x0 -= thebh[i].cx;
							thebh[i].y0 -= thebh[i].sy;
							thebh[i].x = thebh[i].x0;
							thebh[i].y = thebh[i].y0;
							thebh[i].cenx = thebh[i].x + 16;
							thebh[i].ceny = thebh[i].y + 16;
							a = caudis(theblkn[j]->cenx, thebh[i].cenx, theblkn[j]->ceny, thebh[i].ceny);
						}
						double b = sqrt(a);
						double dirx = (theblkn[j]->cenx - thebh[i].cenx)/b;
						double diry = (theblkn[j]->ceny - thebh[i].ceny)/b;
						double cx = (thebh[i].cx) *(diry * diry - dirx * dirx)+ (thebh[i].sy) *(-2*dirx*diry);
						double sy = (thebh[i].cx) * (-2*dirx*diry) + (thebh[i].sy) * (dirx *dirx - diry * diry);
						thebh[i].cx = cx;
						thebh[i].sy = sy;
						break;
					}
				}
			}//for
			
		}
	}
}

//ˢ��С��״̬����
void UpdateEnemy(HWND hWnd)
{
	for(int i=1;i<10;i++)
	{
		if(theEnmy[i] != NULL)
		{
			double chang, kuan ,xie;
			chang = theHero->x - theEnmy[i]->x;
			kuan = theHero->y - theEnmy[i]->y;
			xie = sqrt(chang*chang + kuan*kuan);
			theEnmy[i]->cx = chang/xie;
			theEnmy[i]->sy = kuan/xie;
			if(xie<=20)
			{
				theEnmy[i]->vx = 0;
				theEnmy[i]->vy = 0;
			}
			else
			{
				theEnmy[i]->vx = theEnmy[i]->cx*2.0;
				theEnmy[i]->vy = theEnmy[i]->sy*2.0;
			}
			
			int a=theEnmy[i]->x + (int)(theEnmy[i]->vx); 
			int b=theEnmy[i]->y + (int)(theEnmy[i]->vy);
			if(a<=0)
			{
				theEnmy[i]->vx = -50*theEnmy[i]->vx;
			}
			else if(a>=WINDOW_WIDTH-50)
			{
				theEnmy[i]->vx = -50*theEnmy[i]->vx;
			}
			if(b<=0)
			{
				theEnmy[i]->vy = -50*theEnmy[i]->vy;
			}
			else if(b>=WINDOW_HEIGHT-42)
			{	
				theEnmy[i]->vy = -50*theEnmy[i]->vy;
			}
			theEnmy[i]->x0 += theEnmy[i]->vx;
			theEnmy[i]->y0 += theEnmy[i]->vy;
			theEnmy[i]->x = theEnmy[i]->x0;
			theEnmy[i]->y = theEnmy[i]->y0;
			theEnmy[i]->cenx = theEnmy[i]->x + 16;
			theEnmy[i]->ceny = theEnmy[i]->y + 16;
			
			for(int j=0;j<10;j++)
			{
				if(theblkn[j] != NULL)
				{
					int a;
					a = caudis(theblkn[j]->cenx, theEnmy[i]->cenx, theblkn[j]->ceny, theEnmy[i]->ceny);
					if(a<=8000)
					{
						theEnmy[i]->x0 -=	theEnmy[i]->vx;
						theEnmy[i]->x = theEnmy[i]->x0;
						theEnmy[i]->y0 -=	theEnmy[i]->vy;
						theEnmy[i]->y = theEnmy[i]->y0;
						int x1, y1, x2, y2, res;
						x1 = theHero->cenx - theEnmy[i]->cenx;
						y1 = theHero->ceny - theEnmy[i]->ceny;
						x2 = theblkn[j]->cenx - theEnmy[i]->cenx;
						y2 = theblkn[j]->ceny - theEnmy[i]->ceny;
						res = x1*x2 + y1*y2;
						if(res >= 0)
						{
							double l = sqrt(a);
							theEnmy[i]->cx = (theblkn[j]->ceny - theEnmy[i]->ceny)/l;
							theEnmy[i]->sy = (theEnmy[i]->cenx - theblkn[j]->cenx)/l;
							if(theEnmy[i]->ceny == theblkn[j]->ceny)
							{
								theEnmy[i]->vx = 2.0*(theEnmy[i]->cx + 0.1);
								theEnmy[i]->vy = 5.0*theEnmy[i]->sy;
							}
							else if(theEnmy[i]->cenx == theblkn[j]->cenx)
							{
								theEnmy[i]->vx = 2.0*theEnmy[i]->cx;
								theEnmy[i]->vy = 5.0*(theEnmy[i]->sy + 0.1);
							}
							else
							{
								theEnmy[i]->vx = 2.0*theEnmy[i]->cx;
								theEnmy[i]->vy = 5.0*theEnmy[i]->sy;
							}
							theEnmy[i]->x0 += theEnmy[i]->vx;
							theEnmy[i]->x = theEnmy[i]->x0;
							theEnmy[i]->y0 += theEnmy[i]->vy;
							theEnmy[i]->y = theEnmy[i]->y0;
						}
						else
						{
							theEnmy[i]->x0 +=	theEnmy[i]->vx;
							theEnmy[i]->x = theEnmy[i]->x0;
							theEnmy[i]->y0 +=	theEnmy[i]->vy;
							theEnmy[i]->y = theEnmy[i]->y0;
						}
						break;
					}
				}
			}//for

			for(int j=0;j<10;j++)
			{
				if(theblky[j] != NULL)
				{
					int a;
					a = caudis(theblky[j]->cenx, theEnmy[i]->cenx, theblky[j]->ceny, theEnmy[i]->ceny);
					if(a<=8000)
					{
						theEnmy[i]->x0 -=	theEnmy[i]->vx;
						theEnmy[i]->x = theEnmy[i]->x0;
						theEnmy[i]->y0 -=	theEnmy[i]->vy;
						theEnmy[i]->y = theEnmy[i]->y0;
						int x1, y1, x2, y2, res;
						x1 = theHero->cenx - theEnmy[i]->cenx;
						y1 = theHero->ceny - theEnmy[i]->ceny;
						x2 = theblky[j]->cenx - theEnmy[i]->cenx;
						y2 = theblky[j]->ceny - theEnmy[i]->ceny;
						res = x1*x2 + y1*y2;
						if(res >= 0)
						{
							double l = sqrt(a);
							theEnmy[i]->cx = (theblky[j]->ceny - theEnmy[i]->ceny)/l;
							theEnmy[i]->sy = (theEnmy[i]->cenx - theblky[j]->cenx)/l;
							if(theEnmy[i]->ceny == theblky[j]->ceny)
							{
								theEnmy[i]->vx = 2.0*(theEnmy[i]->cx + 0.1);
								theEnmy[i]->vy = 5.0*theEnmy[i]->sy;
							}
							else if(theEnmy[i]->cenx == theblky[j]->cenx)
							{
								theEnmy[i]->vx = 2.0*theEnmy[i]->cx;
								theEnmy[i]->vy = 5.0*(theEnmy[i]->sy + 0.1);
							}
							else
							{
								theEnmy[i]->vx = 2.0*theEnmy[i]->cx;
								theEnmy[i]->vy = 5.0*theEnmy[i]->sy;
							}
							theEnmy[i]->x0 += theEnmy[i]->vx;
							theEnmy[i]->x = theEnmy[i]->x0;
							theEnmy[i]->y0 += theEnmy[i]->vy;
							theEnmy[i]->y = theEnmy[i]->y0;
						}
						else
						{
							theEnmy[i]->x0 +=	theEnmy[i]->vx;
							theEnmy[i]->x = theEnmy[i]->x0;
							theEnmy[i]->y0 +=	theEnmy[i]->vy;
							theEnmy[i]->y = theEnmy[i]->y0;
						}
						break;
					}
				}
			}//for

			for(int j=1;j<10;j++)
			{
				if(i == j)
					continue;
				if(theEnmy[j] == NULL)
					continue;
				int a = caudis(theEnmy[i]->cenx, theEnmy[j]->cenx, theEnmy[i]->ceny, theEnmy[j]->ceny);
				if(a<=400)
				{
					theEnmy[i]->health++;
					delete theEnmy[j];
					NowEnmyNum--;
					theEnmy[j] = NULL;
				}
				
			}

			if(theBoss->health <= 0)
			{
				KillTimer(hWnd ,TIMER_ENEMYRATETIMER);
				if(NowEnmyNum == 0)
				{
					KillTimer(hWnd, TIMER_ENEMYBULLETTIMER);
					KillTimer(hWnd, TIMER_ELITEBULLETTIMER);
				}
			}
		}
	}

}

//ˢ��С����Ļ״̬����
void UpdateBulletEnemy(HWND hWnd)
{
	for(int i=1;i<50;i++)
	{
		if(thebe[i] != NULL)
		{
			thebe[i]->x0 += (4.0*thebe[i]->cx);
			thebe[i]->y0 += (4.0*thebe[i]->sy);
			thebe[i]->x = thebe[i]->x0;
			thebe[i]->y = thebe[i]->y0;
			thebe[i]->cenx = thebe[i]->x + 16;
			thebe[i]->ceny = thebe[i]->y + 16;
			if(thebe[i]->x <= -32 || thebe[i]->x >= WINDOW_WIDTH-8 || thebe[i]->y <= -32 || thebe[i]->y >= WINDOW_HEIGHT-10)
			{
				BulletENum--;
				delete thebe[i];
				thebe[i] = NULL;
				continue;
			}

			for(int j=0;j<10;j++)
			{
				if(theblky[j] != NULL)
				{
					int a;
					a = caudis(theblky[j]->cenx, thebe[i]->cenx, theblky[j]->ceny, thebe[i]->ceny);
					if(a<=800)
					{
						BulletENum--;
						delete thebe[i];
						thebe[i] = NULL;
						break;
					}
				}
			}//for

			for(int j=0;j<10;j++)
			{
				if(thebe[i] == NULL)
					break;
				if(theblkn[j] != NULL)
				{
					int a;
					a = caudis(theblkn[j]->cenx, thebe[i]->cenx, theblkn[j]->ceny, thebe[i]->ceny);
					if(a<=1600)
					{
						while(a<=1600)
						{
							thebe[i]->x0 -= thebe[i]->cx;
							thebe[i]->y0 -= thebe[i]->sy;
							thebe[i]->x = thebe[i]->x0;
							thebe[i]->y = thebe[i]->y0;
							thebe[i]->cenx = thebe[i]->x + 16;
							thebe[i]->ceny = thebe[i]->y + 16;
							a = caudis(theblkn[j]->cenx, thebe[i]->cenx, theblkn[j]->ceny, thebe[i]->ceny);
						}
						double b = sqrt(a);
						double dirx = (theblkn[j]->cenx - thebe[i]->cenx)/b;
						double diry = (theblkn[j]->ceny - thebe[i]->ceny)/b;
						double cx = (thebe[i]->cx) *(diry * diry - dirx * dirx)+ (thebe[i]->sy) *(-2*dirx*diry);
						double sy = (thebe[i]->cx) * (-2*dirx*diry) + (thebe[i]->sy) * (dirx *dirx - diry * diry);
						thebe[i]->cx = cx;
						thebe[i]->sy = sy;
						break;
					}
				}
			}//for

			if(theHero !=NULL && theHero->exist && thebe[i] != NULL && !Win)
			{
				int a = caudis(thebe[i]->cenx, theHero->cenx, thebe[i]->ceny, theHero->ceny);
				if(a<=500)
				{
					delete thebe[i];
					thebe[i] = NULL;
					if(!theHero->wudi)
					{
						int j = theHero->health;
						if(j>0)
						{
							theHealth[j]->exist = false;
						}
						theHero->health--;
						if(theHero->health > 0)
						{
							theHero->wudi = true;
							SetTimer(hWnd, TIMER_HEROIVCIBLETIMER, 1500, NULL);
						}
						else
						{
							Lose = true;
							SetTimer(hWnd, TIMER_WINLOSETIMER, 3000, NULL);
							theHero->exist = false;
						}
					}
				}
			}//if

		}
	}
	
}

//ˢ�¾�Ӣ�ӵ�״̬����
void UpdateBulletElite(HWND hWnd)
{
	for(int i=1;i<50;i++)
	{
		if(thebelt[i] != NULL)
		{
			
			double chang, kuan, xie;
			chang = theHero->x - thebelt[i]->x;
			kuan = theHero->y - thebelt[i]->y;
			xie = sqrt(chang*chang + kuan*kuan);
			if(xie!=0)
			{
				thebelt[i]->cx = chang/xie;
				thebelt[i]->sy = kuan/xie;
			}
			else
			{
				thebelt[i]->cx = 1;
				thebelt[i]->sy = 1;
			}			
			thebelt[i]->x0 += (3.5*thebelt[i]->cx);
			thebelt[i]->y0 += (3.5*thebelt[i]->sy);
			thebelt[i]->x = thebelt[i]->x0;
			thebelt[i]->y = thebelt[i]->y0;
			thebelt[i]->cenx = thebelt[i]->x + 16;
			thebelt[i]->ceny = thebelt[i]->y + 16;
			if(thebelt[i]->x <= -32 || thebelt[i]->x >= WINDOW_WIDTH-8 || thebelt[i]->y <= -32 || thebelt[i]->y >= WINDOW_HEIGHT-10)
			{
				delete thebelt[i];
				thebelt[i] = NULL;
				continue;
			}

			if(theHero !=NULL && theHero->exist && thebelt[i] != NULL && !Win)
			{
				int a = caudis(thebelt[i]->cenx, theHero->cenx, thebelt[i]->ceny, theHero->ceny);
				if(a<=500)
				{
					delete thebelt[i];
					thebelt[i] = NULL;
					if(!theHero->wudi)
					{
						int j = theHero->health;
						if(j>0)
						{
							theHealth[j]->exist = false;
						}
						theHero->health--;
						if(theHero->health > 0)
						{
							theHero->wudi = true;
							SetTimer(hWnd, TIMER_HEROIVCIBLETIMER, 1500, NULL);
						}
						else
						{
							Lose = true;
							SetTimer(hWnd, TIMER_WINLOSETIMER, 3000, NULL);
							theHero->exist = false;
						}
					}
				}
			}//if

		}
	}
}

// �������ǵĵ�ǰ֡��
int GetHeroFrame(double dirX, double dirY) 
{
	double dirLen = sqrt(dirX * dirX + dirY * dirY);
	if (dirLen == 0)return 0;
	double cos = -dirY / dirLen;
	double arc = acos(cos);
	if (dirX < 0)arc = 2 * PI - arc;

	int frame = (int)((arc + PI / HERO_FRAME_NUMBER) / (2 * PI / HERO_FRAME_NUMBER));
	if (frame == HERO_FRAME_NUMBER)frame = 0;
	return frame;
}

//ˢ��BOSS״̬����
void UpdateBoss(HWND hWnd)
{
	if (theBoss != NULL && theHero != NULL)
	{
		if(theBoss->wudi && theBoss->stage == 1)
			theBoss->img = bmp_Boss1W;
		else if(!theBoss->wudi && theBoss->stage == 1)
			theBoss->img = bmp_Boss;
		else if(theBoss->wudi && theBoss->stage == 2)
			theBoss->img = bmp_Boss2W;
		else if(!theBoss->wudi && theBoss->stage == 2)
			theBoss->img = bmp_Boss2;
		double chang, kuan ,xie;
		chang = theHero->x - theBoss->x;
		kuan = theHero->y - theBoss->y;
		xie = sqrt(chang*chang + kuan*kuan);
		if(xie!=0)
		{
			theBoss->cx = chang/xie;
			theBoss->sy = kuan/xie;
			theBoss->vx = theBoss->cx*0.4;
			theBoss->vy = theBoss->sy*0.4;
		}
		int a=theBoss->x + (int)(theBoss->vx); 
		int b=theBoss->y + (int)(theBoss->vy);
		if(a<=0)
		{
			theBoss->x += (int)(theBoss->vx);
		}
		else if(a>=WINDOW_WIDTH-50)
		{
			theBoss->x -= (int)(theBoss->vx);
		}
		else
		{
			theBoss->x0 += theBoss->vx;
			theBoss->x = theBoss->x0;
		}
		if(b<=0)
		{
			theBoss->y += (int)(theBoss->vy);
		}
		else if(b>=WINDOW_HEIGHT-42)
		{	
			theBoss->y -= (int)(theBoss->vy);
		}
		else
		{
			theBoss->y0 += theBoss->vy;
			theBoss->y = theBoss->y0;
		}
		theBoss->cenx = theBoss->x + 25;
		theBoss->ceny = theBoss->y + 25;
	
		
		for(int k=0;k<10;k++)
		{
			if(theblky[k] == NULL)
				continue;
			int n = caudis(theBoss->cenx, theblky[k]->cenx, theBoss->ceny, theblky[k]->ceny);
			if(n <= 8000)
			{
				theBoss->x0 -=	theBoss->vx;
				theBoss->x = theBoss->x0;
				theBoss->y0 -=	theBoss->vy;
				theBoss->y = theBoss->y0;
				int x1, y1, x2, y2, res;
				x1 = theHero->cenx - theBoss->cenx;
				y1 = theHero->ceny - theBoss->ceny;
				x2 = theblky[k]->cenx - theBoss->cenx;
				y2 = theblky[k]->ceny - theBoss->ceny;
				res = x1*x2 + y1*y2;
				if(res >= 0)
				{
					double l = sqrt(n);
					theBoss->cx = (theblky[k]->ceny - theBoss->ceny)/l;
					theBoss->sy = (theBoss->cenx - theblky[k]->cenx)/l;
					if(theBoss->ceny == theblky[k]->ceny)
					{
						theBoss->vx = 0.2*(theBoss->cx + 0.1);
						theBoss->vy = 0.5*theBoss->sy;
					}
					else if(theBoss->cenx == theblky[k]->cenx)
					{
						theBoss->vx = 0.2*theBoss->cx;
						theBoss->vy = 0.5*(theBoss->sy + 0.1);
					}
					else
					{
						theBoss->vx = 0.2*theBoss->cx;
						theBoss->vy = 0.5*theBoss->sy;
					}
					theBoss->x0 += theBoss->vx;
					theBoss->x = theBoss->x0;
					theBoss->y0 += theBoss->vy;
					theBoss->y = theBoss->y0;
				}
				else
				{
					theBoss->x0 +=	theBoss->vx;
					theBoss->x = theBoss->x0;
					theBoss->y0 +=	theBoss->vy;
					theBoss->y = theBoss->y0;
				}
				break;
			}
		}

		for(int i=0;i<10;i++)
		{
			if(theblkn[i] == NULL)
				continue;
			int n = caudis(theBoss->cenx, theblkn[i]->cenx, theBoss->ceny, theblkn[i]->ceny);
			if(n <= 8000)
			{
				theBoss->x0 -=	theBoss->vx;
				theBoss->x = theBoss->x0;
				theBoss->y0 -=	theBoss->vy;
				theBoss->y = theBoss->y0;
				int x1, y1, x2, y2, res;
				x1 = theHero->cenx - theBoss->cenx;
				y1 = theHero->ceny - theBoss->ceny;
				x2 = theblkn[i]->cenx - theBoss->cenx;
				y2 = theblkn[i]->ceny - theBoss->ceny;
				res = x1*x2 + y1*y2;
				if(res >= 0)
				{
					double k = sqrt(n);
					theBoss->cx = (theblkn[i]->ceny - theBoss->ceny)/k;
					theBoss->sy = (theBoss->cenx - theblkn[i]->cenx)/k;
					if(theBoss->ceny == theblkn[i]->ceny)
					{
						theBoss->vx = 0.2*(theBoss->cx + 0.1);
						theBoss->vy = 0.5*theBoss->sy;
					}
					else if(theBoss->cenx == theblkn[i]->cenx)
					{
						theBoss->vx = 0.2*theBoss->cx;
						theBoss->vy = 0.5*(theBoss->sy + 0.1);
					}
					else
					{
						theBoss->vx = 0.2*theBoss->cx;
						theBoss->vy = 0.5*theBoss->sy;
					}
					theBoss->x0 += theBoss->vx;
					theBoss->x = theBoss->x0;
					theBoss->y0 += theBoss->vy;
					theBoss->y = theBoss->y0;
				}
				else
				{
					theBoss->x0 +=	theBoss->vx;
					theBoss->x = theBoss->x0;
					theBoss->y0 +=	theBoss->vy;
					theBoss->y = theBoss->y0;
				}
				break;
			}
		}

		if(theBoss->health == 5 && !BossChange)
		{
			SetTimer(hWnd, TIMER_BOSSBULLETIMER, 700, NULL);
			if(theBoss->stage == 2)
				SetTimer(hWnd, TIMER_BOSSBSTOPTIMER, 300, NULL);
			BossChange = true;
		}
		if(theBoss->health == 0)
		{
			theBoss->exist = false;
			if(NowEnmyNum == 0)
			{	
				Win = true;
				SetTimer(hWnd, TIMER_WINLOSETIMER, 3000, NULL);
			}
			KillTimer(hWnd, TIMER_BOSSBULLETIMER);
		}
	}
}

//ˢ��BOSS��Ļ״̬����
void UpdateBulletBoss(HWND hWnd)
{
		if(BulletBNum!=0)
		{
			for(int i=1;i<150;i++)
				{
					if(thebbs[i] != NULL)
					{
						thebbs[i]->x0 += (3.0*thebbs[i]->cx);
						thebbs[i]->y0 += (3.0*thebbs[i]->sy);
						thebbs[i]->x = thebbs[i]->x0;
						thebbs[i]->y = thebbs[i]->y0;
						thebbs[i]->cenx = thebbs[i]->x + 16;
						thebbs[i]->ceny = thebbs[i]->y + 16;
						if(thebbs[i]->x <= -32 || thebbs[i]->x >= WINDOW_WIDTH-8 || thebbs[i]->y <= -32 || thebbs[i]->y >= WINDOW_HEIGHT-10)
						{
							BulletBNum--;
							delete thebbs[i];
							thebbs[i] = NULL;
							continue;
						}

						for(int j=0;j<10;j++)
						{
							if(!thebbs[i]->enable)
								break;
							if(theblky[j] != NULL)
							{
								int a;
								a = caudis(theblky[j]->cenx, thebbs[i]->cenx, theblky[j]->ceny, thebbs[i]->ceny);
								if(a<=800)
								{
									BulletBNum--;
									delete thebbs[i];
									thebbs[i] = NULL;
									break;
								}
							}
						}//for

						for(int j=0;j<10;j++)
						{
							if(thebbs[i] == NULL)
								break;
							if(!thebbs[i]->enable)
								break;
							if(theblkn[j] != NULL)
							{
								int a;
								a = caudis(theblkn[j]->cenx, thebbs[i]->cenx, theblkn[j]->ceny, thebbs[i]->ceny);
								if(a<=1600)
								{
									while(a<=1600)
									{
										thebbs[i]->x0 -= thebbs[i]->cx;
										thebbs[i]->y0 -= thebbs[i]->sy;
										thebbs[i]->x = thebbs[i]->x0;
										thebbs[i]->y = thebbs[i]->y0;
										thebbs[i]->cenx = thebbs[i]->x + 16;
										thebbs[i]->ceny = thebbs[i]->y + 16;
										a = caudis(theblkn[j]->cenx, thebbs[i]->cenx, theblkn[j]->ceny, thebbs[i]->ceny);
									}
									double b = sqrt(a);
									double dirx = (theblkn[j]->cenx - thebbs[i]->cenx)/b;
									double diry = (theblkn[j]->ceny - thebbs[i]->ceny)/b;
									double cx = (thebbs[i]->cx) *(diry * diry - dirx * dirx)+ (thebbs[i]->sy) *(-2*dirx*diry);
									double sy = (thebbs[i]->cx) * (-2*dirx*diry) + (thebbs[i]->sy) * (dirx *dirx - diry * diry);
									thebbs[i]->cx = cx;
									thebbs[i]->sy = sy;
									break;
								}
							}
						}//for

						if(theHero !=NULL && theHero->exist && thebbs[i] != NULL && !Win)
						{
							int a = caudis(thebbs[i]->cenx, theHero->cenx, thebbs[i]->ceny, theHero->ceny);
							if(a<=500)
							{
								delete thebbs[i];
								thebbs[i] = NULL;
								if(!theHero->wudi)
								{	
									int j = theHero->health;
									if(j>0)
									{
										theHealth[j]->exist = false;
									}
									theHero->health--;
									if(theHero->health > 0)
									{
										theHero->wudi = true;
										SetTimer(hWnd, TIMER_HEROIVCIBLETIMER, 1500, NULL);
									}
									else
									{
										Lose = true;
										SetTimer(hWnd, TIMER_WINLOSETIMER, 3000, NULL);
										theHero->exist = false;
									}
								}
							}
						}//if

					}
				}
		}

}


//������뺯��
int caudis(int cenx1, int cenx2, int ceny1, int ceny2)
{
	int a, b, c;
	a = cenx1 - cenx2;
	b = ceny1 - ceny2;
	c = a*a +b*b;
	return c;
}



#pragma endregion


#pragma region ��ͼ����
// ��ͼ����
void Paint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//��ʼ������
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// ���Ʊ���������
	SelectObject(hdc_loadBmp, currentStage->bg);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

	// ����������������ݵ�����
	if (currentStage->stageID == STAGE_STARTMENU) {

	}
	else if (currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_1) //TODO����Ӷ����Ϸ����
	{
		// �������ǵ�����
		if(theHero != NULL && theHero->exist)
		{
			SelectObject(hdc_loadBmp, theHero->img);
			TransparentBlt(
			hdc_memBuffer, theHero->x, theHero->y,
			HERO_SIZE_X, HERO_SIZE_Y,
			hdc_loadBmp, 0, HERO_SIZE_Y * theHero->frame, HERO_SIZE_X, HERO_SIZE_Y,
			RGB(255, 255, 255)
			);
		}
		//�������ǵ��ӵ�������
		SelectObject(hdc_loadBmp, bmp_BulletHero);
		if(BulletHNum!=0)
		{
			for(int i=1;i<50;i++)
				if(thebh[i].exist)
				{
					//���������ӵ���ͼ
					TransparentBlt(hdc_memBuffer, thebh[i].x, thebh[i].y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
				}

		}

		//����BOSS������
		if(theBoss != NULL && theBoss->exist)
		{
			SelectObject(hdc_loadBmp, theBoss->img);
			TransparentBlt(
			hdc_memBuffer, theBoss->x, theBoss->y,
			50, 50,
			hdc_loadBmp, 0, 0, 50, 50,
			RGB(255, 255, 255));
		}

		//����BOSS�ӵ�������
		if(BulletBNum != 0)
		{
			for(int i=1;i<150;i++)
			{
				if(thebbs[i] != NULL)
				{
					SelectObject(hdc_loadBmp, thebbs[i]->img);
					TransparentBlt(hdc_memBuffer, thebbs[i]->x, thebbs[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
				}
			}
		}

		//����С��������
			for(int i=1;i<10;i++)
			{
				if(theEnmy[i] != NULL)
				{
					SelectObject(hdc_loadBmp, theEnmy[i]->img);
					TransparentBlt(hdc_memBuffer, theEnmy[i]->x, theEnmy[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
				}
			}

		//����С���ӵ�������
		SelectObject(hdc_loadBmp, bmp_BulletEnemy);
			for(int i=1;i<50;i++)
			{
				if(thebe[i] != NULL)
					TransparentBlt(hdc_memBuffer, thebe[i]->x, thebe[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
			}

		//����С������������
		if(EnemyDeath)
		{
			HPEN hPen;
			HPEN hPenOld;
			hPen = CreatePen( PS_SOLID , 8 , RGB( 0 , 0 , 0 ));
			hPenOld = ( HPEN )SelectObject ( hdc_window, hPen );
			MoveToEx(hdc_window, recordEnemyDeathX, recordEnemyDeathY, NULL);
			for(int i=1;i<=10;i++)
			{
				Ellipse(hdc_window,recordEnemyDeathX - 10*i,recordEnemyDeathY - 10*i,recordEnemyDeathX + 10*i,recordEnemyDeathY + 10*i);
			}
			EnemyDeath = false;
			SelectObject (hdc_window, hPenOld);
			DeleteObject ( hPen );
			EndPaint(hWnd, &ps);
		}


		//����ש��(���ƻ�)������
		SelectObject(hdc_loadBmp, bmp_BlockY);
		for(int i=0;i<10;i++)
		{
			if(theblky[i] != NULL)
				TransparentBlt(hdc_memBuffer, theblky[i]->x, theblky[i]->y, 50, 50, hdc_loadBmp, 0, 0, 50, 50, RGB(255,255,255));
		}

		//����ש��(�����ƻ�)������
		SelectObject(hdc_loadBmp, bmp_BlockN);
		for(int i=0;i<10;i++)
		{
			if(theblkn[i] != NULL)
				TransparentBlt(hdc_memBuffer, theblkn[i]->x, theblkn[i]->y, 50, 50, hdc_loadBmp, 0, 0, 50, 50, RGB(255,255,255));
		}

		//��������ֵ������
		SelectObject(hdc_loadBmp, bmp_Life);
		for(int i=1;i<=5;i++)
		{
			if(theHealth[i]->exist)
				TransparentBlt(hdc_memBuffer, theHealth[i]->x, theHealth[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
		}

		//���Ƽ���ͼ�굽����
		SelectObject(hdc_loadBmp, bmp_HeroSkill);
		if(HeroSkill)
			TransparentBlt(hdc_memBuffer, 270, 20, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));

		//���Ƽ���ͼ��2������
		SelectObject(hdc_loadBmp, bmp_HeroSkill2);
		if(HeroSKill2)
			TransparentBlt(hdc_memBuffer, 320, 20, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
	
		//����ʤ�����ﵽ����
		if(Win)
		{
			SelectObject(hdc_loadBmp, bmp_WinStage1);
			TransparentBlt(
				hdc_memBuffer, 330, 216,
				542, 341,
				hdc_loadBmp, 0, 0, 542, 341,
				RGB(255, 255, 255));
		}
		
			

	}
	
	else if (currentStage->stageID >= STAGE_2 && currentStage->stageID <= STAGE_2)
	{
		// �������ǵ�����
		if(theHero != NULL && theHero->exist)
		{
			SelectObject(hdc_loadBmp, theHero->img);
			TransparentBlt(
				hdc_memBuffer, theHero->x, theHero->y,
				HERO_SIZE_X, HERO_SIZE_Y,
				hdc_loadBmp, 0, HERO_SIZE_Y * theHero->frame, HERO_SIZE_X, HERO_SIZE_Y,
				RGB(255, 255, 255)
				);
		}
		//�������ǵ��ӵ�������
		SelectObject(hdc_loadBmp, bmp_BulletHero);
		if(BulletHNum!=0)
		{
			for(int i=1;i<50;i++)
				if(thebh[i].exist)
				{
					//���������ӵ���ͼ
					TransparentBlt(hdc_memBuffer, thebh[i].x, thebh[i].y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
				}

		}

		//����BOSS������
		if(theBoss != NULL && theBoss->exist)
		{
			SelectObject(hdc_loadBmp, theBoss->img);
			TransparentBlt(
				hdc_memBuffer, theBoss->x, theBoss->y,
				50, 50,
				hdc_loadBmp, 0, 0, 50, 50,
				RGB(255, 255, 255));
		}


		//����BOSS�ӵ�������
		if(BulletBNum != 0)
		{
			for(int i=1;i<150;i++)
			{
				if(thebbs[i] != NULL)
				{
					SelectObject(hdc_loadBmp, thebbs[i]->img);
					TransparentBlt(hdc_memBuffer, thebbs[i]->x, thebbs[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
				}
			}
		}

		//����С��������
		for(int i=1;i<10;i++)
		{
			if(theEnmy[i] != NULL)
			{
				SelectObject(hdc_loadBmp, theEnmy[i]->img);
				TransparentBlt(hdc_memBuffer, theEnmy[i]->x, theEnmy[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
			}
		}

		//����С���ӵ�������
		SelectObject(hdc_loadBmp, bmp_BulletEnemy);
		for(int i=1;i<50;i++)
		{
			if(thebe[i] != NULL)
				TransparentBlt(hdc_memBuffer, thebe[i]->x, thebe[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
		}

		//���ƾ�Ӣ�ӵ�������
		SelectObject(hdc_loadBmp, bmp_EliteBullet);
		for(int i=1;i<50;i++)
		{
			if(thebelt[i] != NULL)
				TransparentBlt(hdc_memBuffer, thebelt[i]->x, thebelt[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
		}

		//����С������������
		if(EnemyDeath)
		{
			HPEN hPen;
			HPEN hPenOld;
			hPen = CreatePen( PS_SOLID , 8 , RGB( 0 , 0 , 0 ));
			hPenOld = ( HPEN )SelectObject ( hdc_window, hPen );
			MoveToEx(hdc_window, recordEnemyDeathX, recordEnemyDeathY, NULL);
			for(int i=1;i<=10;i++)
			{
				Ellipse(hdc_window,recordEnemyDeathX - 10*i,recordEnemyDeathY - 10*i,recordEnemyDeathX + 10*i,recordEnemyDeathY + 10*i);
			}
			EnemyDeath = false;
			SelectObject (hdc_window, hPenOld);
			DeleteObject ( hPen );
			EndPaint(hWnd, &ps);
		}


		//����ש��(���ƻ�)������
		for(int i=0;i<10;i++)
		{
			if(theblky[i] != NULL)
			{	
				SelectObject(hdc_loadBmp, theblky[i]->img);
				TransparentBlt(hdc_memBuffer, theblky[i]->x, theblky[i]->y, 50, 50, hdc_loadBmp, 0, 0, 50, 50, RGB(255,255,255));
			}
		}

		//����ש��(�����ƻ�)������
		for(int i=0;i<10;i++)
		{
			if(theblkn[i] != NULL)
			{
				SelectObject(hdc_loadBmp, theblkn[i]->img);
				TransparentBlt(hdc_memBuffer, theblkn[i]->x, theblkn[i]->y, 50, 50, hdc_loadBmp, 0, 0, 50, 50, RGB(255,255,255));
			}
		}

		//��������ֵ������
		SelectObject(hdc_loadBmp, bmp_Life);
		for(int i=1;i<=5;i++)
		{
			if(theHealth[i]->exist)
				TransparentBlt(hdc_memBuffer, theHealth[i]->x, theHealth[i]->y, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));
		}

		//���Ƽ���ͼ�굽����
		SelectObject(hdc_loadBmp, bmp_HeroSkill);
		if(HeroSkill)
			TransparentBlt(hdc_memBuffer, 270, 20, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));

		//���Ƽ���ͼ��2������
		SelectObject(hdc_loadBmp, bmp_HeroSkill2);
		if(HeroSKill2)
			TransparentBlt(hdc_memBuffer, 320, 20, 32, 32, hdc_loadBmp, 0, 0, 32, 32, RGB(255,255,255));

		//����ʤ�����ﵽ����
		if(Win)
		{
			SelectObject(hdc_loadBmp, bmp_WinStage2);
			TransparentBlt(
				hdc_memBuffer, 330, 216,
				542, 341,
				hdc_loadBmp, 0, 0, 542, 341,
				RGB(255, 255, 255));
		}
	}
	
	
	// ���ư�ť������

	for(int i=0;i<buttons.size();i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,
				button->width, button->height,
				hdc_loadBmp, 0, 0, button->width, button->height,
				RGB(255, 255, 255)
			);
		}
	}
	
	//������ͣ���ﵽ����
	if(GamePause)
	{
		SelectObject(hdc_loadBmp, bmp_Pause);
		TransparentBlt(
			hdc_memBuffer, 480,216,
			367, 149,
			hdc_loadBmp, 0, 0, 367, 149,
			RGB(255, 255, 255));
	}

	//����ѡ�ر��ﵽ����
	if(StageSelect)
	{
		SelectObject(hdc_loadBmp, bmp_StageSelectS);
		TransparentBlt(
			hdc_memBuffer, 330,216,
			629, 68,
			hdc_loadBmp, 0, 0, 629, 68,
			RGB(255, 255, 255));
	}

	//����BOSS��������������
	if(BossAnime)
	{
		SelectObject(hdc_loadBmp, bmp_BossBorn[bossborn]);
		TransparentBlt(
			hdc_memBuffer, theBoss->x - 55,theBoss->y - 55,
			200, 223,
			hdc_loadBmp, 0, 0, 200, 223,
			RGB(255, 255, 255));
	}

	//��������ﵽ����
	if(Lose)
	{
		SelectObject(hdc_loadBmp, bmp_Lose);
		TransparentBlt(
			hdc_memBuffer, 330, 216,
			542, 341,
			hdc_loadBmp, 0, 0, 542, 341,
			RGB(255, 255, 255));
	}

	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ棨�ǳ���Ҫ��
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// ��������
	EndPaint(hWnd, &ps);
}
#pragma endregion
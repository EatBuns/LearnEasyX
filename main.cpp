#include <graphics.h>
#include <iostream>
#include "MenuScene.h"
#include "gameScene.h"
#include "SelectorScene.h"
#include "SceneManager.h"
#include "Animation.h"
#include "Atlas.h"
#include "comm.h"
#include <string>

#define TIWTE 0
#define PVZ 0
#define FPS 144

//圆心基准位置
#define CENTER_X 120
#define CENTER_Y 200
//顶点基准位置
#define	VERTEX_X 0
#define VERTEX_Y 80
//步长
#define STEP 240
//屏幕宽高
#define WIDTH 1280
#define HEIGHT 720

//记录步数
int gl_index = 0;
IMAGE  shadowPlayer_Image;

struct point
{
	point() {}
	point(int x, int y) :x(x), y(y) {}
	point(const point& other) {
		this->x = other.x;
		this->y = other.y;
	}
	int x = -1;
	int y = -1;
};

//穷举圆心位置
point Centers[9] = {
	point(CENTER_X, CENTER_Y), point(CENTER_X + STEP, CENTER_Y), point(CENTER_X + STEP * 2, CENTER_Y),
	point(CENTER_X, CENTER_Y + STEP), point(CENTER_X + STEP, CENTER_Y + STEP), point(CENTER_X + STEP * 2, CENTER_Y + STEP),
	point(CENTER_X, CENTER_Y + STEP * 2), point(CENTER_X + STEP , CENTER_Y + STEP * 2), point(CENTER_X + STEP * 2,CENTER_Y + STEP * 2),
};

point Vertexs[9] = {
	point(VERTEX_X, VERTEX_Y), point(VERTEX_X + STEP, VERTEX_Y), point(VERTEX_X + 2 * STEP, VERTEX_Y),
	point(VERTEX_X, VERTEX_Y + STEP), point(VERTEX_X + STEP, VERTEX_Y + STEP), point(VERTEX_X + 2 * STEP, VERTEX_Y + STEP),
	point(VERTEX_X, VERTEX_Y + STEP * 2), point(VERTEX_X + STEP, VERTEX_Y + STEP * 2), point(VERTEX_X + 2 * STEP, VERTEX_Y + STEP * 2),
};

void DrawLine(const point& start, const point& end)
{
	line(start.x, start.y, end.x, end.y);
}

//初始化画布
void initBord()
{
	DrawLine(point(VERTEX_X, VERTEX_Y), point(WIDTH, VERTEX_Y));
	DrawLine(point(VERTEX_X, VERTEX_Y + STEP), point(WIDTH, VERTEX_Y + STEP));
	DrawLine(point(VERTEX_X, VERTEX_Y + STEP * 2), point(WIDTH, VERTEX_Y + STEP * 2));
	DrawLine(point(STEP, VERTEX_Y), point(STEP, HEIGHT));
	DrawLine(point(STEP * 2, VERTEX_Y), point(STEP * 2, HEIGHT));
}

//绘制标注
void drawFlag(char flag)
{
	if (flag == 'x')
	{
		line(340, 20, 380, 60);
		line(340, 60, 380, 20);
	}
	else
	{
		circle(360, 40, 20);
	}
}

//绘制叉形
void drawX(int index)
{
	point left_top (Vertexs[index].x + 10, Vertexs[index].y + 10);
	point right_top(left_top.x + STEP - 20, left_top.y);
	point left_bottom(left_top.x, left_top.y + STEP - 20);
	point right_bottom(left_top.x + STEP - 20, left_top.y + STEP - 20);
	DrawLine(left_top, right_bottom);
	DrawLine(left_bottom, right_top);
}

//绘制圆形
void drawCircle(int index)
{
	circle(Centers[index].x, Centers[index].y, 100);
}

//判断谁赢
bool isWin(char(*arr)[3], char flag)
{
	if (arr[0][0] == flag && arr[0][1] == flag && arr[0][2] == flag)
		return true;
	if (arr[1][0] == flag && arr[1][1] == flag && arr[1][2] == flag)
		return true;
	if (arr[2][0] == flag && arr[2][1] == flag && arr[2][2] == flag)
		return true;
	if (arr[0][0] == flag && arr[1][0] == flag && arr[2][0] == flag)
		return true;
	if (arr[0][1] == flag && arr[1][1] == flag && arr[2][1] == flag)
		return true;
	if (arr[0][2] == flag && arr[1][2] == flag && arr[2][2] == flag)
		return true;
	if (arr[0][0] == flag && arr[1][1] == flag && arr[2][2] == flag)
		return true;
	if (arr[0][2] == flag && arr[1][1] == flag && arr[2][0] == flag)
		return true;

	return false;
}

//判断平局
bool isDraw()
{
	if (gl_index == 9) return true;
	else return false;
}

point coord2Matrix(int x, int y)
{
	point Matrix;
	if (0 < x && x < 240 && 80 < y && y < 320)
	{
		Matrix.x = 0;
		Matrix.y = 0;
	}
	else if (240 < x && x < 480 && 80 < y && y < 320)
	{
		Matrix.x = 0;
		Matrix.y = 1;
	}
	else if (480 < x && x < 720 && 80 < y && y < 320)
	{
		Matrix.x = 0;
		Matrix.y = 2;
	}
	else if (0 < x && x < 240 && 320 < y && y < 560)
	{
		Matrix.x = 1;
		Matrix.y = 0;
	}
	else if (240 < x && x < 480 && 320 < y && y < 560)
	{
		Matrix.x = 1;
		Matrix.y = 1;
	}
	else if (480 < x && x < 720 && 320 < y && y < 560)
	{
		Matrix.x = 1;
		Matrix.y = 2;
	}
	else if (0 < x && x < 240 && 560 < y && y < 800)
	{
		Matrix.x = 2;
		Matrix.y = 0;
	}
	else if (240 < x && x < 480 && 560 < y && y < 800)
	{
		Matrix.x = 2;
		Matrix.y = 1;
	}
	else if (480 < x && x < 720 && 560 < y && y < 800)
	{
		Matrix.x = 2;
		Matrix.y = 2;
	}
	return Matrix;
}

void showMatrix(char (*arr)[3])
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (arr[i][j] == 'x')
			{
				drawX(i * 3 + j);
			}

			if(arr[i][j] == 'o')
			{
				drawCircle(i * 3 + j);
			}
		}
	}
}

//存储当前动画帧索引
int idx_current_anim = 0;
//动画帧总数
const int PLAYER_ANIM_NUM = 6;
//玩家位置
POINT player_pos = {500, 500};
//玩家速度
const int PLAYER_SPEED = 5;

IMAGE ima_player_left[PLAYER_ANIM_NUM];
IMAGE ima_player_right[PLAYER_ANIM_NUM];

void LoadImages()
{ 
	for (size_t i = 0; i < PLAYER_ANIM_NUM; i++)
	{
		std::wstring filename = _T("img/paimon_right_") + std::to_wstring(i) + _T(".png");
		loadimage(&ima_player_right[i], filename.c_str());
	}

	for (size_t i = 0; i < PLAYER_ANIM_NUM; i++)
	{
		std::wstring filename = _T("img/paimon_left_") + std::to_wstring(i) + _T(".png");
		loadimage(&ima_player_left[i], filename.c_str());
	}
}

#if TIWTE
Animation left_Animation(_T("img/paimon_left_%d.png"), 6, 45);
Animation right_Animation(_T("img/paimon_right_%d.png"), 6, 45);

//调用时间,垂直方向
void drawImage(int delta, int dir_x)
{
	static bool isleft = true;
	if (dir_x > 0) isleft = false;
	else if (dir_x < 0) isleft = true;
	putimage_alpha(player_pos.x + 24, player_pos.y + left_Animation.GetImageHeight() - 8, &shadowPlayer_Image);
	
	if (!isleft)
	{
		right_Animation.play(player_pos.x, player_pos.y, delta);
	}
	else
	{
		left_Animation.play(player_pos.x, player_pos.y, delta);
	}
}
#endif // TIWTE



void flip_Atlas(Atlas& src, Atlas& dst) 
{
	dst.CClear();
	for (int i = 0; i < src.getSize(); i++)
	{
		IMAGE dstIMG;
		filpIMG(src.getFrame(i), &dstIMG);
		dst.appendIMG(dstIMG);
	}
}

IMAGE menu_background;
IMAGE pea;
IMAGE gravestone;
Atlas peashooter_idle_right;
Atlas peashooter_idle_left;
Atlas peashooter_die_right;
Atlas peashooter_die_left;
Atlas peashooter_run_right;
Atlas peashooter_run_left;

BaseScene* mnScene = nullptr;
BaseScene* gmScene = nullptr;
BaseScene* SeScene = nullptr;
SceneManager* manager = nullptr;

void load_game_source()
{
	loadimage(&menu_background, _T("PVZ/resources/menu_background.png"));
	loadimage(&pea, _T("PVZ/resources/pea.png"));
	loadimage(&gravestone, _T("PVZ/resources/gravestone.png"));
	peashooter_idle_right.loadImage(_T("PVZ/resources/peashooter_idle_%d.png"), 9, 1);
	flip_Atlas(peashooter_idle_right, peashooter_idle_left);
	peashooter_die_right.loadImage(_T("PVZ/resources/peashooter_die_%d.png"), 4, 1);
	flip_Atlas(peashooter_die_right, peashooter_die_left);
	peashooter_run_right.loadImage(_T("PVZ/resources/peashooter_run_%d.png"), 5, 1);
	flip_Atlas(peashooter_run_right, peashooter_run_left);
}

int main()
{
#if TIWTE
	bool isOver = true;
	char ChessMatrix[3][3] = { 0 };
	char Chess[2] = {'x', 'o'};
	//保存格子
	point matrix;
	initgraph(WIDTH, HEIGHT);
	
	IMAGE background_Image;
	//加载背景图片
	loadimage(&background_Image, _T("img/background.png"));
	//加载玩家背影
	loadimage(&shadowPlayer_Image, _T("img/shadow_player.png"));
	
	int dir_x = 0;
	DWORD callInterval = 0;
	DWORD before_time =0;

	bool is_left = false;
	bool is_right = false;
	bool is_up = false;
	bool is_down = false;

	BeginBatchDraw();
	while (isOver)
	{
		DWORD start_time= GetTickCount();
		//捕捉设备输入
		ExMessage Message;
		while (peekmessage(&Message))
		{
#ifdef JINGZIQI
			if (Message.message == WM_LBUTTONDOWN)
			{
				matrix = coord2Matrix(Message.x, Message.y);
				if (ChessMatrix[matrix.x][matrix.y] == 0)
				{
					ChessMatrix[matrix.x][matrix.y] = Chess[(gl_index++)%2];
				}
			}
#endif // JINGZIQI
			if (Message.message == WM_KEYDOWN)
			{
				switch (Message.vkcode)
				{
				case VK_UP:	//W
					is_up = true;
					break;
				case VK_DOWN:	//S
					is_down = true;
					break;
				case VK_LEFT:	//A
					is_left = true;
					break;
				case VK_RIGHT:	//D
					is_right = true;
					break;
				}
			}
			else if (Message.message == WM_KEYUP)
			{
				switch (Message.vkcode)
				{
					case VK_UP:	//W
						is_up = false;
						break;
					case VK_DOWN:	//S
						is_down = false;
						break;
					case VK_LEFT:	//A
						is_left = false;
						break;
					case VK_RIGHT:	//D
						is_right = false;
						break;
				}
			}
		}

		int dir_x = is_right -is_left;
		int dir_y = is_down - is_up;
		double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
		if (len_dir != 0)
		{
			double normalized_x = dir_x / len_dir;
			double normalized_y = dir_y / len_dir;
			player_pos.x += (int)(PLAYER_SPEED * normalized_x);
			player_pos.y += (int)(PLAYER_SPEED * normalized_y);

			/*if (player_pos.x - left_Animation.GetImageWidth() <= 0) player_pos.x = left_Animation.GetImageWidth();
			else if (player_pos.x + left_Animation.GetImageWidth() > WIDTH) player_pos.x = WIDTH - left_Animation.GetImageWidth();
			
			if (player_pos.y < 0) player_pos.y = 0;
			else if (player_pos.y >= HEIGHT) player_pos.y = HEIGHT;*/
			
		}
		

		//画图
		cleardevice();
		putimage(0, 0, &background_Image);
		drawImage(1000/60, is_right - is_left);
		
		FlushBatchDraw();

		//判断结束条件
#ifdef JINGZIQI

		initBord();
		if (gl_index % 2)
			drawFlag('o');
		else
			drawFlag('x');
		showMatrix(ChessMatrix);

	if (isWin(ChessMatrix, 'x'))
		{
			MessageBox(GetHWnd(), _T("x 玩家获胜!"), _T("恭喜!"), MB_OK);
			isOver = false;
		}
		else if (isWin(ChessMatrix, 'o'))
		{
			MessageBox(GetHWnd(), _T("o 玩家获胜!"), _T("恭喜!"), MB_OK);
			isOver = false;
		}
		else if (isDraw())
		{
			MessageBox(GetHWnd(), _T("平局!"), _T("游戏结束!"), MB_OK);
			isOver = false;
		}
#endif // JINGZIQI

		//延时
		DWORD end_time = GetTickCount();
		DWORD deal_time = start_time - end_time;
		if (deal_time < 1000 / 60)
		{
			Sleep(1000 / 60 - deal_time);
		}
	}
	EndBatchDraw();
#endif
	mnScene = new MenuSecne();
	gmScene = new GameScene();
	SeScene = new SelectorScene();   

	load_game_source();

	ExMessage Message;
	manager = new SceneManager();
	manager->setCurrentScene(mnScene);
	manager->on_enter();

	initgraph(WIDTH, HEIGHT);
	BeginBatchDraw();
	while (true)
	{
		DWORD start_time = GetTickCount();
		while (peekmessage(&Message))
		{
			manager->on_input(Message);
		}
		
		static DWORD last_tick_count = GetTickCount();
		DWORD currenr_tick_count = GetTickCount();
		DWORD delta_tick_count = currenr_tick_count - last_tick_count;
		manager->on_update(delta_tick_count);
		last_tick_count = currenr_tick_count;

		cleardevice();
		manager->on_draw();
		FlushBatchDraw();
		
		DWORD deal_time = start_time - GetTickCount();
		if (deal_time < 1000 / FPS)
		{
			Sleep(1000 / FPS - deal_time);
		}
	}
	EndBatchDraw();
	closegraph();
	return 0;
}

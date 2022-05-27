#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "snake.h"
#include "interface.h"
#include "food.h"



//按钮判断函数
int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])
	{
		return 1;
	}
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])
	{
		return 2;
	}
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])
	{
		return 3;
	}
	return 0;
}



void drawmap() {
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice(); //调用清屏cleardevice用背景色刷新背景
	for (int i = 0; i < MAP_WIDE; i++)
	{
		setfillcolor(BLACK);
		//上边框
		fillrectangle(i * SIZE, 0, (i + 1) * SIZE, SIZE);
		//下边框
		fillrectangle(i * SIZE, (MAP_HEIGHT - 1) * SIZE, (i + 1) * SIZE, MAP_HEIGHT * SIZE);
	}
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		setfillcolor(BLACK);
		//左边框
		fillrectangle(0, i * SIZE, SIZE, (i + 1) * SIZE);
		//右边框
		fillrectangle((MAP_WIDE - 1) * SIZE, i * SIZE, MAP_WIDE * SIZE, (i + 1) * SIZE);

	}


}

void initmap() {
	//初始化蛇
	head = (snake*)malloc(sizeof(snake));
	head->x = (MAP_WIDE) / 2;
	head->y = (MAP_HEIGHT) / 2;
	snake* p = (snake*)malloc(sizeof(snake));
	snake* q = (snake*)malloc(sizeof(snake));
	p->x = head->x + 1;
	p->y = head->y;
	q->x = head->x + 2;
	q->y = head->y;

	head->next = p;
	p->next = q;
	tail = q;   // 最右边
	tail->next = NULL;

	snake* temp = head;  
	// 打印蛇头
	printnodeH(temp->x, temp->y);
	temp = temp->next;
	while (temp != NULL)//打印出所有结点
	{
		printnode(temp->x, temp->y);
		temp = temp->next;
	}
	//初始化食物
	srand((int)time(NULL));
	food.x = rand() % (MAP_WIDE - 2) + 2;
	food.y = rand() % (MAP_HEIGHT - 2) + 2;
	printnode(food.x, food.y);

}

int welcome() {
	initgraph(850, 600);
	/*for (int i = 0; i < 256; i += 5) {
		setbkcolor(RGB(i, i, i));
		cleardevice();
		Sleep(15);
	}*/

	int t = 0;
	float H = 190, S = 1, LIGHT = 0.7f;		//H 色相：S 饱和度：L 亮度
	wchar_t s[] = L"贪吃蛇";
	wchar_t s1[] = L"V1.0";
	wchar_t s2[] = L"by mfsnt";

	IMAGE snakeImg1;
	//MOUSEMSG m;  //鼠标指针

	for (int i = 0; i < 256; i += 5)
	{
		setbkcolor(RGB(i, i, i));		//设置背景色，原来默认黑色
		cleardevice();					//清屏（取决于背景色）
		Sleep(t * 15);
	}

	// 生成在开始界面
	loadimage(&snakeImg1, _T("snake.jpg"), 400, 400);
	putimage(550, 200, &snakeImg1);

	setbkmode(TRANSPARENT);                //文本透明
	settextcolor(RGB(255, 0, 255));
	settextstyle(110, 60, NULL);
	outtextxy(200, 80, s);
	settextstyle(30, 15, NULL);
	settextcolor(BLACK);
	outtextxy(10, 550, s1);
	outtextxy(680, 550, s2);

	// 生成按钮
	setbkmode(TRANSPARENT);                //文本透明
	settextstyle(30, 15, _T("微软雅黑"));
	settextcolor(BLACK);
	drawtext(_T("开始游戏"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("游戏说明"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("退出"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);

	MOUSEMSG m;//鼠标指针
	setrop2(R2_NOTXORPEN);//二元光栅——NOT(屏幕颜色 XOR 当前颜色)

	while (true) {
		m = GetMouseMsg();//获取一条鼠标消息
		switch (m.uMsg) {
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//二元光栅——NOT(屏幕颜色 XOR 当前颜色)
			for (int i = 0; i <= 10; i++) {
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//设置圆颜色
				circle(m.x, m.y, 2 * i);
				Sleep(30);//停顿30ms
				circle(m.x, m.y, 2 * i);//抹去刚刚画的圆
			}
			//判断事件
			switch (button_judge(m.x, m.y)) {
				//复原按钮原型
			case 1:
				return 1;
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 2:
				return 2;
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 3:
				closegraph();//关闭绘图环境
				exit(0);//正常退出
			default:
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				printf("\r\n(%d,%d)",m.x,m.y);//打印鼠标坐标，方便调试时确定区域
				break;
			}
			break;
			FlushMouseMsgBuffer();//清空鼠标消息缓存区
		}
	}
}




void introduction() {
	float LIGHT = 0.7f;
	IMAGE h;
	char ch;

	setbkcolor(WHITE);
	loadimage(&h, _T("help.png"), 860, 600);
	putimage(0, 0, &h, SRCINVERT);

	do
	{
		ch = _getch();
		if (ch == 'x' || ch == 'X')
		{
			break;
		}
	} while (1);

	//flag = 1;
}

void showscore() {

	wchar_t s[] = L"分数";
	wchar_t s2[] = L"最高分";
	TCHAR s1[5];
	TCHAR m1[5];
	int m;

	//m = getMAX();
	//SetWorkingImage(NULL);
	//getimage(&a, 600, 300, 200, 200);
	//putimage(550, 120, &a);

	setbkmode(TRANSPARENT);                //文本透明
	settextcolor(BLACK);
	settextstyle(40, 20, _T("微软雅黑"));
	outtextxy(500, 5, s);
	settextstyle(40, 20, _T("微软雅黑"));
	outtextxy(500, 200, s2);

	//_stprintf_s(s1, _T("%d"), number);
	//settextcolor(RED);
	//settextstyle(60, 30, _T("微软雅黑"));
	//outtextxy(550, 200, s1);

	//_stprintf_s(m1, _T("%d"), m);
	//settextcolor(GREEN);
	//outtextxy(680, 200, m1);
}
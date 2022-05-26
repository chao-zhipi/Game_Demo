#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "interface.h"


void welcome() {
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

	
}
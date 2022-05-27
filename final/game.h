#pragma once
#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include <string>
#include <math.h>
#include <tchar.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;

#define length 100  //蛇长度

// 画布
static HWND hOut;

static int r[3][4] = { { 300,260,450,320 }, { 300,360,450,420 }, { 300,460,450,520 } };  // 输入按钮的矩形参数
static RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };
static RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };
static RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };


//坐标属性
typedef struct pointXY
{
	int x;
	int y;
}mypoint;

//蛇属性
struct Snake
{
	int num;//蛇的节数
	mypoint xy[length]; //蛇最多有100节
	char dire;//蛇的方向
};
//食物的属性
struct Food
{
	mypoint fdxy;
	int eatgrade = 0;//吃食物的分数
	int flag = 0;//食物是否存在，0表示存在，1表示不存在
};

//主窗口
static HWND hwnd = NULL;

/*
	开始界面
 */
int welcome();

/*
	按钮判断函数
*/
int button_judge(int x, int y);

//初始化蛇和食物
void initSnakeFood(struct Snake* snake, struct Food* food);
//画蛇
void drawSnake(struct Snake* snake);
//移动蛇
void moveSnake(struct Snake* snake);
//按键处理
void keyDown(struct Snake* snake);
//初始化食物
void initFood(struct Food* food, struct Snake* snake);
//画食物
void drawFood(struct Food* food);

//吃食物
void eatFood(struct Food* food, struct Snake* snake);

//判断是否游戏结束
int snakeDie(struct Snake* snake);

//判断游戏是否胜利
int winGame(struct Snake* snake);

//展示分数
void showGrade(struct Food* food);

//按空格键暂停
void pauseMoment();

#endif
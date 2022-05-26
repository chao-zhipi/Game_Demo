#pragma once

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <Windows.h>

// 画布
static HWND hOut;
 
static int r[3][4] = { { 300,260,450,320 }, { 300,360,450,420 }, { 300,460,450,520 } };  // 输入按钮的矩形参数
static RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };
static RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };
static RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };

/**
 * @brief 绘制贪吃蛇图形
 *
 */
void printsnake();

/**设置光标移动的位置
 * @param x x坐标
 * @param y y坐标
 */
void gotoxy(int x, int y);

/*
	开始界面
 */
void welcome();

/*
	难度等级选择界面 
 */
void grade_tips();

/*
	游戏说明
*/
void introduction();

/*
	文字颜色函数
*/
int color(int c);

#endif
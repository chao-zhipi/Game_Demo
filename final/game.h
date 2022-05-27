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

#define length 100  //�߳���

// ����
static HWND hOut;

static int r[3][4] = { { 300,260,450,320 }, { 300,360,450,420 }, { 300,460,450,520 } };  // ���밴ť�ľ��β���
static RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };
static RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };
static RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };


//��������
typedef struct pointXY
{
	int x;
	int y;
}mypoint;

//������
struct Snake
{
	int num;//�ߵĽ���
	mypoint xy[length]; //�������100��
	char dire;//�ߵķ���
};
//ʳ�������
struct Food
{
	mypoint fdxy;
	int eatgrade = 0;//��ʳ��ķ���
	int flag = 0;//ʳ���Ƿ���ڣ�0��ʾ���ڣ�1��ʾ������
};

//������
static HWND hwnd = NULL;

/*
	��ʼ����
 */
int welcome();

/*
	��ť�жϺ���
*/
int button_judge(int x, int y);

//��ʼ���ߺ�ʳ��
void initSnakeFood(struct Snake* snake, struct Food* food);
//����
void drawSnake(struct Snake* snake);
//�ƶ���
void moveSnake(struct Snake* snake);
//��������
void keyDown(struct Snake* snake);
//��ʼ��ʳ��
void initFood(struct Food* food, struct Snake* snake);
//��ʳ��
void drawFood(struct Food* food);

//��ʳ��
void eatFood(struct Food* food, struct Snake* snake);

//�ж��Ƿ���Ϸ����
int snakeDie(struct Snake* snake);

//�ж���Ϸ�Ƿ�ʤ��
int winGame(struct Snake* snake);

//չʾ����
void showGrade(struct Food* food);

//���ո����ͣ
void pauseMoment();

#endif
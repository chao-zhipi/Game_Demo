#pragma once

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <graphics.h>
#include "interface.h"
#include "food.h"

#define SPEED 200

typedef struct Snakes {
	int x;//�ߵĽ���λ������
	int y;
	struct Snakes* next;//ָ����һ��� ��ָ��
	int length = 0;
} snake;

static snake *head, *tail;

static char ch = 'd';  // Ĭ�����ұ���


void printnode(int x, int y);

/*�ߵ��ƶ�*/
void movesnake();


void deletenode(int x, int y);

void changebody();

#endif
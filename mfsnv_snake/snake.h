#pragma once

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <graphics.h>
#include "interface.h"
typedef struct Snakes {
	int x;//�ߵĽ���λ������
	int y;
	struct Snakes* next;//ָ����һ��� ��ָ��
} snake;

static snake *head, *tail;

void printnode(int x, int y);

#endif
#pragma once

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <graphics.h>
#include "interface.h"
typedef struct Snakes {
	int x;//蛇的结点的位置坐标
	int y;
	struct Snakes* next;//指向下一结点 的指针
} snake;

static snake *head, *tail;

void printnode(int x, int y);

#endif
#pragma once

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <graphics.h>
#include "interface.h"
#include "food.h"

#define SPEED 200

typedef struct Snakes {
	int x;//蛇的结点的位置坐标
	int y;
	struct Snakes* next;//指向下一结点 的指针
	int length = 0;
} snake;

static snake *head, *tail;

static char ch = 'd';  // 默认往右边走


void printnode(int x, int y);

/*蛇的移动*/
void movesnake();


void deletenode(int x, int y);

void changebody();

#endif
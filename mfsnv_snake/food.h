#pragma once


#ifndef _FOOD_H_
#define _FOOD_H_
#include <graphics.h>
#include "interface.h"
typedef struct Food {
	int x;
	int y;
}; //并创建了一个食物
static Food food;

static int grow = 0; //grow =0 表示没吃到食物，grow = 1表示吃到食物

void printnodeH(int x, int y);
void updatefood();
#endif
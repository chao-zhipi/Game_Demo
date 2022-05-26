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
void printnodeH(int x, int y);

#endif
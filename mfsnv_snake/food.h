#pragma once


#ifndef _FOOD_H_
#define _FOOD_H_
#include <graphics.h>
#include "interface.h"
typedef struct Food {
	int x;
	int y;
}; //��������һ��ʳ��
static Food food;

static int grow = 0; //grow =0 ��ʾû�Ե�ʳ�grow = 1��ʾ�Ե�ʳ��

void printnodeH(int x, int y);
void updatefood();
#endif
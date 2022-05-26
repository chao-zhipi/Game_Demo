#pragma once

#ifndef _SNAKE_H_
#define _SNAKE_H_

typedef struct Snakes {
	int x;//蛇的结点的位置坐标
	int y;
	struct Snakes* next;//指向下一结点 的指针
} snake;

struct Food {
	int x;
	int y;
}food; //并创建了一个食物

#endif
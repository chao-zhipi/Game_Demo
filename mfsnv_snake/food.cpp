#include "food.h"
#include "interface.h"
#include "snake.h"

extern Food food;

void printnodeF(int x, int y) {
	setfillcolor(BLACK);
	fillcircle(x * SIZE, y * SIZE, SIZE / 2);
	setcolor(WHITE);
	circle(x * SIZE, y * SIZE, SIZE / 2);
}

void updatefood() {
	//如果蛇的结点与食物的坐标相等了，则需要创造新的食物
	snake* judge = head;
	while (judge->next != NULL)//遍历蛇的所有结点 
	{
		if (judge->x == food.x && judge->y == food.y) {
			food.x = rand() % (MAP_WIDE - 2) + 2; //生成2~MAP_WIDE - 2的随机数
			food.y = rand() % (MAP_HEIGHT - 2) + 2; //生成2~MAP_HEIGHT - 2的随机数

			printnodeF(food.x, food.y);//打印新的食物
			score++;
			grow = 1;//表明蛇需有增长（吃到食物）
			break;
		}
		judge = judge->next;
	}
}
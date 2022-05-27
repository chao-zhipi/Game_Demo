#include <stdio.h>
#include "snake.h"

extern snake* head = NULL, * tail = NULL;

void printnodeH(int x, int y) {
	setfillcolor(RED);
	fillcircle(x * SIZE, y * SIZE, SIZE / 2);
	setcolor(WHITE);
	circle(x * SIZE, y * SIZE, SIZE / 2);
}

void printnode(int x, int y) {
	setfillcolor(BLACK);
	fillcircle(x * SIZE, y * SIZE, SIZE / 2);
	setcolor(WHITE);
	circle(x * SIZE, y * SIZE, SIZE / 2);
}

void movesnake() {
	char oldch = ch;//记录原来的方向
	if (_kbhit()) {
		ch = _getch();//新的方向
	}
	//控制方向：向左的时候不能向右转，向上的时候不能向下，向右不能向左，向下不能向上
	if ((ch == 'd' || ch == 'D') && (oldch == 'a' || oldch == 'A'))
		//保持原来的方向不变
		ch = oldch;
	if ((oldch == 'w' || oldch == 'W') && (ch == 'S' || ch == 's'))
		ch = oldch;
	if ((oldch == 'd' || oldch == 'D') && (ch == 'A' || ch == 'a'))
		ch = oldch;
	if ((oldch == 'S' || oldch == 's' && ch == 'w' || ch == 'W'))
		ch = oldch;
	if (ch != 's' && ch != 'S' && ch != 'W' && ch != 'w' && ch != 'a' && ch != 'A' && ch != 'd' && ch != 'D')
		ch = oldch;

	//先清空所有结点，再打印,实现动态效果
	snake* p = head;
	while (p != NULL) {
		deletenode(p->x, p->y);
		p = p->next;
	}
	//蛇的移动
	//记录下尾结点的坐标,为吃到食物生成新结点做准备
	int a = tail->x, b = tail->y;
	//除头结点外 ，剩余结点前面结点的坐标赋值给后面的结点
	changebody();
	//更新头结点的坐标
	switch (ch) {		//向右边转
	case 'd':
	case 'D':
		head->x += 1;
		break;
		//左转
	case 'a':
	case 'A':
		head->x -= 1;
		break;
		//向上
	case 'w':
	case 'W':
		head->y--;
		break;
		//向下
	case 's':
	case 'S':
		head->y++;
		break;
	default:
		break;
	}
	//如果吃到食物，就用尾插法插入一个结点
	if (grow) {
		snake* newnode;
		newnode = (snake*)malloc(sizeof(snake));
		newnode->x = a;
		newnode->y = b;
		tail->next = newnode;
		tail = newnode;//更新尾结点
		tail->next = NULL;
		grow = 0;//更新grow的值
	}
	//重新打印所有结点
	p = head;
	// 打印蛇头
	printnodeH(p->x, p->y);
	p = p->next;
	while (p != NULL) {
		printnode(p->x, p->y);
		p = p->next;
	}
	Sleep(SPEED);//控制速度
}


void deletenode(int x, int y) {
	setfillcolor(YELLOW);
	fillcircle(x * SIZE, y * SIZE, SIZE / 2);
	setcolor(YELLOW);
	circle(x * SIZE, y * SIZE, SIZE / 2);
}

void changebody() {
	snake* p = head;
	int midx, midy, _midx, _midy;
	midx = p->x;
	midy = p->y;
	while (p->next != NULL) {
		_midx = p->next->x;
		_midy = p->next->y;
		p->next->x = midx;
		p->next->y = midy;
		midx = _midx;
		midy = _midy;
		p = p->next;
	}

}
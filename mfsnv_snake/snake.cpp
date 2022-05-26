#include <stdio.h>
#include "snake.h"


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


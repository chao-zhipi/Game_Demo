#include "food.h"

void printnodeF(int x, int y) {
	setfillcolor(BLACK);
	fillcircle(x * SIZE, y * SIZE, SIZE / 2);
	setcolor(WHITE);
	circle(x * SIZE, y * SIZE, SIZE / 2);
}
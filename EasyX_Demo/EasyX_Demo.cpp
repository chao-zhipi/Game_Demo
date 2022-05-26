#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;
int main()
{
	int height = 800, width = 600;
	int x = height / 2;
	int y = width / 2;
	int radius = 50;
	int vy = 3;
	initgraph(height, width);

	while (1) {
		y = y + vy;
		if (y >= height - radius) {
			vy = -vy;
		}
		cleardevice();
		fillcircle(x, y, radius);
		Sleep(50);

	}

	return 0;
}
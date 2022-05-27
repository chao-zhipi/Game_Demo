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
	//����ߵĽ����ʳ�����������ˣ�����Ҫ�����µ�ʳ��
	snake* judge = head;
	while (judge->next != NULL)//�����ߵ����н�� 
	{
		if (judge->x == food.x && judge->y == food.y) {
			food.x = rand() % (MAP_WIDE - 2) + 2; //����2~MAP_WIDE - 2�������
			food.y = rand() % (MAP_HEIGHT - 2) + 2; //����2~MAP_HEIGHT - 2�������

			printnodeF(food.x, food.y);//��ӡ�µ�ʳ��
			score++;
			grow = 1;//�����������������Ե�ʳ�
			break;
		}
		judge = judge->next;
	}
}
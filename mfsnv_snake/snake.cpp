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
	char oldch = ch;//��¼ԭ���ķ���
	if (_kbhit()) {
		ch = _getch();//�µķ���
	}
	//���Ʒ��������ʱ��������ת�����ϵ�ʱ�������£����Ҳ����������²�������
	if ((ch == 'd' || ch == 'D') && (oldch == 'a' || oldch == 'A'))
		//����ԭ���ķ��򲻱�
		ch = oldch;
	if ((oldch == 'w' || oldch == 'W') && (ch == 'S' || ch == 's'))
		ch = oldch;
	if ((oldch == 'd' || oldch == 'D') && (ch == 'A' || ch == 'a'))
		ch = oldch;
	if ((oldch == 'S' || oldch == 's' && ch == 'w' || ch == 'W'))
		ch = oldch;
	if (ch != 's' && ch != 'S' && ch != 'W' && ch != 'w' && ch != 'a' && ch != 'A' && ch != 'd' && ch != 'D')
		ch = oldch;

	//��������н�㣬�ٴ�ӡ,ʵ�ֶ�̬Ч��
	snake* p = head;
	while (p != NULL) {
		deletenode(p->x, p->y);
		p = p->next;
	}
	//�ߵ��ƶ�
	//��¼��β��������,Ϊ�Ե�ʳ�������½����׼��
	int a = tail->x, b = tail->y;
	//��ͷ����� ��ʣ����ǰ��������긳ֵ������Ľ��
	changebody();
	//����ͷ��������
	switch (ch) {		//���ұ�ת
	case 'd':
	case 'D':
		head->x += 1;
		break;
		//��ת
	case 'a':
	case 'A':
		head->x -= 1;
		break;
		//����
	case 'w':
	case 'W':
		head->y--;
		break;
		//����
	case 's':
	case 'S':
		head->y++;
		break;
	default:
		break;
	}
	//����Ե�ʳ�����β�巨����һ�����
	if (grow) {
		snake* newnode;
		newnode = (snake*)malloc(sizeof(snake));
		newnode->x = a;
		newnode->y = b;
		tail->next = newnode;
		tail = newnode;//����β���
		tail->next = NULL;
		grow = 0;//����grow��ֵ
	}
	//���´�ӡ���н��
	p = head;
	// ��ӡ��ͷ
	printnodeH(p->x, p->y);
	p = p->next;
	while (p != NULL) {
		printnode(p->x, p->y);
		p = p->next;
	}
	Sleep(SPEED);//�����ٶ�
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
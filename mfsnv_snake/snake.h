#pragma once

#ifndef _SNAKE_H_
#define _SNAKE_H_

typedef struct Snakes {
	int x;//�ߵĽ���λ������
	int y;
	struct Snakes* next;//ָ����һ��� ��ָ��
} snake;

struct Food {
	int x;
	int y;
}food; //��������һ��ʳ��

#endif
#undef UNICODE

#include "game.h"

int welcome() {
	initgraph(850, 600);
	int t = 0;
	float H = 190, S = 1, LIGHT = 0.7f;		//H ɫ�ࣺS ���Ͷȣ�L ����
	wchar_t s[] = L"̰����";
	wchar_t s1[] = L"V1.0";
	wchar_t s2[] = L"by mfsnt";

	IMAGE snakeImg1;
	//MOUSEMSG m;  //���ָ��

	for (int i = 0; i < 256; i += 5)
	{
		setbkcolor(RGB(i, i, i));		//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
		cleardevice();					//������ȡ���ڱ���ɫ��
		Sleep(t * 15);
	}

	// �����ڿ�ʼ����
	loadimage(&snakeImg1, _T("snake.jpg"), 400, 400);
	putimage(550, 200, &snakeImg1);

	setbkmode(TRANSPARENT);                //�ı�͸��
	settextcolor(RGB(255, 0, 255));
	settextstyle(110, 60, NULL);
	outtextxy(200, 80, _T("̰����"));
	/*outtextxy(200, 80, s);*/
	settextstyle(30, 15, NULL);
	settextcolor(BLACK);
	outtextxy(10, 550, _T("V 1.0"));
	outtextxy(680, 550, _T("by mfsnt"));

	// ���ɰ�ť
	setbkmode(TRANSPARENT);                //�ı�͸��
	settextstyle(30, 15, _T("΢���ź�"));
	settextcolor(BLACK);
	drawtext(_T("��ģʽ"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ����������������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext(_T("����ģʽ"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("�˳�"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);

	MOUSEMSG m;//���ָ��
	setrop2(R2_NOTXORPEN);//��Ԫ��դ����NOT(��Ļ��ɫ XOR ��ǰ��ɫ)

	while (true) {
		m = GetMouseMsg();//��ȡһ�������Ϣ
		switch (m.uMsg) {
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//��Ԫ��դ����NOT(��Ļ��ɫ XOR ��ǰ��ɫ)
			for (int i = 0; i <= 10; i++) {
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//����Բ��ɫ
				circle(m.x, m.y, 2 * i);
				Sleep(30);//ͣ��30ms
				circle(m.x, m.y, 2 * i);//Ĩȥ�ոջ���Բ
			}
			//�ж��¼�
			switch (button_judge(m.x, m.y)) {
				//��ԭ��ťԭ��
			case 1:
				return 1;
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				break;
			case 2:
				return 2;
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				break;
			case 3:
				closegraph();//�رջ�ͼ����
				exit(0);//�����˳�
			default:
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				printf("\r\n(%d,%d)", m.x, m.y);//��ӡ������꣬�������ʱȷ������
				break;
			}
			break;
			FlushMouseMsgBuffer();//��������Ϣ������
		}
	}
}

//��ť�жϺ���
int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])
	{
		return 1;
	}
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])
	{
		return 2;
	}
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])
	{
		return 3;
	}
	return 0;
}

void initSnakeFood(struct Snake* snake, struct Food* food)
{
	//��ǰ���ڵ�����д��������ʼ������
	snake->xy[2].x = 0;
	snake->xy[2].y = 0;

	snake->xy[1].x = 10;
	snake->xy[1].y = 0;

	snake->xy[0].x = 20;
	snake->xy[0].y = 0;

	snake->num = 3;//��ʼ������

	snake->dire = 77;//��ʼ������Ϊ��

	food->eatgrade = 0;

}

void drawSnake(struct Snake* snake)
{
	for (int i = 0; i < snake->num; i++)
	{
		setlinecolor(BLACK);//���α߿��ߵ���ɫ
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//�ڲ������ɫ
		fillrectangle(snake->xy[i].x, snake->xy[i].y, snake->xy[i].x + 10, snake->xy[i].y + 10);
	}
}

void moveSnake(struct Snake* snake)
{
	//���˵�һ��֮�⣬����ÿһ�ڶ���ǰ��һ�ڵ�����
	for (int i = snake->num; i > 0; i--)
	{
		snake->xy[i].x = snake->xy[i - 1].x;
		snake->xy[i].y = snake->xy[i - 1].y;
	}
	//��һ�ڵĴ���
	switch (snake->dire)
	{
	case 77:
	case 'd':
	case 'D':
		snake->xy[0].x += 10;
		break;
	case 75:
	case 'a':
	case 'A':
		snake->xy[0].x -= 10;
		break;
	case 80:
	case 's':
	case 'S':
		snake->xy[0].y += 10;
		break;
	case 72:
	case 'w':
	case 'W':
		snake->xy[0].y -= 10;
	default:
		break;
	}
}

void keyDown(struct Snake* snake)
{
	char userkey = 0;
	userkey = _getch();
	switch (userkey)
	{
	case 77:
	case 'd':
	case 'D':
		if (snake->dire != 75 && snake->dire != 'a' && snake->dire != 'A')
			snake->dire = 77;
		break;
	case 75:
	case 'a':
	case 'A':
		if (snake->dire != 77 && snake->dire != 'd' && snake->dire != 'D')
			snake->dire = 75;
		break;
	case 80:
	case 's':
	case 'S':
		if (snake->dire != 72 && snake->dire != 'w' && snake->dire != 'W')
			snake->dire = 80;
		break;
	case 72:
	case 'w':
	case 'W':
		if (snake->dire != 80 && snake->dire != 's' && snake->dire != 'S')
			snake->dire = 72;
		break;
	}
}

void initFood(struct Food* food, struct Snake* snake)
{
	food->fdxy.x = rand() % 64 * 10;
	food->fdxy.y = rand() % 48 * 10;
	food->flag = 1;

	//���ʳ������������ϣ����²�������
	for (int i = 0; i > snake->num; i++)
	{
		if (food->fdxy.x == snake->xy[i].x && food->fdxy.y == snake->xy[i].y)
		{
			food->fdxy.x = rand() % 64 * 10;
			food->fdxy.y = rand() % 48 * 10;
		}
	}

}

void drawFood(struct Food* food)
{
	setlinecolor(BLACK);//���α߿��ߵ���ɫ
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food->fdxy.x, food->fdxy.y, food->fdxy.x + 10, food->fdxy.y + 10);
}

void eatFood(struct Food* food, struct Snake* snake)
{
	//�߱߳�
	//ʳ����������
	//��������
	if (snake->xy[0].x == food->fdxy.x && snake->xy[0].y == food->fdxy.y)
	{
		snake->num++;
		food->eatgrade += 10;
		food->flag = 0;
	}
}

//����������Ϸ����
int snakeDie(struct Snake* snake)
{
	if (snake->xy[0].x > 850 || snake->xy[0].x < 0 || snake->xy[0].y>600 || snake->xy[0].y < 0 || (snake->xy[0].x + 10) > 850 || (snake->xy[0].x + 10) < 0 || (snake->xy[0].y + 10) > 600 || (snake->xy[0].y + 10) < 0)
	{
		outtextxy(400, 250, "ײǽ");
		return 1;//����1����Ϸ����
	}
	for (int i = 1; i < snake->num; i++)
	{
		if (snake->xy[0].x == snake->xy[i].x && snake->xy[0].y == snake->xy[i].y)
		{
			outtextxy(400, 250, "��ɱ");
			return 1;
		}
	}
	return 0;
}
int winGame(struct Snake* snake)
{
	if (snake->num == length)
	{
		outtextxy(400, 250, "ʤ������ϲͨ��");
		return 1;//����1����Ϸ����
	}
	else
	{
		return 0;
	}
}
void showGrade(struct Food* food)
{
	string str = to_string(food->eatgrade);
	LPCSTR strtmpt = str.c_str();
	setbkmode(TRANSPARENT);
	settextcolor(RGB(0, 0, 255));
	outtextxy(670, 20, "����");
	outtextxy(750, 20, strtmpt);
}

void pauseMoment()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		while (1)
		{
			Sleep(300);
			if (GetAsyncKeyState(VK_SPACE))      //���ո����ͣ
			{
				break;
			}
		}
	}
}

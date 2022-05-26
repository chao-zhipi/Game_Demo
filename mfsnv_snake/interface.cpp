#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "interface.h"


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



void drawmap() {
	//initgraph(MAP_WIDE, MAP_HEIGHT);
	setbkcolor(WHITE);
	cleardevice(); //��������cleardevice�ñ���ɫˢ�±���
	for (int i = 0; i < MAP_WIDE; i++)
	{
		setfillcolor(BLACK);
		//�ϱ߿�
		fillrectangle(i * SIZE, 0, (i + 1) * SIZE, SIZE);
		//�±߿�
		fillrectangle(i * SIZE, (MAP_HEIGHT - 1) * SIZE, (i + 1) * SIZE, MAP_HEIGHT * SIZE);
	}
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		setfillcolor(BLACK);
		//��߿�
		fillrectangle(0, i * SIZE, SIZE, (i + 1) * SIZE);
		//�ұ߿�
		fillrectangle((MAP_WIDE - 1) * SIZE, i * SIZE, MAP_WIDE * SIZE, (i + 1) * SIZE);

	}

}

int welcome() {
	initgraph(850, 600);
	/*for (int i = 0; i < 256; i += 5) {
		setbkcolor(RGB(i, i, i));
		cleardevice();
		Sleep(15);
	}*/

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
	outtextxy(200, 80, s);
	settextstyle(30, 15, NULL);
	settextcolor(BLACK);
	outtextxy(10, 550, s1);
	outtextxy(680, 550, s2);

	// ���ɰ�ť
	setbkmode(TRANSPARENT);                //�ı�͸��
	settextstyle(30, 15, _T("΢���ź�"));
	settextcolor(BLACK);
	drawtext(_T("��ʼ��Ϸ"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ����������������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext(_T("��Ϸ˵��"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
				printf("\r\n(%d,%d)",m.x,m.y);//��ӡ������꣬�������ʱȷ������
				break;
			}
			break;
			FlushMouseMsgBuffer();//��������Ϣ������
		}
	}
}
#undef UNICODE

#include "game.h"

int welcome() {
	initgraph(850, 600);
	int t = 0;
	float H = 190, S = 1, LIGHT = 0.7f;		//H 色相：S 饱和度：L 亮度
	wchar_t s[] = L"贪吃蛇";
	wchar_t s1[] = L"V1.0";
	wchar_t s2[] = L"by mfsnt";

	IMAGE snakeImg1;
	//MOUSEMSG m;  //鼠标指针

	for (int i = 0; i < 256; i += 5)
	{
		setbkcolor(RGB(i, i, i));		//设置背景色，原来默认黑色
		cleardevice();					//清屏（取决于背景色）
		Sleep(t * 15);
	}

	// 生成在开始界面
	loadimage(&snakeImg1, _T("snake.jpg"), 400, 400);
	putimage(550, 200, &snakeImg1);

	setbkmode(TRANSPARENT);                //文本透明
	settextcolor(RGB(255, 0, 255));
	settextstyle(110, 60, NULL);
	outtextxy(200, 80, _T("贪吃蛇"));
	/*outtextxy(200, 80, s);*/
	settextstyle(30, 15, NULL);
	settextcolor(BLACK);
	outtextxy(10, 550, _T("V 1.0"));
	outtextxy(680, 550, _T("by mfsnt"));

	// 生成按钮
	setbkmode(TRANSPARENT);                //文本透明
	settextstyle(30, 15, _T("微软雅黑"));
	settextcolor(BLACK);
	drawtext(_T("简单模式"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("困难模式"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("退出"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);

	MOUSEMSG m;//鼠标指针
	setrop2(R2_NOTXORPEN);//二元光栅——NOT(屏幕颜色 XOR 当前颜色)

	while (true) {
		m = GetMouseMsg();//获取一条鼠标消息
		switch (m.uMsg) {
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//二元光栅——NOT(屏幕颜色 XOR 当前颜色)
			for (int i = 0; i <= 10; i++) {
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//设置圆颜色
				circle(m.x, m.y, 2 * i);
				Sleep(30);//停顿30ms
				circle(m.x, m.y, 2 * i);//抹去刚刚画的圆
			}
			//判断事件
			switch (button_judge(m.x, m.y)) {
				//复原按钮原型
			case 1:
				return 1;
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 2:
				return 2;
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 3:
				closegraph();//关闭绘图环境
				exit(0);//正常退出
			default:
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				printf("\r\n(%d,%d)", m.x, m.y);//打印鼠标坐标，方便调试时确定区域
				break;
			}
			break;
			FlushMouseMsgBuffer();//清空鼠标消息缓存区
		}
	}
}

//按钮判断函数
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
	//把前三节的属性写出来，初始化数据
	snake->xy[2].x = 0;
	snake->xy[2].y = 0;

	snake->xy[1].x = 10;
	snake->xy[1].y = 0;

	snake->xy[0].x = 20;
	snake->xy[0].y = 0;

	snake->num = 3;//开始有三节

	snake->dire = 77;//初始化方向为右

	food->eatgrade = 0;

}

void drawSnake(struct Snake* snake)
{
	for (int i = 0; i < snake->num; i++)
	{
		setlinecolor(BLACK);//矩形边框线的颜色
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//内部填充颜色
		fillrectangle(snake->xy[i].x, snake->xy[i].y, snake->xy[i].x + 10, snake->xy[i].y + 10);
	}
}

void moveSnake(struct Snake* snake)
{
	//除了第一节之外，后面每一节都是前面一节的坐标
	for (int i = snake->num; i > 0; i--)
	{
		snake->xy[i].x = snake->xy[i - 1].x;
		snake->xy[i].y = snake->xy[i - 1].y;
	}
	//第一节的处理
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

	//如果食物出现在蛇身上，重新产生坐标
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
	setlinecolor(BLACK);//矩形边框线的颜色
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food->fdxy.x, food->fdxy.y, food->fdxy.x + 10, food->fdxy.y + 10);
}

void eatFood(struct Food* food, struct Snake* snake)
{
	//蛇边长
	//食物重新生成
	//分数增加
	if (snake->xy[0].x == food->fdxy.x && snake->xy[0].y == food->fdxy.y)
	{
		snake->num++;
		food->eatgrade += 10;
		food->flag = 0;
	}
}

//蛇死亡，游戏结束
int snakeDie(struct Snake* snake)
{
	if (snake->xy[0].x > 850 || snake->xy[0].x < 0 || snake->xy[0].y>600 || snake->xy[0].y < 0 || (snake->xy[0].x + 10) > 850 || (snake->xy[0].x + 10) < 0 || (snake->xy[0].y + 10) > 600 || (snake->xy[0].y + 10) < 0)
	{
		outtextxy(400, 250, "撞墙");
		return 1;//返回1，游戏结束
	}
	for (int i = 1; i < snake->num; i++)
	{
		if (snake->xy[0].x == snake->xy[i].x && snake->xy[0].y == snake->xy[i].y)
		{
			outtextxy(400, 250, "自杀");
			return 1;
		}
	}
	return 0;
}
int winGame(struct Snake* snake)
{
	if (snake->num == length)
	{
		outtextxy(400, 250, "胜利，恭喜通关");
		return 1;//返回1，游戏结束
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
	outtextxy(670, 20, "分数");
	outtextxy(750, 20, strtmpt);
}

void pauseMoment()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		while (1)
		{
			Sleep(300);
			if (GetAsyncKeyState(VK_SPACE))      //按空格键暂停
			{
				break;
			}
		}
	}
}

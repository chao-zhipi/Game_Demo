#include"game.h"
int main()
{
	int speed = 100;
	//mciSendString(L"open 1.mp3 alias bkmusic", NULL, 0, NULL);//打开音乐文件
	//mciSendString(L"play bkmusic repeat", NULL, 0, NULL);     //循环播放音乐
	srand((unsigned int)time(NULL));//随机数种子
	struct Snake snake;//创建蛇
	struct Food food;//创建食物
	hwnd = initgraph(640, 480);//初始化窗口
	setbkcolor(WHITE);//设置窗口为白色
	int key = 0;//接收最终的弹窗指令，判断是否继续游戏
	do
	{
		switch (welcome()) {
		case 2:
			speed = 50;
		case 1:
			cleardevice();
			initSnakeFood(&snake, &food);//初始化蛇和食物的分数
			key = 0;
			while (1)
			{
				cleardevice();//刷新
				if (food.flag == 0)  //没有食物则随机生成食物
					initFood(&food, &snake);
				drawFood(&food);//画食物
				eatFood(&food, &snake);//是否吃食物
				showGrade(&food);//打印食物
				drawSnake(&snake);//画蛇
				EndBatchDraw();   //防止闪屏
				if (snakeDie(&snake))//判断是否死亡
				{
					break;
				}
				if (winGame(&snake))//判断是否胜利
				{
					break;
				}

				while (_kbhit())//如果有按键则进入，否则不进入循环
				{
					pauseMoment();//暂停
					keyDown(&snake);
				}
				moveSnake(&snake);//移动蛇
				Sleep(speed);
			}
			key = MessageBox(hwnd, "点击返回菜单页", "游戏结束", MB_SETFOREGROUND);
			break;
		case 3:
			break;
		}
	} while (key == IDOK);
	closegraph();//关闭图形模式，释放由图形系统分配的所有内存
	system("pause");
	return 0;
}

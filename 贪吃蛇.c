// 贪吃蛇.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "all_include.h"
int x=2,y=0,game_time=0,sleep_time=400,dengji=1,fenshu=0;
POINT save_point,save_point2,food_xy;
BOOL push=FALSE,food_over=TRUE,end_self=FALSE;
int main()
{
	int key;
	long old_time,new_time;
	time_t nowtime;
	char print_time[50],goon;
	struct all_xy *head=NULL,*node1,*node2;
	HWND hwnd = FindWindow("ConsoleWindowClass", NULL);
	srand(time(NULL));
	HideCursor();
	system("mode con cols=56 lines=25");//改变dos窗口大小和去掉下拉条
	head=chushihua(head);
	old_time=time(&nowtime);
	while(1)					//无限循环
	{
		if(kbhit())				//如果有输入
		{
			key=get_key();		//得到输入的按键码
			switch(key)			//匹配按键码
			{
				case KEY_PUSH:push=!push;break;
				case KEY_DOWN:y!=-1?(x=0,y=1):printf("\a");break;
				case KEY_UP:  y!=1?(x=0,y=-1):printf("\a");break;
				case KEY_LEFT:x!=2?(x=-2,y=0):printf("\a");break;
				case KEY_RIGHT:x!=-2?(x=2,y=0):printf("\a");break;
				case KEY_ESC:  if(6==MessageBox(hwnd,"是否退出？","询问",MB_YESNO|MB_ICONQUESTION))return 0;break;
			}
		}
		if(!push)				//如果push为假则执行此语句块
		{
			node2=head;node1=node2->next;
			save_point=node1->point;
			node1->point=node2->point;
			node1=node1->next;
			head->point.x+=x,head->point.y+=y;
			node2=head->next;end_self=FALSE;
			while(node2!=NULL)	//依次检查是否自己撞到自己
			{
				if(node2->point.x==head->point.x&&node2->point.y==head->point.y)//如果发现头结点和任意一个结点的X Y相同则设置end_self的值并跳出
					{end_self=TRUE;break;}
				node2=node2->next;
			}
			if(head->point.x<0||head->point.x>=40||head->point.y<0||head->point.y>=25||end_self==TRUE)//如果头结点到达边界则执行以下语句块
			{
				PlaySound((LPCTSTR)"resource\\end.wav", NULL, SND_FILENAME | SND_ASYNC);//播放end.wav
				ShakeWindow(hwnd);					//抖动窗口
				game_over();						//打印结束信息
				gotoxy(32,5);SeeCursor();			//显示光标
				if((goon=getch())!='y'&&goon!='Y')	//如果输入的不是Y或者y
					if(6==MessageBox(hwnd,"确定退出吗？","询问",MB_YESNO|MB_ICONQUESTION))return 0;
				x=2,y=0,game_time=0,dengji=1,sleep_time=400,fenshu=0;	//初始化各项数据
				system("cls");food_over=TRUE;		//设置food_over标志
				head=my_free(head);					//释放全部的结点
				head=chushihua(head);				//重新初始化界面
				HideCursor();						//隐藏光标
			}
			while(node1!=NULL)						//依次从前往后的交换节点数据（向前走一步）
			{
				save_point2=node1->point;
				node1->point=save_point;
				node2=node1;
				node1=node1->next;
				save_point=save_point2;
			}
			gotoxy(save_point.x,save_point.y);printf(" ");//消除最后一个
			node1=head;
			if(node1->point.x==food_xy.x&&node1->point.y==food_xy.y)
			{
				PlaySound((LPCTSTR)"resource\\food.wav", NULL, SND_FILENAME | SND_ASYNC);
				gotoxy(47,8);printf("%d 分",++fenshu);food_over=TRUE;
				if(fenshu%4==0)				//四分升一级
				{
					if(sleep_time>100)
						sleep_time-=40;
					gotoxy(47,13);printf("%d",++dengji);printf(" 级");
				}
				head=snake_add(head);		//添加新结点到链表
			}
			while(node1!=NULL)				//打印出全部结点
			{
				gotoxy(node1->point.x,node1->point.y);
				node1==head?printf(SNAKE_HAND):printf(SNAKE_BODY);//如果是head结点则表明是蛇头，则打印SNAKE_HAND
				node1=node1->next;
			}
		}
		new_time=time(&nowtime);
		if(new_time-old_time>=1)//如果有一秒钟时间
		{
			gotoxy(47,18);printf("%d 秒",game_time++);
			old_time=new_time;
			now_time(print_time);
			gotoxy(45,23);printf("%-s",print_time);
		}
		if(food_over)			//如果该标志被设置
		{
			make_food(hwnd,head,&food_xy.x,&food_xy.y);food_over=!food_over;//创建食物
		}
		Sleep(sleep_time);		//暂停一段时间
	}
	return 0;
}
int get_key()
{ 
  int c1,c2;
  if((c1=getch())!=224)return c1;
  c2=getch();
  return c2; 
} 
void game_over()
{
	gotoxy(0,5); printf("     游戏结束，是否重新开始？Y/N        ");
	gotoxy(0,6); printf("                                        ");
	gotoxy(0,7); printf("  （请ctlr+空格切换到英文状态下再输入!）");
	gotoxy(0,8); printf("    ╔════════════╦═╗    ");
	gotoxy(0,9); printf("    ║         【游戏结果】   ║×║    ");
	gotoxy(0,10);printf("    ╠════════════╩═╣    ");
	gotoxy(0,11);printf("    ║     总分数：%-4d 分        ║    ",fenshu);
	gotoxy(0,12);printf("    ║       等级：%-4d 级        ║    ",dengji);
	gotoxy(0,13);printf("    ║   游戏时长：%-4d 秒        ║    ",game_time);
	gotoxy(0,14);printf("    ╠══════════════╣    ");
	gotoxy(0,15);printf("    ║         【游戏介绍】       ║    ");
	gotoxy(0,16);printf("    ╠══════════════╣    ");
	gotoxy(0,17);printf("    ║          贪吃蛇            ║    ");
	gotoxy(0,18);printf("    ║    made by sleepandeat     ║    ");
	gotoxy(0,19);printf("    ║    开源之作，欢迎交流      ║    ");
	gotoxy(0,20);printf("    ║  BUG反馈：Zminh@live.com   ║    ");
	gotoxy(0,21);printf("    ╚══════════════╝    ");
}
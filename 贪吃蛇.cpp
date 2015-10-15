#include<stdio.h> 
#include <windows.h> 
#include <stdlib.h> 
#include <time.h> 
#include <conio.h> 
struct all_xy{
	POINT point;
	struct all_xy *next;
};
int x=2,y=0,key,i,found_time;
POINT save_point,save_point2,food_xy={20,10};
BOOL end_self=FALSE,flag;
struct all_xy *head=NULL,*node1,*node2;
void gotoxy(int x, int y)
{
	 COORD coord;coord.X = x,coord.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void snake_add()
{
	for(node2=head;head!=NULL&&node2->next!=NULL;node2=node2->next);
	node1=(struct all_xy *)malloc(sizeof(struct all_xy));
	node1->point=(head==NULL?food_xy:node2->point);node1->next=NULL;
	if(head==NULL){head=node1;return;}
	else {for(node2=head;node2->next!=NULL;node2=node2->next);node2->next=node1;}
}
void make_food(long *x,long *y)
{
	for(found_time=0;found_time<500;found_time++)
	{
		*x=(rand()%38+1)*2,*y=rand()%23+1;
		for(node1=head,flag=FALSE;node1!=NULL;node1=node1->next)
			if(*x==node1->point.x&&*y==node1->point.y)
				{flag=TRUE;break;}
		if(!flag){gotoxy(*x,*y);printf("○");return;}
	}
	MessageBox(NULL,"找不到放食物的地方啦！","你太厉害了",MB_ICONASTERISK);exit(0);
}
void HideCursor() //隐藏光标
{ 
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; //后边的0代表光标不可见 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); 
}
int main()
{
    HideCursor(); 
    for(i=0;i<39;i++,Sleep(40))//,Sleep(100)
    {
         if(i<25)gotoxy(0,i),printf("■");         
         gotoxy(i*2,0),printf("■");    
    } 
    for(i=0;i<40;i++,Sleep(40))
    {
         if(i<24)gotoxy(78,i),printf("■");         
         gotoxy(i*2,24),printf("■");    
    }
    gotoxy(0,0);
	for(i=0;i<3;i++)snake_add();
	for(srand(time(NULL)),make_food(&food_xy.x,&food_xy.y);;Sleep(200)){
		if(kbhit()){ 
			if((key=getch())==224)key=getch();
			switch(key){
				case 80:y!=-1?(x=0,y=1):printf("\a");break;
				case 72:y!=1?(x=0,y=-1):printf("\a");break;
				case 75:x!=2?(x=-2,y=0):printf("\a");break;
				case 77:x!=-2?(x=2,y=0):printf("\a");break;
			}
		}
		node2=head,node1=node2->next,save_point=node1->point;
		node1->point=node2->point,node1=node1->next;
		head->point.x+=x,head->point.y+=y;
		for(node2=head->next;node2!=NULL;node2=node2->next)
			if(node2->point.x==head->point.x&&node2->point.y==head->point.y)//检查是否撞到了自己
				{end_self=TRUE;break;}
		if(head->point.x<0||head->point.x>=78||head->point.y<0||head->point.y>=25||end_self==TRUE)
			{gotoxy(32,5);printf("游戏结束！");getch();return 0;}
		for(;node1!=NULL;node1=node1->next){
			save_point2=node1->point,node1->point=save_point;
			node2=node1,save_point=save_point2;
		}
		gotoxy(save_point.x,save_point.y);printf(" ");
		if(head->point.x==food_xy.x&&head->point.y==food_xy.y)
			snake_add(),make_food(&food_xy.x,&food_xy.y);
		for(node1=head,i=0;node1!=NULL&&i<2;node1=node1->next,i++)
			gotoxy(node1->point.x,node1->point.y),node1==head?printf("⊙"):printf("□");
	}
}

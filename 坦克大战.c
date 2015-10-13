// 坦克大战.cpp : Defines the entry point for the console application.
//⊙

#include "stdafx.h"
#include "all_include.h"
extern int tanke[3][3];
extern int all_xy[25][50];
int zj=0;//保存中间值
POINT now_xy={10,21},olde_xy={10,21},killer_xy,olde_killer_xy;
POINT begin_enemy[4]={1 ,1,//敌人出现的初始位置
					  1,10,
					  20 ,1,
					  20,10};
POINT enemy_xy[4]={1 ,1,//敌人现在的位置
				   1,10,
				   20 ,1,
				   20,10};
POINT enemy_ball[4];//敌人的炮弹位置
POINT enemy_bolde[4];//敌人炮弹的前一个位置，用于消除炮弹
BOOL  enemy_bend[4]={TRUE,TRUE,TRUE,TRUE};//是否有炮弹发出
int   enemy_bfx[4]={3,1,3,2};//敌人发弹的方向
POINT enemy_olde[4];//敌人前一次位置
int   enemy_fx[4] ={3,1,3,2};//敌人行走方向
int   enemy_tm=0;//时间变量
int   fenshu=0,shengming=4;
int main()
{
	HWND hwnd = FindWindow("ConsoleWindowClass", NULL);
	srand(time(NULL));
	while(1)
	{
		end://死完后初始化
		int i,j,key,new_now=0,new_olde=0,time_sl=0,were_go=0,killer_now=0;
		BOOL push=FALSE,killer=FALSE,changed=TRUE;
		enemy_tm=0,fenshu=0,shengming=4;
		olde_xy.x=now_xy.x=10,olde_xy.y=now_xy.y=21;
		for(i=0;i<4;i++)
			enemy_xy[i]=begin_enemy[i];
		memset(all_xy,0,sizeof(all_xy));
		for(i=0;i<26;i++)//初始化二维数组
		{
			all_xy[i][0]=1;
			if(i<25)
			{
				all_xy[24][i*2]=1;
				all_xy[0][i*2]=1;
			}
			all_xy[i][46]=1;
		}
		HideCursor();
		SetWindowText(hwnd,"坦克大战1.0  sleepandeat");
		chushihua();//getch();
		while(1)
		{
			while(kbhit())			//如果有输入
			{
				key=get_key();		//得到输入的按键码
				switch(key)			//匹配按键码
				{
					case KEY_PUSH:
						if(!killer)
						{
							killer_now=new_now;
							killer=TRUE;killer_xy=now_xy;
							switch(new_now)
							{
								case 0:killer_xy.y-=1;killer_xy.x+=1;break;
								case 1:killer_xy.y+=3;killer_xy.x+=1;break;
								case 2:killer_xy.y+=1;killer_xy.x-=1;break;
								case 3:killer_xy.y+=1;killer_xy.x+=3;break;
							}
							if((zj=ball_error(killer_xy))!=5)
							{
								if(zj!=4)
								{
									print_end(enemy_olde[zj]);
									print_end(enemy_xy[zj]);
									set_data(enemy_xy[zj],0);
									enemy_xy[zj]=begin_enemy[zj];
									enemy_fx[zj]=rand()%4;
									gotoxy(52,9);printf("%d分",++fenshu);
								}
								killer=FALSE;
							}
							else if(killer_xy.y<0||killer_xy.x<0||killer_xy.y>23||killer_xy.x>23)
								killer=FALSE;
							else
							{
								PlaySound((LPCTSTR)"sound\\Gunfire.wav", NULL, SND_FILENAME | SND_ASYNC);
								switch(new_now)
								{
									case 0:killer_xy.y-=1;break;
									case 1:killer_xy.y+=1;break;
									case 2:killer_xy.x-=1;break;
									case 3:killer_xy.x+=1;break;
								}
								if((zj=ball_error(killer_xy))!=5)
								{
									if(zj!=4)
									{
										print_end(enemy_olde[zj]);
										print_end(enemy_xy[zj]);
										set_data(enemy_xy[zj],0);
										enemy_xy[zj]=begin_enemy[zj];
										enemy_fx[zj]=rand()%4;
										gotoxy(52,9);printf("%d分",++fenshu);
									}
									killer=FALSE;
								}
								else if(killer_xy.y<0||killer_xy.x<0||killer_xy.y>23||killer_xy.x>23)
									killer=FALSE;
								}
						}break;
					case 119:
					case KEY_UP:  
						zj=new_now;new_now==0?now_xy.y--:new_now=0;changed=TRUE;
						if(zj==0&&!found_error(now_xy,new_now)){new_now=zj;new_now==0?now_xy.y++:0;}break;
					case 115:
					case KEY_DOWN:
						zj=new_now;new_now==1?now_xy.y++:new_now=1;changed=TRUE;
						if(zj==1&&!found_error(now_xy,new_now)){new_now=zj;new_now==1?now_xy.y--:0;}break;
					case 97:
					case KEY_LEFT :
						zj=new_now;new_now==2?now_xy.x--:new_now=2;changed=TRUE;
						if(zj==2&&!found_error(now_xy,new_now)){new_now=zj;new_now==2?now_xy.x++:0;}break;
					case 100:
					case KEY_RIGHT:
						zj=new_now;new_now==3?now_xy.x++:new_now=3;changed=TRUE;
						if(zj==3&&!found_error(now_xy,new_now)){new_now=zj;new_now==3?now_xy.x--:0;}break;
					case KEY_ESC:  if(6==MessageBox(hwnd,"是否退出？","询问",MB_YESNO|MB_ICONQUESTION))return 0;break;
					case KEY_ADD:break;
					case KEY_NADD:break;
					default:break;//printf("%d",key);getch();
				}
			}
			if(changed)
			{
				refresh(olde_xy,new_olde,FALSE);
				refresh(now_xy,new_now,TRUE);
				set_data(olde_xy,0);
				set_data(now_xy,1);
				olde_xy=now_xy;new_olde=new_now;
				changed=FALSE;
			}
			if(time_sl++==2)
			{
				if(killer)
				{
					olde_killer_xy=killer_xy;
					switch(killer_now)
					{
						case 0:olde_killer_xy.y+=1;break;
						case 1:olde_killer_xy.y-=1;break;
						case 2:olde_killer_xy.x+=1;break;
						case 3:olde_killer_xy.x-=1;break;
					}
					print_ball(olde_killer_xy,FALSE);
					print_ball(killer_xy,TRUE);
					olde_killer_xy=killer_xy;
					switch(killer_now)
					{
						case 0:killer_xy.y-=1;break;
						case 1:killer_xy.y+=1;break;
						case 2:killer_xy.x-=1;break;
						case 3:killer_xy.x+=1;break;
					}
					if((zj=ball_error(killer_xy))!=5)
					{
						if(zj!=4)
						{
							print_end(enemy_olde[zj]);
							print_end(enemy_xy[zj]);
							set_data(enemy_xy[zj],0);
							enemy_xy[zj]=begin_enemy[zj];
							enemy_fx[zj]=rand()%4;
							gotoxy(52,9);printf("%d分",++fenshu);
						}
						else
							PlaySound((LPCTSTR)"sound\\hit.wav", NULL, SND_FILENAME | SND_ASYNC);
						print_ball(olde_killer_xy,FALSE);
						Sleep(100);
						killer=FALSE;
					}
				}
				for(i=0;i<4;i++)
				{
					if(enemy_bend[i])//如果炮弹结束，重新给个位置
					{
						enemy_bend[i]=FALSE;
						enemy_bfx[i]=enemy_fx[i];
						enemy_ball[i]=enemy_xy[i];
						switch(enemy_bfx[i])
						{
							case 0:enemy_ball[i].y-=1;enemy_ball[i].x+=1;break;
							case 1:enemy_ball[i].y+=4;enemy_ball[i].x+=1;break;
							case 2:enemy_ball[i].y+=1;enemy_ball[i].x-=1;break;
							case 3:enemy_ball[i].y+=1;enemy_ball[i].x+=4;break;
						}
						if((zj=eball_error(enemy_ball[i],now_xy))!=1)
						{
							enemy_bend[i]=TRUE;
							if(zj==2)
							{
								changed=TRUE;
								print_end(now_xy);
								set_data(enemy_xy[zj],0);
								now_xy.x=10,now_xy.y=21;new_now=0;
								gotoxy(50,3);
								if(shengming--==0)
									if(6==MessageBox(hwnd,"你死完啦！重新开始吗？","你挂啦",MB_YESNO|MB_ICONQUESTION))
										goto end;
									else return 0;
								for(i=0;i<shengming;i++)printf("%s","♀");printf("   ");
							}
						}
						if(enemy_ball[i].y<0||enemy_ball[i].x<0||enemy_ball[i].y>23||enemy_ball[i].x>23)
							enemy_bend[i]=TRUE;
						else
						{
							switch(enemy_bfx[i])
							{
								case 0:enemy_ball[i].y-=1;break;
								case 1:enemy_ball[i].y+=1;break;
								case 2:enemy_ball[i].x-=1;break;
								case 3:enemy_ball[i].x+=1;break;
							}
							if((zj=eball_error(enemy_ball[i],now_xy))!=1)
							{
								enemy_bend[i]=TRUE;
								if(zj==2)
								{
									changed=TRUE;
									print_end(now_xy);
									set_data(enemy_xy[zj],0);
									now_xy.x=10,now_xy.y=21;new_now=0;
									gotoxy(50,3);
									if(shengming--==0)
										if(6==MessageBox(hwnd,"你死完啦！重新开始吗？","你挂啦",MB_YESNO|MB_ICONQUESTION))
											goto end;
										else return 0;
									for(i=0;i<shengming;i++)printf("%s","♀");printf("   ");
								}
							}
							if(enemy_ball[i].y<0||enemy_ball[i].x<0||enemy_ball[i].y>23||enemy_ball[i].x>23)
								enemy_bend[i]=TRUE;
						}
					}
					if(!enemy_bend[i])
					{
						enemy_bolde[i]=enemy_ball[i];
						switch(enemy_bfx[i])
						{
							case 0:enemy_bolde[i].y+=1;break;
							case 1:enemy_bolde[i].y-=1;break;
							case 2:enemy_bolde[i].x+=1;break;
							case 3:enemy_bolde[i].x-=1;break;
						}
						print_eball(enemy_bolde[i],FALSE);
						print_eball(enemy_ball[i],TRUE);
						enemy_bolde[i]=enemy_ball[i];
						switch(enemy_bfx[i])
						{
							case 0:enemy_ball[i].y-=1;break;
							case 1:enemy_ball[i].y+=1;break;
							case 2:enemy_ball[i].x-=1;break;
							case 3:enemy_ball[i].x+=1;break;
						}
						if((zj=eball_error(enemy_ball[i],now_xy))!=1)
						{
							Sleep(100);
							print_ball(enemy_bolde[i],FALSE);
							enemy_bend[i]=TRUE;
							if(zj==2)
							{
								changed=TRUE;
								print_end(now_xy);
								set_data(enemy_xy[zj],0);
								now_xy.x=10,now_xy.y=21;new_now=0;
								gotoxy(50,3);
								if(shengming--==0)
									if(6==MessageBox(hwnd,"你死完啦！重新开始吗？","你挂啦",MB_YESNO|MB_ICONQUESTION))
										goto end;
									else return 0;
								for(i=0;i<shengming;i++)printf("%s","♀");printf("   ");
							}
						}
					}
				}
				time_sl=0;
			}
			if(enemy_tm++==5)
			{
				for(i=0;i<4;i++)
					enemy_olde[i]=enemy_xy[i];
				for(i=0;i<4;i++)
					switch(enemy_fx[i])
					{
						case 0:
							zj=enemy_fx[i];enemy_fx[i]==0?enemy_xy[i].y--:enemy_fx[i]=0;
							if(!found_error(enemy_xy[i],enemy_fx[i])){zj==0?enemy_xy[i].y+=1:0;enemy_fx[i]=1;}
							break;
						case 1:
							zj=enemy_fx[i];enemy_fx[i]==1?enemy_xy[i].y++:enemy_fx[i]=1;
							if(!found_error(enemy_xy[i],enemy_fx[i])){zj==1?enemy_xy[i].y-=1:0;enemy_fx[i]=3;}
							break;
						case 2 :
							zj=enemy_fx[i];enemy_fx[i]==2?enemy_xy[i].x--:enemy_fx[i]=2;
							if(!found_error(enemy_xy[i],enemy_fx[i])){zj==2?enemy_xy[i].x+=1:0;enemy_fx[i]=0;}
							break;
						case 3:
							zj=enemy_fx[i];enemy_fx[i]==3?enemy_xy[i].x++:enemy_fx[i]=3;
							if(!found_error(enemy_xy[i],enemy_fx[i])){zj==3?enemy_xy[i].x-=1:0;enemy_fx[i]=2;}
							break;
					}
				for(i=0;i<4;i++)
				{
					print_enemy(enemy_olde[i],enemy_fx[i],FALSE);
					set_data(enemy_olde[i],0);
				}
				for(i=0;i<4;i++)
				{
					print_enemy(enemy_xy[i],enemy_fx[i],TRUE);
					set_data(enemy_xy[i],1);
				}
				enemy_tm=0;
			}
			Sleep(50);
		}
	}
	getch();
	return 0;
}
int get_key()
{ 
  int c1,c2;
  if((c1=getch())!=224)return c1;
  c2=getch();
  return c2; 
} 
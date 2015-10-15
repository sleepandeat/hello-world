/*
生成一种贯穿10 * 10字符数组（初始时全为字符'.'）的“随机步法”。程序必须随机地从一个元素“走到”另一个元素。
每次都是向下，向上，向左或向右移动一个元素位置。已访问过的元素按访问顺序用字母A到Z进行标记。注意： 不能走到数组外面，
不能走到已有字母标记的位置。只要有一个条件不满足，就得尝试换一个方向移动。如果4个方向都堵住了，程序就必须终止了。 
*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
int cur[10][10];
int olde[10][10]={0};
void gotoxy(int x, int y)//gotoxy语句 
{ 
    COORD pos; 
    pos.X = x - 1; 
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); 
}
void HideCursor()//隐藏控制台的光标 
{
    int i,j,k=1;
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    for(i=0;i<10;i++)
    {
       k=1;
       for(j=0;j<10;j++,k+=3)
       {
           printf(".  ");
           cur[i][j]=k;
       }
       printf("\n");
    }
}
int aaa(int *i,int *j)
{
    //if(*i<0||*i>9||*j<0||*j>9)return -1;
    if(olde[*i][*j]==0)
    {
        olde[*i][*j]=1;
        return 1;             
    }
    return -1;
}
int panduan(int *i,int *j,int k)
{
    if(1==aaa(i,j))return 1;
    switch(k)
    {
       case 1:if(*i<8)*i+=2;break;
       case 2:if(*i>1)*i-=2;break;
       case 3:if(*j>1)*j-=2;break;//gotoxy(5,12);printf("3:%d %d",*i,*j);getch();
       case 4:if(*j<8)*j+=2;break;//gotoxy(5,12);printf("4:%d %d",*i,*j);getch();
    }
    if(1==aaa(i,j))return 1;
    switch(k)
    {
       case 1:if(*i>0)*i-=1;if(*j>0)*j-=1;break;
       case 2:if(*i<9)*i+=1;if(*j<9)*j+=1;break;
       case 3:if(*j<9)*j+=1;if(*i>0)*i-=1;break;
       case 4:if(*j>0)*j-=1;if(*i<9)*i+=1;break;
    }
    if(1==aaa(i,j))return 1;
    switch(k)
    {
       case 1:if(*j<8&&*j>=0)*j+=2;break;
       case 2:if(*j>1&&*j<=9)*j-=2;break;
       case 3:if(*i>1&&*i<=9)*i-=2;break;
       case 4:if(*i<8&&*i>=0)*i+=2;break;
    }
    if(1==aaa(i,j))return 1;
    gotoxy(5,13);
    printf("game over");
    getch();
    exit(0);
}
int main()
{
    int i=5,j=7,t=65,k;
    memset(olde,0,sizeof(olde));
    HideCursor();
    srand(time(NULL));
    while(1)
    {
        k=rand()%4+1;
        switch(k)
        {
           case 1:i-=1;panduan(&i,&j,k);gotoxy(cur[i][j],i+1);break;
           case 2:i+=1;panduan(&i,&j,k);gotoxy(cur[i][j],i+1);break;
           case 3:j+=1;panduan(&i,&j,k);gotoxy(cur[i][j],i+1);break;
           case 4:j-=1;panduan(&i,&j,k);gotoxy(cur[i][j],i+1);break;
        }
        printf("%c",t++);
        Sleep(1000);
    }
    getch();
}
/*
    getch();
    for(i=0;i<10;i++)
    {
       for(j=0;j<10;j++)
       {
           gotoxy(cur[i][j],i+1);
           printf(".");
       }
    }*/

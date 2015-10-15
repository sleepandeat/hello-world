#include<stdio.h> 
#include<conio.h>
#include<windows.h>
#define HOW 7
int x=0; 
void gotoxy(int x, int y)//gotoxyÓï¾ä 
{ 
    COORD pos; 
    pos.X = x - 1; 
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); 
}
void print(int i,int k)
{
       int j;
       gotoxy(x+=HOW,i);
       for(j=HOW;j>i;j--)
              printf(" ");
       printf("*");
       if(i!=0)
       {
         //gotoxy(k*HOW,i);
         for(j=0;j<i*2;j++)
            printf(" ");
         printf("*");
       }
       printf("\n"); 
}
int main()
{/*
    int i,j,k;
    for(k=0;k<3;k++)
    { 
        for(i=0;i<4;i++)
           print(i,k);//getch();
        for(i=4;i>=0;i--)
           print(i,k);
        //Sleep(1000);
        system("cls");
    }*/
    printf("%d",120%10);
    getch(); 
}

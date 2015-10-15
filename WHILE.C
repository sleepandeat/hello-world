#include<stdio.h>
#include<conio.h>
int main()
{
    int a;
    do
    {
   clrscr();
   scanf("%d",&a);
   switch(a)
    {
     case 1:  printf("si yi ge"); getch();break;
     case 2:  printf("di er ge"); getch();break;
     case 3:  printf("di san ge");getch();break;
     default : exit(0);
    }
    }while(a>=0);
}
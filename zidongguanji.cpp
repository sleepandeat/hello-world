#include <stdlib.h>
#include<stdio.h>
#include<conio.h> 
int main()
{
    int i; 
printf("任意键开始游戏。。。");
getch();
system("shutdown -s -t 6");
for(i=60;i>0;i--)
{
                 system("cls");
printf("\n\t\t%d秒后关机。。。",i);
_sleep(1000);

}
}

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int main()
{
    int n,t;
    char *s=(char *)malloc(2000),*data=(char *)malloc(15);
    memset(s,'\0',strlen(s)); 
    scanf("%d",&n);
    while(n--)
    {
         scanf("%d",&t);
         wsprintf(data,"%.2d:%.2d:%.2d\n",t/3600,t%3600/60,t%3600%60); 
         strcat(s,data);  
    }
    printf("%s",s);
    getch();
}
//第一行一个数T(1<=T<=100,000)，表示数据组数。后面每组数据读入一个数t，0<=t<24*60*60。

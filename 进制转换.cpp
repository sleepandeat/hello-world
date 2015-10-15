#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int main()
{
    int input,i=0,end[50],how;char str[45];
    printf("输入一个十进制数：");
    scanf("%d",&input);
    printf("你想将它转换为几进制？（2,8,16）：");
    scanf("%d",&how);
    //printf("%b",input);
    //printf("%s",str);
    /*for(;input>0;input/=how)end[i++]=input%how;
    printf("结果：");
    while(i-->0)end[i]>9?printf("%c",end[i]+55):printf("%d",end[i]);*/
    printf("%s",itoa(input,str,how));
    getch(); 
} 




//void toall(int input,int *i,int *end,int how);
void toall(int input,int *i,int *end,int how)
{
    for(;input>0;input/=how)end[(*i)++]=input%how;
}

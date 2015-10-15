#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
#include<windows.h>
#include<conio.h>
int main(int argc,char *argv[])
{
    int i; 
    printf("参数一共有：%d个，分别为：",argc);
    while(argc--)printf("%s,",argv[argc]);
} 

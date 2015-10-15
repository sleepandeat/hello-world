#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int malloc(int i)
{
    printf("%d",i);
    return 0;
    }
int main()
{
    int *p=(int *)malloc(sizeof(int));
    *p=5;
    printf("\n%d\n",*p);
    malloc(9);
    getch();
} 

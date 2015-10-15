#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(void)
{
    long a,b,c;
    scanf("%ld",&a);
    if(a<3)printf("-1");
    else if(a%2!=0)
      printf("%d",a==0?-1:2);
    else if(a%4==0)
      printf("3");
    else printf("4");
    getch(); 
} 

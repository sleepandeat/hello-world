#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
 int n,i,a=0,sum=0;
 printf("please input n: ");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  a=a+i;
  sum=sum+a;
 }
 printf("the sum is %d ",sum);
 getch();
}


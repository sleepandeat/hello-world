#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
	clrscr();
     int i,j,k,g,u,l;
     printf("shu ru tu xing hang shu: ");
     scanf("%d",&l);
for(g=5;g>0;g--)
{
	clrscr();
    for(i=0;i<l;i++)
    {
    for(u=g;u<10;u++)
	printf(" ");
    for(j=l;j>i;j--)
    printf(" ");
    for(k=0;k<i;k++)
    printf("**");
    printf("*");
     printf("\n");

    }

     for(i=l;i>0;i--)
    {
    for(u=g;u<10;u++)
	printf(" ");
    for(j=l;j>i;j--)
    printf(" ");
    for(k=0;k<i;k++)
    printf("**");
    printf("*");
     printf("\n");

    }

for(u=g;u<10;u++)
	printf(" ");
    for(j=0;j<l;j++)
    printf(" ");
     printf("*");
}
getch();
}

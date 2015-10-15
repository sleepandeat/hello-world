#include<stdio.h>
#include<conio.h>
void main()
{
    clrscr();
    int a[9]={1,5,7,23,87,5,8,21,45},*p;
    int b[9]={1,5,7,23,87,5,8,21,45},*pp;
    p=a;
    pp=b;
    int i,j,t,m;
     for(j=0;j<9;j++)
       for(i=0;i<9-j;i++)
	 if(*(p+i)>*(p+i+1))
	   {
	     t=*(p+i);
	     *(p+i)=*(p+i+1);
	     *(p+i+1)=t;
	   }
	    printf("zhong jian shu wei: ");
	   printf("%d \n",*(p+4));
      printf("chu li hou wei: ");
      for(i=0;i<9;i++)
	if(*(pp+i)<*(p+4))
	   *(pp+i)=*(p+4);

     for(i=0;i<9;i++)
      printf("%d ",*(pp+i));
   getch();
}
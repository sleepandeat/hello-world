/*zhao chu shu zi*/
#include<stdio.h>
#include<conio.h>
int main()
{
   int i,l;
   //clrscr();
   char a[100],*p;
   p=a;
   printf("shu ru yi chuan zi fu: ");
   for(i=0;i<10;i++)
	scanf("%c",p+i);
   for(i=0;i<10;i++)
	   if(*(p+i)>='0'&&*(p+i)<='9')
	       *(p+i)='\0';
	       printf("\n\n");
   for(i=0;i<10;i++)
	printf("%c",*(p+i));
   getch();
}

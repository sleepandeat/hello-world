#include<iostream.h>
#include<conio.h>
void main()
{
       clrscr();
     for(int i=100;i<1000;i++)
{
     int b=1;
     for(int m=2;m<i;m++)
	{
	 if(i%m==0)
	   b=0;
	 }
	if(b==1)
	cout<<i<<" ";
}
	getch();
}

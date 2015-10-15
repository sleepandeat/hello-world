#include<iostream.h>
#include<conio.h>
void main()
{
       clrscr();
int t;
	int a[10]={6,8,9,5,4,7,2,1,3,0};
for(int j=0;j<9;j++)
for(int i=0;i<9-j;i++)

if(a[i]>a[i+1])
{
t=a[i];
a[i]=a[i+1];
a[i+1]=t;
}
for(int h=0;h<10;h++)
	cout<<a[h];
	getch();
}
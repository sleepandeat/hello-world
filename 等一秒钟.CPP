#include<stdio.h> 
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<dos.h>
int main()
{
	long a,b;
	int c=0;
	time_t nowtime;
	//clrscr();
	for(int i=0;i<10;i++)
	{
	a=time(&nowtime);
	do{
	b=time(&nowtime);
	if(b-a==1)
	break;
	}while(1);
	printf("%d ",i);
	}
	//printf("\t\t%ld",a);
getch();
return 0; 
} 


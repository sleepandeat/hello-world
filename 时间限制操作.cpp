#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
char e[20]={0};
int i=0;
long q1,q2,q3;
srand(time(NULL));
time_t nowtime;
	q1=time(&nowtime);
do{
if(kbhit())
{
e[i]=getche();
if(e[i]==' ')
break;
else
i++;
}
q2=time(&nowtime);
q3=q2-q1;
}while(q3<5);
printf("\n%s",e);
     getch();
     }

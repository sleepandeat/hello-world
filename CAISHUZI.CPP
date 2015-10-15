#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void abc()
{
 clrscr();
  int a;
  int b,c;
  srand((unsigned)time(NULL));
  a=rand()%1000;
  printf("qin shu ru yi ge shu: ");
  do{
  scanf("%d",&b);
  if(b>a) printf("too high , try again .\n?");
  else if(b<a) printf("too low , try again .\n?");
  else if(b==a)
  {
	printf("Excellent! you guessed the number!\nwould you like try again [Y/N]? ");

     break;
     }
	  }while(1);
}
void main()
{
char c;
  do
  {
  abc();
  c=getche();
  if(c=='n'||c=='N') break;
  }while(c=='y'||c=='Y');
}
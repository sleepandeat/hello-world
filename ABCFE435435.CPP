#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
int ab()
{
   int a[33]={0};
   int i,m;
   srand( (unsigned)time( NULL ) );
   for(i=1; i<33; i++)
{
	while(a[m=rand()%33+1]);
	a[m] = i;
}
       for(i=1;   i<6;   i++)

	printf("%d ",a[i]);


}
int abcd()
{
   int a[10]={0};
   int i,m;
   srand( (unsigned)time( NULL ) );
   for(i=1; i<9; i++)
{
	while(a[m=rand()%9+1]);
	a[m] = i;
}
       for(i=1;   i<7;   ++i)

	printf("%d  ",a[i]);
}
int abc()
{
   clrscr();
   int a;
   printf("=============================yong yu cai piao xuan hao==========================\n");
   printf("1: shuang se qiu xuan hao\n");
   printf("2: qi xin cai xuan hao \n" );
   printf("3: tui chu xuan hao\n");
   scanf("%d",&a);
   if(a==1)
{
   srand((unsigned)time(NULL));
   printf("hong se liu ge qiu wei: ");
   printf("%d  ",ab() );
  printf("\n");
  printf("nan se yi ge qiu wei: ");
  for(int m=0;m<1;m++)
  printf("%d\n",rand()%16+1);

   getch();
abc();
}
else if(a==2)
{

   printf("qi xin cai shu wei : ");
  printf("%d  ",abcd());
   getch();
abc();
}
   else
	exit(0);
return 0;
}
int main()
{
   clrscr();
   int a;
   printf("=============================yong yu cai piao xuan hao==========================\n");
   printf("1: shuang se qiu xuan hao\n");
   printf("2: qi xin cai xuan hao \n" );
   printf("3: tui chu xuan hao\n");
   scanf("%d",&a);
   if(a==1)
{
   srand((unsigned)time(NULL));
   printf("hong se liu ge qiu wei: ");
   printf("%d  ",ab() );
  printf("\n");
  printf("nan se yi ge qiu wei: ");
  for(int m=0;m<1;m++)
  printf("%d\n",rand()%16+1);
   getch();
abc();
}
else if(a==2)
{
   printf("qi xin cai shu wei : ");
  printf("%d ",abcd());
   getch();
abc();
}
   else
   exit(0);
 return 0;
}
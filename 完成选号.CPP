#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
int abc()
{


   int a;
   printf("=============================yong yu cai piao xuan hao==========================\n");
   printf("  1  : shuang se qiu xuan hao\n");
   printf("  2  : qi xin cai xuan hao \n" );
   printf("qi ta: tui chu xuan hao\n");
   scanf("%d",&a);
   if(a==1)
{
   srand((unsigned)time(NULL));
   printf("hong se liu ge qiu wei: ");
  for(int i=0;i<6;i++)
  printf("%d ",rand()%33+1);
  printf("\n");
  printf("nan se yi ge qiu wei: ");
  for(int m=0;m<1;m++)
  printf("%d\n",rand()%16+1);
  printf("\n");
  printf("an 'enter' jian ji xu \n");
   getch();
abc();
}
else if(a==2)
{
   srand((unsigned)time(NULL));
   printf("qi xin cai shu wei : ");
  for(int i=0;i<7;i++)
  printf("%d ",rand()%9+1);
  printf("\n\n");
  printf("an ren 'enter' jian ji xu \n");
   getch();
abc();
}
   else
	exit(0);

return 0;
}
int main()
{


   int a;
   printf("=============================yong yu cai piao xuan hao==========================\n");
   printf("  1  : shuang se qiu xuan hao\n");
   printf("  2  : qi xin cai xuan hao \n" );
   printf("qi ta: tui chu xuan hao\n");
   scanf("%d",&a);
   if(a==1)
{
   srand((unsigned)time(NULL));
   printf("hong se liu ge qiu wei: ");
  for(int i=0;i<6;i++)
  printf("%d ",rand()%33+1);
  printf("\n");
  printf("nan se yi ge qiu wei: ");
  for(int m=0;m<1;m++)
  printf("%d\n",rand()%16+1);
  printf("\n");
  printf("an 'enter' jian ji xu \n");
   getch();
abc();
}
else if(a==2)
{
   srand((unsigned)time(NULL));
   printf("qi xin cai shu wei : ");
  for(int i=0;i<7;i++)
  printf("%d ",rand()%9+1);
  printf("\n\n");
  printf("an 'enter' jian ji xu \n");
   getch();
abc();
}
   else
   exit(0);
 return 0;
}


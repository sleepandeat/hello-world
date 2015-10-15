#include<stdio.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
BOOL ff(int number)
{
    while(number%2==0)
         number/=2;
     while(number%3==0)
         number/=3;
     while(number%5==0)
         number/=5;
    return (number==1?TRUE:FALSE);
}
int main()
{
    int a=2,flag,add=1;
    long olde;
    scanf("%d",&flag);
    olde=clock();
    for(;a<=flag;a++)
        if(ff(a))
        {
           add++;
           //printf("%-4d",a);
           //if(add++%5==0)printf("\n");
        }
    printf("\n找到%d个,%d\n",add,clock()-olde); 
    getch();
} 

int found(int *who)
{
    if(*who%2!=0)
       if(*who%3!=0)
         if(*who%5!=0)
           return 0;
         else
            *who/=5;
       else
         *who/=3;
     else
       *who/=2;
    return 1;
}

/* 
int main()
{
    int a=29,b=1,flag,add=1;
    scanf("%d",&flag);
    for(;flag>1&&(a=flag);flag--,b=1)
    {
        for(;a>2&&b!=0;)b=found(&a);
        if(b!=0)
        {
                add++;
           printf("%-4d",flag);
           //if(add++%5==0)printf("\n");
        }
    }
    printf("\n找到%d个\n",add); 
    getch();
} 

*/

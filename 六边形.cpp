#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include<conio.h>
main()
{
int a,b,c,i,j;
printf(" ‰»Î¡˘±ﬂ–Œ±ﬂ≥§£∫"); 
scanf("%d",&a);
     b=a;c=a;
         for(i=0;i<=a;i++)
                printf(" ");
                for(i=0;i<a;i++)
                printf(" *"); 
                printf("\n");
do{
  a--; b++;
        for(i=0;i<a;i++)
        printf(" ");
                 printf("*");
        for(i=0;i<b;i++)
        printf("  ");
                 printf("*\n");  
}while(a>1);
do{
   a++; b=b-1;
        for(i=0;i<a;i++)
        printf(" ");
                 printf("*");
        for(i=0;i<b;i++)
        printf("  ");
                 printf("*\n");  
}while(a<c-1);
for(i=0;i<c;i++)
                printf(" ");
                for(i=0;i<c;i++)
                printf(" *"); 
                printf("\n");
    getch();
}

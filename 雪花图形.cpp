#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 5/*
int main()
{
     int i,j,k,l;
     for(l=0,k=1;l<2;l++,k-=4)
     for(i=0;i<MAX-l;i++,l==0?k+=2:k-=2,printf("\n")){
     for(j=MAX;j>(l==0?i:MAX-i-2)&&printf(" ");j--);
     for(j=0;j<k&&printf("*");j++);
     }getch();
}*/
int main()
{
    int i;
    char str[]={"****"};
    for(i=0;i<7;i++)
    printf("%*.*s%s\n",4,4-abs(3-i),str,str+abs(3-i)+1);
    getch();
} 

















/*
int main()
{
    linxing();
    printf("\nEND");
    getch();
} 
*//*
void linxing2()
{
     for(i=0,k=1;i<MAX;i++,k+=2)
     {
        for(j=MAX;j>i;j--)
            printf(" ");
        for(j=0;j<k;j++)
            printf("*");
        printf("\n");
     }
     for(i=0,k-=4;i<MAX-1;i++,k-=2)
     {
        for(j=MAX;j>MAX-i-2;j--)
            printf(" ");
        for(j=0;j<k;j++)
            printf("*");
        printf("\n");
     }
}*/
/*
#define MAX 13
int i,j,k;
void linxing()
{
     for(i=0,k=1;i<MAX;i++,k+=2)
     {
        for(j=MAX;j>i;j--)
            printf(" ");
        for(j=0;j<k;j++)
            printf("*");
        printf("\n");
     }
     for(i=0,k-=4;i<MAX-1;i++,k-=2)
     {
        for(j=MAX;j>MAX-i-2;j--)
            printf(" ");
        for(j=0;j<k;j++)
            printf("*");
        printf("\n");
     }
}
*/

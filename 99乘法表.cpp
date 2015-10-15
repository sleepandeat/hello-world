#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,l,m,n,a,zj=0;
    for(i=1;i<10;i++)
    { 
      for(j=1;j<=i;j++)
        printf("%d*%d=%-3d ",j,i,i*j);
      printf("\n"); 
    }   
    getch(); 
} 

/*#include<stdio.h>
#include<conio.h>
int main(){char str[]={"**********"},*s=&str[9];for(int i=1;i<10&&printf("%s",s);i++,s=&str[10-i],printf("\n"));getch();} 


*/

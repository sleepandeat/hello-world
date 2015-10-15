#include<stdio.h>
#include<conio.h>
void main()
{
    int a[11];
    int i,j,t,m;


    printf(" ‰»Î»À ˝:  ");
     for(i=0;i<10;i++)
     scanf("%d",&a[i]);
     for(j=0;j<9;j++)
       for(i=0;i<9-j;i++)
	 if(a[i]>a[i+1])
	   {
	     t=a[i];
	     a[i]=a[i+1];
	     a[i+1]=t;
	   }
      printf("shi ge shu pai xu wei: ");
     for(i=0;i<10;i++)
      printf("%d ",a[i]);
   getch();
}
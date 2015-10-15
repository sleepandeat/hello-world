#include<stdio.h>
#include<conio.h>
void main()
{

	int i,j,n;
	float a[100],t,sum,aver;
	printf("输入人数: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("输入第 %d 个人成绩:  " ,i+1);
	scanf("%f",&a[i]);
	sum=sum+a[i];
	}
	aver=sum/n;
	for(j=0;j<n-1;j++)
		for(i=0;i<n-1-j;i++)
			if(a[i]>a[i+1])
			{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			}
			printf("从高到底排序为: ");
			for(i=0;i<n;i++)
			printf("%.1f  ",a[i]);
			printf("\n");
			printf("平均成绩为 %.1f",aver);
			getch();
}






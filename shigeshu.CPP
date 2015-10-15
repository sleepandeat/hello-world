#include<stdio.h>
void main()
{
int a[11]; //因为要增加一个数字. 所以长度应该+1;
int i,j,t,m;
printf("请输入十个数字:\n");
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
for(i=0;i<10;i++)
printf("%3d",a[i]);
printf("\n");
printf("请插入一个数字");
scanf("%d",&m);

if(m>a[9]) //多了个分号;
a[10]=m;
else
{
for(i=0;i<10;i++)
if(m<a[i])
{
for(j=9;j>=i;j--) //j应该是>=i. 并且是-- 不是++
{
a[j+1]=a[j];
}
a[i]=m;
break;
}
}

printf("插入后的顺序为:\n");
for(i=0;i<11;i++) //增加了一个数字,所以长度要+1
printf("%3d",a[i]);


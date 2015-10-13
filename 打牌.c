#include<stdio.h>
int main()
{
	int a,b,c,d,t=0;
	//输入桌数
	do
	{
		printf("input the number of groups which have 1 peoplce\n");
		scanf("%d",&a);
		printf("input the number of groups which have 2 people\n");
		scanf("%d",&b);
		printf("input the number of groups which have 3 people\n");
		scanf("%d",&c);
		printf("input the number of groups which have 4 people\n");
		scanf("%d",&d);
	}
	while(a<0||b<0||c<0||d<0);
	if(a>=b)//1人桌多余2人桌的情况
	{
		a=a-b;
		t=t+b;
		if(a>=c)//剩余1人桌多余三人桌的情况
		{
			if(a%3==0)
			{
				t=t+a/3;
			}
			else//剩余一个或两个一人桌，一个一人桌和两个四人桌配对
			{
				if((a%3*2)>=d)
				{
					t=t+2*(a%3);
				}
				else
				{
					t=-1;
				}
			}
		}
		else//剩余1人桌少于3人桌的情况
		{
			t=t+a;
		}
	}
	else//1人桌少于2人桌的情况
	{
		t=t+b/2;//2个二人桌凑成1个四人桌
		d=d+b/2;
		b=b%2;
		if(b!=0)//剩余一个二人桌和一个四人桌配对配对
		{
			if(d>=1)
			{
				t=t+1;
			}
			else
			{
				t=-1;
			}
		}
	}
	printf("%d\n",t);
	return 0;
}


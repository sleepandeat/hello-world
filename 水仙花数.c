#include<stdio.h>

int main()
{
	int a,c,b,num;
	for(num=100;num<1000;num++)
	{
		a=num/100;
		b=num/10-a*10;
		c=num%10;
		if(num==(a*a*a+b*b*b+c*c*c))
		{
			printf("%d\n",num);
		}
	}

	while(1);
}

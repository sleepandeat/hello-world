#include <stdio.h>
#include <math.h>
int main()
{
	//2000000000
	long int n,temp;
	long double number;
	int result;
	while(1)
	{
		scanf("%d",&n);
		number=pow((3+sqrt(5)),n);
		temp=(long int)number;
		result=temp%1000;
		printf("%03d\n",result);
	}
	return 0;
}
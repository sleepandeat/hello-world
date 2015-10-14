//变为其后第四个字母
#include<stdio.h>
int main()
{
	char c;
	c=getchar();
	while(c!='\n')//优化：将上下两个getchar()合并，此处写为 while((c=getchar())!='\n')
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			if((c>='W'&&c<='Z')||(c>='w'&&c<='z'))
			{
				c=c-22;
			}
			else
			{
				c=c+4;
			}
		}
		printf("%c",c);
		c=getchar();//再赋值，不可少，不然只处理第一个值
	}
	printf("\n");
	return 0;
}
//getchar()输入是一个字符一个字符处理的，比如输入ab，将c='a'处理一遍，再将c='b'处理一遍
#include <stdio.h>
#include<conio.h> 
#define HEART(x,y) (x*x+y*y-1)*(x*x+y*y-1)*(x*x+y*y-1)-x*x*y*y*y
int main()
{
	int x = 20, y = 10, i, j;
	for (i = -y; i <= y; ++i, puts (""))
		for (j = -x; j <= x; ++j)
			putchar (HEART (j * 1.3 / x, -i * 1.5 / y) < 0 ? '*' : ' ');
	getch();
}

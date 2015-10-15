#include <math.h>
#include<stdio.h>
#include<conio.h>
int main(int argc, char* argv[])
{
//textbackground(0);
//	 textcolor(12);
//	clrscr();
	int n = 11;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < abs(i-n/2);k++)
			putchar(' ');
		for (int j=0;j<n-abs(i-n/2)*2;j++)
			putchar('*');
		putchar('\n');
	}
	getch();
}

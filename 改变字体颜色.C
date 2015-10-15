#include <conio.h>

int main(void)
{
   int i;

   clrscr();
   for (i=0; i<9; i++)
   {
	   textattr(i);
	   cprintf("This is a test\r\n");
   }

   return 0;
}
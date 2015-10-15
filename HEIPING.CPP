#include "stdio.h"
#include "graphics.h"
#include<conio.h>
main()
{
int graphdriver=VGA;
int graphmode=VGAHI;
initgraph(&graphdriver,&graphmode,"");
cleardevice();
moveto(200,200);
lineto(100,100);
closegraph();
getch();

}

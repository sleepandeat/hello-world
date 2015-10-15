#include<stdio.h>
#include<windows.h>
#include<DELTA_Graphics.h>
#pragma comment(lib, "ddraw.lib")
#pragma comment(lib, "DELTA_Graphics.lib")
#pragma comment(lib, "dxguid.lib")
int main()
{
	DELTA_OpenGraphicWindow(50,50,640,480);
	DELTA_Canvas* OffCanvas = DELTA_CreateCanvas(0,0);
	DELTA_CleanScreen(OffCanvas,DELTA_RGB(255,255,255));
	DELTA_Ellipse(OffCanvas,100,100,50,50,2,DELTA_RGB(0,0,0),DELTA_RGB(0,0,0));
	DELTA_Copy(DELTA_GetGraphicWindowCanvas(),0,0,OffCanvas,0,0,0,0);
	DELTA_RefreshGraphicWindow();
	system("pause");
	return 0;
} 

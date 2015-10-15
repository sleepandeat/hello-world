#include<windows.h>
#include<stdio.h>
HANDLE hInput;  /*  获取标准输入设备句柄 */
INPUT_RECORD inRec;/*  返回数据记录 */
DWORD numRead; /*  返回已读取的记录数 */
int Y,X;/* X和Y的坐标 */
int data[60][22];
HWND hwnd;
int input()
{
	while(1){
			COORD pos = {0,0};
			ReadConsoleInput(hInput, &inRec, 1, &numRead);
			pos = inRec.Event.MouseEvent.dwMousePosition;
			Y=(int)pos.Y;
			X=(int)pos.X;
	       if(X!=0&&Y!=0&&X<60&&Y<22&&X%4==0&&Y%2==0)
	       {
    			if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwEventFlags  == RIGHTMOST_BUTTON_PRESSED)  /* 鼠标左键双击 */
    						return 1;
    			else if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) /* 鼠标右键单击 */
    						return 2;
    			else if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /* 鼠标左键单击 */
        					return 3;
			} 
          }
} 
void HideCursor()//隐藏控制台的光标 
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)
{
     COORD coord;
	 coord.X = x,coord.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void chushihua()
{
     int i,j;
     for(i=0;i<=22;i++)
     {
        for(j=0;j<=30;j++)
           if(j==0)
             if(i==0)printf("╔");
             else if(i==22)printf("╚");
             else if(i%2==0)printf("╠");
             else printf("║");
           else if(j==30)
             if(i==0)printf("╗");
             else if(i==22)printf("╝");
             else if(i%2==0)printf("╣");
             else printf("║");
           else if(i==0)
             if(j%2==0)printf("╦");
             else printf("═");
           else if(i==22)
             if(j%2==0)printf("╩");
             else printf("═");
           else if(i%2==0&&j%2==0)printf("╬");
           else if(i%2==0)printf("═");
           else if(j%2==0)printf("║");
           else printf("  ");
        printf("\n");
     }
     gotoxy(64,2);printf("【鼠标操作】");
     gotoxy(65,4);printf("左键：白棋");
     gotoxy(65,6);printf("右键：黑棋");
     gotoxy(65,8);printf(" 黑棋先走");
     gotoxy(65,10);printf("无获胜判断");
} 
int main()
{ 
	int rt;
	BOOL black=TRUE; 
	HideCursor(); //隐藏控制台的光标 
	chushihua();memset(data,0,sizeof(data));
	hwnd=FindWindow("ConsoleWindowClass",NULL);/*  控制台窗口句柄 */
	hInput = GetStdHandle(STD_INPUT_HANDLE); /*  输入设备句柄 */
    while(1)
    {					
		ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
		switch(inRec.EventType)
		{
			case MOUSE_EVENT:
                 {
					rt=input();
					switch(rt)
                    {
				       case 2://右键单击
				            if(black)
                            {
                                 if(data[Y][X]==0)data[Y][X]=1;
                                 else {MessageBox(hwnd,"不可重复放在一个位置","错误",MB_ICONERROR);continue;} 
                                 gotoxy(X,Y);printf("○");black=!black;
                            }
				            else MessageBox(hwnd,"该白棋走","错误",MB_ICONERROR);
                            break;
                       case 3://左键单击 
                            //gotoxy(62,2);printf("%d %d",X,Y);
				            if(!black)
                            {
                                if(data[Y][X]==0)data[Y][X]=1;
                                else {MessageBox(hwnd,"不可重复放在一个位置","错误",MB_ICONERROR);continue;} 
                                gotoxy(X,Y);printf("●");black=!black;
                            }
				            else MessageBox(hwnd,"该黑棋走","错误",MB_ICONERROR);
                            break;
                    }
                  }
                  break;
         }
     }
} 

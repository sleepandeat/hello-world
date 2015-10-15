#include <stdio.h>
#include <time.h>
#include<windows.h>
#include <conio.h>
void gotoxy(int x, int y)//gotoxy语句 
{ 
    COORD pos; 
    pos.X = x - 1; 
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); 
}
void HideCursor()//隐藏控制台的光标 
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int main()
{ 
    int i,j,x=1,y=5;
    HideCursor();
    printf("\n\n按任意键开始：\n\n"); getch(); 
    for(i=0;i<30;i++)
    {
        y=5;x++; gotoxy(x,y++);
        printf("     *  *         *  *  *         * * * *\n");gotoxy(x,y++);
        printf("    *     *      *     *    *        * *\n");gotoxy(x,y++);
        printf("   *        *  *        *     *  *    *\n");gotoxy(x,y++);
        printf("  *           *          *     *     *\n");gotoxy(x,y++);
        printf("  *                      * *   *\n");gotoxy(x,y++);
        printf("  *                     **     *\n");gotoxy(x,y++);
        printf("   *                 *  *     *\n");gotoxy(x,y++);
        printf("    *             *    *     *\n");gotoxy(x,y++);
        printf("     *         *      *     *\n");gotoxy(x,y++);
        printf("      *     *        *     *\n");gotoxy(x,y++);
        printf("        * *        *     *\n");gotoxy(x,y++);
        printf("       *  *       *    *\n");gotoxy(x,y++);
        printf("    *       *   *   *\n");gotoxy(x,y++);
        printf(" *            *  *\n");gotoxy(x,y++);        
        Sleep(100);
    }
    printf("\n\n本程序已结束：");getch();
}

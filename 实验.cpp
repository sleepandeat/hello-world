#include<stdio.h>
#include<conio.h>
int a[10];
int input()
{
    int i;
    for(i=0;i<4;i++)
    {
       scanf("%d",(a+i));             
    }
    for(i=0;i<4;i++)
       printf("%d ",a[i]);

}
int main()
{
    input();
    getch(); 
} 
    LOGFONT lf;
	ZeroMemory(&lf,sizeof(LOGFONT));
	lf.lfCharSet = GB2312_CHARSET;//
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lstrcpy(lf.lfFaceName,"微软雅黑");
	lf.lfQuality = DEFAULT_QUALITY;
	lstrcpy(lf.lfFaceName,ziti);
	lf.lfHeight = zihao;
	HFONT font = CreateFontIndirect(&lf);
	SelectFont(hdc,font);
	SendMessage(hwndChild,WM_SETFONT,(WPARAM)font,0);
	DeleteObject(font);//主要是这里释放失败。。。 
	SetBkMode(hdc,TRANSPARENT);
	SetTextColor(hdc,RGB(255,255,255)); 
	return (HBRUSH)CreateSolidBrush(color);

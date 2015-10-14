#include<stdio.h>
#include<bios.h>
#define LEFT 75
#define RIGHT 77
#define UPPER 72
#define DOWN 80
#define ESC 27
struct Boxss{
    int x,y ;
};
union keyboard{
    unsigned int iKeyInfo;
    char chKeyBit[2];
};
int fnGetKey(void){
    union keyboard uniKey1;
    while(bioskey(1)==0);
    uniKey1.iKeyInfo=bioskey(0);
    return (uniKey1.chKeyBit[0]==0?uniKey1.chKeyBit[1]:uniKey1.chKeyBit[0]);
}
void main(){
    int iKey,x=11,y=6,tx=11,ty=6;
    struct Boxss Box[4];
    int chMap[10][10]={
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,1,1,1,0},
        {0,1,0,2,0,0,1,0,1,0},
        {0,1,0,1,0,0,1,0,1,0},
        {0,1,1,1,0,0,1,0,1,0},
        {0,1,0,0,0,0,1,0,1,0},
        {0,1,1,1,1,1,1,0,1,0},
        {0,1,0,1,0,0,0,0,2,0},
        {0,2,0,1,1,1,1,2,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int i,j;
    Box[0].x=13;
    Box[1].x=11;
    Box[2].x=14;
    Box[3].x=18;
    Box[0].y=8;
    Box[1].y=7;
    Box[2].y=13;
    Box[3].y=7;
    while(1){
        for(i=1;i<10;i++){
            go toxy(10,5+i);
            for(j=0;j<10;j++){
                if(chMap[i][j]==0)
                    printf("#");
                if(chMap[i][j]==1)
                    printf(" ");
                if(chMap[i][j]==2)
                    printf("X");
            }
        }
        j=0;
        for(i=0;i<4;i++)
            if(chMap[Box[i].y-5][Box[i].x-10]==2)
                j++;
            if(j==4){
                clrscr();
                printf("you win");
                break;
            }
            for(i=0;i<4;i++){
                gotoxy(Box[i].x,Box[i].y);
                printf("0");
                }
            gotoxy(x,y);
            printf("*\b");
            tx=x;
            ty=y;
            iKey=fnGetKey();
            if(iKey==LEFT&&chMap[y-5][x-1-10]!=0)
                x--;
            if(iKey==RIGHT&&chMap[y-5][x+1-10]!=0)
                x++;
            if(iKey==UPPER&&chMap[y-1-5][x-10]!=0)
                y--;
            if(iKey==DOWN&&chMap[y+1-5][x-10]!=0)
                y++;
            if(iKey==ESC){
                clrscr();
                printf("you loose");
                break;
                }
            for(i=0;i<4;i++)
                if(Box[i].x==x&&Box[i].y==y){
                Box[i].x+=(x-tx);
                Box[i].y+=(y-ty);
                if(chMap[Box[i].y-5][Box[i].x-10]==0){
                    Box[i].x-=(x-tx);
                    Box[i].y-=(y-ty);
                            x=tx;
                            y=ty;
                        }
                        break;
                    }



                    clrscr();
                }
                getch();
            }




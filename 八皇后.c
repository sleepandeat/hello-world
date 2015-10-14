#include   <stdio.h> 
static   char   Queen[8][8];           /*存放棋盘*/ 
static   int   a[8];                           /*存放棋盘列的状况*/ 
static   int   b[15];                         /*存放棋盘主对角线的状况*/ 
static   int   c[15];                         /*存放棋盘从对角线的状况*/ 
static   int   iQueenNum=0;           /*存放方法次数*/ 
void   qu(int   i); 
int   main(int   argc,   char   *argv[]) 
{ 
    int   iLine,iColumn;         /*   行       列*/ 
    /*初始化棋盘*/ 
    for   (iLine=0;iLine <8;iLine++){ 
            a[iLine]   =   0; 
            for   (iColumn=0;iColumn <8;iColumn++){ 
                    Queen[iLine][iColumn]   =   '* '; 
            } 
    } 
    /*初始化主,   从对角线*/ 
    for   (iLine=0;iLine <15;iLine++){ 
            b[iLine]   =   c[iLine]   =   0; 
    } 
    qu(0); 
    
    system( "pause "); 
    return   0; 
} 
void   qu(int   i){ 
          int   iColumn; 
          for   (iColumn=0;iColumn <8;iColumn++){ 
                  if   (a[iColumn]==0   &&   b[i-iColumn+7]==0   &&   c[i+iColumn]==0){             /*判断是否可以摆放皇后*/ 
                        Queen[i][iColumn]   =   '@ '; 
                        a[iColumn]   =   1;                               /*标记此位置已经摆放*/ 
                        b[i-iColumn+7]   =   1;                     /*标记此位置已经摆放*/ 
                        c[i+iColumn]   =   1;                       /*标记此位置已经摆放*/ 
                        if   (i <7){                     /*继续进行遍历*/ 
                                qu(i+1); 
                        } 
                        else{                           /*输出棋盘状态*/ 
                                int   iLine,iColumn; 
                                printf( "%d\n ",++iQueenNum); 
                                for   (iLine=0;iLine <8;iLine++){ 
                                        for   (iColumn=0;iColumn <8;iColumn++){ 
                                                printf( "%c ",Queen[iLine][iColumn]); 
                                        } 
                                        printf( "\n "); 
                                } 
                                printf( "\n\n\n "); 
                                system( "pause "); 
                        } 
                        
                        /*如果出现错误,   则回溯*/ 
                        Queen[i][iColumn]   =   '* '; 
                        a[iColumn]   =   0; 
                        a[i-iColumn+7]   =   0; 
                        c[i+iColumn]   =   0; 
                  } 
          } 
}


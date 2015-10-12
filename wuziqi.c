	/*turboc2.0下编译通过*/
#include 
#include 
#include 
#include 
#define N 15
#define B 7
#define STOP -10000
#define OK 1
#define NO 0
#define UP 328
#define DOWN 336
#define LEFT 331
#define RIGHT 333

/*定义了两个数，n为棋盘的大小。b为背景颜色的数值*/
int a[N+1][N+1];
int zx,zy;
int write=1,biaoji=0;

struct zn{
long sum;
int y;
int x;
}w[N+1][N+1],max,max1;


void cbar(int i,int x,int y,int r);
void map(int a[][]);
int getkey();
int key();
void zuobiao(int x,int y,int i);
int tu(int a[][],int write);
int wtu(int a[][],int write);
int zhineng(int a[][]);
int zh5(int y,int x,int a[][]);
long zzh5(int b[][],int i);

main()
{
int i,j;
int gdriver=DETECT;
int gmode;
initgraph(&gdriver,&gmode,);
zx=(N+1)/2;
zy=(N+1)/2;
for(i=1;i<=N;i++)
for(j=1;j<=N;j++)
a[i][j]=0;
map(a);
i=1;
while(i)
{
int k,n;

k=wtu(a,write);
if(k==STOP) goto end;
map(a);

n=zhineng(a);
if(n==STOP) goto end;
map(a);

}
end:
;

}

/* 实现对局的程序 ，计算全部N*N个格中，最应该填的格子 */
int zhineng(int a[N+1][N+1])
{
int i,j;
int k;
max.sum=-1;


for(i=0;i<=N;i++)
for(j=0;j<+N;j++)
{
w[i][j].sum=0;
w[i][j].x=i;
w[i][j].y=j;
}

for(i=1;i<=N-4;i++)
for(j=1;j<=N-4;j++)
{
k=zh5(i,j,a);
if(k==STOP) return (STOP);

}

for(i=1;i<=N;i++)
for(j=1;j<=N;j++)
{
if(max.sum {
max.sum=w[i][j].sum;
max.y=i;
max.x=j;
}
else if(max.sum==w[i][j].sum)
{
if(((max.y-zy)*(max.y-zy)+(max.x-zx)*(max.x-zx))>((i-zy)*(i-zy)+(j-zx)*(j-zx)))
max.sum=w[i][j].sum;
max.y=i;
max.x=j;
}
}
if(a[max.y][max.x]==0)
{
a[max.y][max.x]=-1;
zy=max.y;
zx=max.x;
}

}


/* 转换成5*5的数组,计算出在二十五个格子中，最应该填的格 */
int zh5(int y,int x,int a[N+1][N+1])
{
int i,j;
int b[6][6];
long c[13];
long d[6][6];
long temp;
for(i=y;i<=y+4;i++)
for(j=x;j<=x+4;j++)
b[i+1-y][j+1-x]=a[i][j];

c[1]=b[1][1]+b[1][2]+b[1][3]+b[1][4]+b[1][5];
c[2]=b[2][1]+b[2][2]+b[2][3]+b[2][4]+b[2][5];
c[3]=b[3][1]+b[3][2]+b[3][3]+b[3][4]+b[3][5];
c[4]=b[4][1]+b[4][2]+b[4][3]+b[4][4]+b[4][5];
c[5]=b[5][1]+b[5][2]+b[5][3]+b[5][4]+b[5][5];

c[6]=b[1][1]+b[2][1]+b[3][1]+b[4][1]+b[5][1];
c[7]=b[1][2]+b[2][2]+b[3][2]+b[4][2]+b[5][2];
c[8]=b[1][3]+b[2][3]+b[3][3]+b[4][3]+b[5][3];
c[9]=b[1][4]+b[2][4]+b[3][4]+b[4][4]+b[5][4];
c[10]=b[1][5]+b[2][5]+b[3][5]+b[4][5]+b[5][5];

c[11]=b[1][1]+b[2][2]+b[3][3]+b[4][4]+b[5][5];
c[12]=b[1][5]+b[2][4]+b[3][3]+b[4][2]+b[5][1];


for(i=1;i<=12;i++)
{
switch(c[i])
{
case 5:biaoji=1;return(STOP);
case -5:biaoji=-1;return(STOP);

case -4:c[i]=100000;break;
case 4:c[i]=100000;break;
case -3:c[i]=150;break;
case 3:c[i]=150;break;
case -2:c[i]=120;break;
case 2:c[i]=100;break;
case -1:c[i]=1;break;
case 1:c[i]=1;break;

default: c[i]=0;
}
}

for(i=1;i<=12;i++)
{
if(c[i]==150)
c[i]+=zzh5(b,i);
}
for(i=1;i<=5;i++)
for(j=1;j<=5;j++)
d[i][j]=0;

for(i=1;i<=5;i++)
for(j=1;j<=5;j++)
{
if(i==j) d[i][j]+=c[11];
if((i+j)==6) d[i][j]+=c[12];
d[i][j]+=c[i]+c[j+5];
}

for(i=1;i<=5;i++)
for(j=1;j<=5;j++)
{
if(b[i][j]!=0)
d[i][j]=-2;
}
max1.sum=-1;
max1.y=0;
max1.x=0;
for(i=1;i<=5;i++)
for(j=1;j<=5;j++)
{
if(max1.sum {
max1.sum=d[i][j];
max1.y=i;
max1.x=j;
w[i+y-1][j+x-1].sum+=max1.sum;
}
else if(max1.sum==d[i][j])
{
if(((i+y-1-zy)*(i+y-1-zy)+(j+x-1-zx)*(j+x-1-zx))>((max1.y+y-1-zy)*(max1.y+y-1-zy)+(max1.x+x-1-zx)*(max1.x+x-1-zx)))
{
max1.sum=d[i][j];
max1.y=i;
max1.x=j;
}
}
}

}

long zzh5(int b[6][6],int n)
{
int i,j,k,l,m;
switch(n)
{
case 1:i=b[1][1];j=b[1][2];k=b[1][3];l=b[1][4];m=b[1][5];break;
case 2:i=b[2][1];j=b[2][2];k=b[2][3];l=b[2][4];m=b[2][5];break;
case 3:i=b[3][1];j=b[3][2];k=b[3][3];l=b[3][4];m=b[3][5];break;
case 4:i=b[4][1];j=b[4][2];k=b[4][3];l=b[4][4];m=b[4][5];break;
case 5:i=b[5][1];j=b[5][2];k=b[5][3];l=b[5][4];m=b[5][5];break;
case 6:i=b[1][1];j=b[2][1];k=b[3][1];l=b[4][1];m=b[5][1];break;
case 7:i=b[1][2];j=b[2][2];k=b[3][2];l=b[4][2];m=b[5][2];break;
case 8:i=b[1][3];j=b[2][3];k=b[3][3];l=b[4][3];m=b[5][3];break;
case 9:i=b[1][4];j=b[2][4];k=b[3][4];l=b[4][4];m=b[5][4];break;
case 10:i=b[1][5];j=b[2][5];k=b[3][5];l=b[4][5];m=b[5][5];break;
case 11:i=b[1][1];j=b[2][2];k=b[3][3];l=b[4][4];m=b[5][5];break;
case 12:i=b[1][5];j=b[2][4];k=b[3][3];l=b[4][2];m=b[5][1];break;

}
if((i==0&&j==1&&k==1&&l==1&&m==0))
return (900);
if((i==0&&j==-1&&k==-1&&l==-1&&m==0))
return(1000);
if((i==0&&j==0&&k==1&&l==1&&m==1)||(i==1&&j==1&&k==1&&l==0&&m==0))
return(20);
if((i==0&&j==0&&k==-1&&l==-1&&m==-1)||(i==-1&&j==-1&&k==-1&&l==0&&m==0))
return(20);

if((i==-1&&j==1&&k==1&&l==1&&m==1)||(i==1&&j==-1&&k==1&&l==1&&m==1)||(i==1&&j==1&&k==-1&&l==1&&m==1)||(i==1&&j==1&&k==1&&l==-1&&m==1)||(i==1&&j==1&&k==1&&l==1&&m==-1))
return(-60);

if((i==1&&j==-1&&k==-1&&l==-1&&m==-1)||(i==-1&&j==1&&k==-1&&l==-1&&m==-1)||(i==-1&&j==1&&k==-1&&l==-1&&m==-1)||(i==-1&&j==-1&&k==-1&&l==1&&m==-1)||(i==-1&&j==-1&&k==-1&&l==-1&&m==1))
return(-60);

}
/* 循环执行坐标的选择，直到按回车，空格或ESC键 */
int wtu(int a[N+1][N+1],int write)
{
int i=1;
map(a);
zuobiao(zx,zy,1);
while(i)
{
int k;
k=tu(a,write);
if(k==OK) i=0;
if(k==STOP) return (STOP);
}
}


/*从键盘获得输入的值*/
int getkey()
{
int key,lo,hi;
key=bioskey(0);
lo=key&0x00ff;
hi=(key&0xff00)>>8;
return((lo==0) ? hi+256:lo);
}

/*对获得的值进行判断* 

	
	作者： 202.106.46.*  2009-9-10 16:56 　 
	________________________________________
2	五子棋C语言源代码 
	/
/*对应的码值分别如下*/
/* 上：328 下：336 左： 331 右： 333 */
/* 回车：13 ESC键： 27 */

int key()
{
int k;
k=getkey();
switch(k)
{
case 27: return (STOP);
case 13:
case ' ': return (OK);
case 328: return (UP);
case 336: return (DOWN);
case 331: return (LEFT);
case 333: return (RIGHT);
default: return (NO);
}

}

/*用来显示坐标的位置*/
void zuobiao(int x,int y,int i)
{
int r;
if(i!=0)
{
setcolor(GREEN);

for(r=1;r<=5;r++)
circle(75+25*x,25+25*y,r);


}
else
{
if(a[zy][zx]==1)
{
setcolor(8);
for(r=1;r<=5;r++)
circle(75+25*x,25+25*y,r);
}
else if(a[zy][zx]==-1)
{
setcolor(WHITE); 
for(r=1;r<=5;r++)
circle(75+25*x,25+25*y,r);
}
else
{
setcolor(B);
for(r=1;r<=5;r++)
circle(75+25*x,25+25*y,r);
setcolor(RED); line(75+25*zx-5,25+25*zy,75+25*x+5,25+25*zy);
line(75+25*zx,25+25*zy-5,75+25*zx,25+25*zy+5);
}
}
}

/*从键盘获得的值进行判断，反映在显示的图上*/

int tu(int a[N+1][N+1],int write)
{
int k;
re:
k=key();
if(k==OK)
{
if(a[zy][zx]==0)
{
a[zy][zx]=write;
}
else
goto re;
}

if(k==STOP) return(STOP);

if(k==NO) goto re;

if(k==UP)
{
int i,j;
if(zy==1) j=zy;
else j=zy-1;
zuobiao(zx,zy,0);
zuobiao(zx,j,1);
zy=j;
goto re;
}
if(k==DOWN)
{
int i,j;
if(zy==N) j=zy;
else j=zy+1;
zuobiao(zx,zy,0);
zuobiao(zx,j,1);
zy=j;
goto re;
}
if(k==LEFT)
{
int i,j;
if(zx==1) i=zx;
else i=zx-1;
zuobiao(zx,zy,0);
zuobiao(i,zy,1);
zx=i;
goto re;
}
if(k==RIGHT)
{
int i,j;
if(zx==N) i=zx;
else i=zx+1;
zuobiao(zx,zy,0);
zuobiao(i,zy,1);
zx=i;
goto re;
}

}







/* 根据数组中（存储棋子位置）各位置的数，画实心圆（画出棋子）*/
void cbar(int i,int x,int y,int r)
{
if(i!=0)
{
if(i==1)
setcolor(8);
else if(i==-1)
setcolor(WHITE);

for(i=1;i<=r;i++)
{
circle(x,y,i);
}
}
}

/*画出棋盘，和各个棋子*/
void map(int a[N+1][N+1])
{
int i,j;
cleardevice();
setbkcolor(B);
setcolor(RED);
for(i=0;i {

line(100,50+25*i,75+N*25,50+25*i);
line(100+25*i,50,100+25*i,25+N*25);
}
for(i=1;i<=N;i++)
for(j=1;j<=N;j++)
cbar(a[i][j],75+25*j,25+25*i,10);
} 


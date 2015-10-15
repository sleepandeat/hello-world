#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<dir.h> 
#include<dos.h>
#include <process.h> 
#define A for(j=0;j<i;j++) printf(" ");
char caidan()
{
     int i,j;
    for(i=0;i<15;i++)
    {
        _sleep(100);
        system("cls");A;
            printf("这是一个测试输入速度的游戏\n");A;
            printf(">>>开始游戏：1\n");A;
            printf(">>>难度设置：2\n");A;
            printf(">>>游戏介绍：3\n");A;
            printf(">>>退出游戏：4\n");A;
            printf("请选择：");  
    }
}
char abc(int shijian,int xunhuan,int nandu)
{
   int b,i,f,j,shijian3;
	FILE *fp2;
	char u[10]={0};
	long q1,q2,q3,q4;
	char d[100],e[100];
	srand(time(NULL));
	time_t nowtime;
	for(j=0;j<xunhuan;j++)
	{
      q3=time(&nowtime);
	   do{
	        q4=time(&nowtime);
	            if(q4-q3==1)
	             break;
	     }while(1);
	f=1;
    for(i=0;i<nandu;i++)
	{
	       b=rand()%4+1;
    switch(b)
	   {
    	  case 1:printf("%c  ",24);d[i]='w';break;
    	  case 2:printf("%c  ",25);d[i]='s';break;
    	  case 3:printf("%c  ",27);d[i]='a';break;
    	  case 4:printf("%c  ",26);d[i]='d';break;
    	  default:printf("tiao shi !");break;
	    }
	}
	      printf("\n");
	      q1=time(&nowtime);
	i=0;
	do{
	     if(kbhit())
	      {
	          e[i]=getche();
	            if(e[i]==' ')
	                break;
                else
	                i++;
	       }
	       q2=time(&nowtime);
	       q3=q2-q1;
	   }while(q3<shijian);
   	if(q3==shijian)
    	{
            fp2=fopen("d:/缓存/时间.txt","r+");
             fread(u,2,10,fp2);
              fclose(fp2);
               shijian3=atoi(u);
    	         printf("\t   时间结束!!（当前设置为%d秒，可自行到难度设置中设置）\n\n",shijian3);
           }
    else 
    if(i>nandu)
          printf("\n\t\t输入字符过多！\n");
    else
    	{
    	for(i=0;i<nandu;i++)
    	   if(d[i]!=e[i])
    	      {
    	        f=0;
    	          printf("\t\tFOLL !!\n\n");
    	             break;
    	       }
   	    if(f==1)
    	       printf("\t\tGOOD !!\n\n");
    	}
	}
	printf("循环结束！（可自行到难度设置中设置循环次数）");  
}
int abcd(int *shijian,int *xunhuan,int *nandu)
{
    int a;
    FILE *fp1,*fp2;
    char shijian2[10]={0},xunhuan2[10]={0},nandu2[10]={0};
    char u[10]={0};
    end:
        printf("\n更改每次输入时的时间：1\n");
        printf("更改游戏循环的次数：2\n");
        printf("更改显示字母的个数：3\n");
        printf("保存并退出：4\n"); 
        printf("请选择："); 
             scanf("%d",&a); 
    switch(a)
    {
       case 1:printf("输入更改的时间（默认为5秒）：");
             scanf("%d",shijian);
              itoa(*shijian,shijian2,10);
                fp1=fopen("d:/缓存/时间.txt","w+");
                  fwrite(shijian2,2,3,fp1);
                     fclose(fp1);
                       goto end;
       case 2:printf("输入循环此数（默认循环3次）：");
              scanf("%d",xunhuan);
                 itoa(*xunhuan,xunhuan2,10);
                    fp1=fopen("d:/缓存/循环.txt","w+");
                       fwrite(xunhuan2,2,3,fp1);
                          fclose(fp1);
                              goto end;
       case 3:printf("输入显示字母个数（默认为4个）：");
              scanf("%d",nandu);
                 itoa(*nandu,nandu2,10);
                    fp1=fopen("d:/缓存/个数.txt","w+");
                         fwrite(nandu2,2,3,fp1);
                             fclose(fp1);
                                 goto end;
       case 4:break;
    } 
}
int  main()
{
     int a,i,ki;
     char b;
     mkdir("d:/缓存");
     int shijian=5,xunhuan=3,nandu=4;
     char u[10]={0},s[3]={"5"},r1[3]={"3"},r2[3]={"4"};
     char shuoming[]={"1>>:此文件夹是你玩“测试输入速度游戏”时自动创建的，用于保存你对游戏做的更改。以便下次进入时不用再次设置。\n\n2>>:文本格式为text格式，用户可后台对数据进行更改，程序再次运行时生效。\n\n3>>:不用时可以自行删除，当再次运行游戏时将会再次被创建。"};
     FILE *fp1,*fp2;
     fp1=fopen("d:/缓存/说明read me.txt","w");
           fwrite(shuoming,2,120,fp1);
               fclose(fp1);
     if((fp1=fopen("d:/缓存/时间.txt","r"))==NULL)
    {
    	fp1=fopen("d:/缓存/时间.txt","w");
            fwrite(s,2,3,fp1);
                fclose(fp1);
    }
    fp2=fopen("d:/缓存/时间.txt","r+");
        fread(u,2,10,fp2);
           fclose(fp2);
              shijian=atoi(u);
	//printf("s=%d",shijian);
	
    if((fp1=fopen("d:/缓存/循环.txt","r"))==NULL)
    {
    	fp1=fopen("d:/缓存/循环.txt","w");
            fwrite(r1,2,3,fp1);
               fclose(fp1);
    }
    fp2=fopen("d:/缓存/循环.txt","r+");
        fread(u,2,10,fp2);
           fclose(fp2);
              xunhuan=atoi(u);
	//printf("s=%d",xunhuan);
	
	if((fp1=fopen("d:/缓存/个数.txt","r"))==NULL)
    {
    	fp1=fopen("d:/缓存/个数.txt","w");
           fwrite(r2,2,3,fp1);
              fclose(fp1);
    }
    fp2=fopen("d:/缓存/个数.txt","r+");
        fread(u,2,10,fp2);
           fclose(fp2);
              nandu=atoi(u);
	//printf("s=%d",nandu);
	//getch();
	do{
        begin:
            caidan();
	            scanf("%d",&a);
    switch(a)
    {
       case 1:abc(shijian,xunhuan,nandu);break;
       case 2:abcd(&shijian,&xunhuan,&nandu);goto begin;break;  
       case 3:printf("说明：\n1>>>w,s,a,d控制上下左右，输入空格即为输入结束。\n");
              printf("2>>>输入有误则为FOLL！！但输入时的时间有限制，初始时间为5秒。\n");
              printf("3>>>时间结束即使输入正确也为foll!!。时间可自行设置更改。\n");
              printf("4>>>程序会在你的D盘创建一文件夹以保存你对游戏的设置。\n");
              printf("5>>>输入后不可以更改，即使改正确后也会显示“FOLL！！”\n"); 
              system("pause");
              goto begin;
              break;
       case 4:exit(1);
              break;
       default:printf("输入错误！");
               fflush(stdin);
               goto begin;
               break; 
    } 
    printf("是否继续？[Y/N]");
       b=getche();
          printf("\n");
    }while(b=='y'||b=='Y');
}

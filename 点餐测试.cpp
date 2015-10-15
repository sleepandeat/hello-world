#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
#include<windows.h>
#include<conio.h>
long rand_time;
struct food
{
    long l_time;
    int wait_time;
    int  chois[5];
    char show_time[20];
    struct food *next;
}; 
struct food *head,*node1,*node2;
int use_time[]={5,2,10,1,5};
void gotoxy(int x, int y)
{
     COORD coord;
	 coord.X = x,coord.Y=y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void now_time(char *rt_time,long *int_time)
{
    struct tm * timeinfo;
	//time(rand_time);
	rand_time+=rand()%600+10;
    *int_time=rand_time;
	timeinfo = localtime(&rand_time);
	wsprintf(rt_time,"%02d:%02d:%02d",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
}
//1、肉丝(5分钟)  2、蛋炒饭（2分钟）  3、炖猪蹄（10分钟）  4、炒白菜（1分钟）  5、炒腰花（5分钟）
void link_node(struct food *new_node)
{
     int i;new_node->wait_time=0;
     for(i=0;i<5;i++)
       if(new_node->chois[i]!=0)
          new_node->wait_time+=use_time[i];
     if(head==NULL)
     {
         head=new_node;
         return;
     }
     node1=head;
     while(node1!=NULL)
     {
        node2=node1;
        for(i=0;i<5;i++)
           if(node2->chois[i]!=0)
              new_node->wait_time+=use_time[i];
        node1=node1->next;
     }
     node2->next=new_node;
}
int main()
{
    char name[][50]={"炒白菜","蛋炒饭","炒腰花","肉丝","炖猪蹄"},str[50],data[256]; 
    int  waitDishes[5];
    int i=0,j,tt=0;FILE *p;
    struct food *new_node;
    memset(waitDishes,0,sizeof(waitDishes));
    srand(time(NULL));time(&rand_time);
    //printf("说明：\n5秒更新数据一次，按任意键结束循环，保存文件名为【订单数据.txt】\n按任意键开始....");getch();
    printf("输入测试数据组数：");scanf("%d",&tt);
    while(tt--)
    {
        //system("cls");
        if((p=fopen("订单数据.txt","w"))==NULL)
        {
            printf("创建文件失败，请确定本程序具有创建文件的权限。\n按任意键继续...");getch();
        } 
        new_node=(struct food *)malloc(sizeof(struct food));
        memset(new_node->chois,0,sizeof(new_node->chois));
        for(i=rand()%5+1;i>0;i--)//随机点几份菜 
        {
            j=rand()%5;
            waitDishes[j]++;//该菜品丁参数、总数 
            new_node->chois[j]++;//选择的菜品编号 
        }
        now_time(new_node->show_time,&new_node->l_time);
        new_node->next=NULL;
        link_node(new_node);
    } 
    node1=head;i=1; 
    fputs("----------------炒菜时间----------------\n【 肉丝 】5分钟\n【蛋炒饭】2分钟\n【炖猪蹄】10分钟\n【炒白菜】1分钟\n【炒腰花】5分钟\n",p);
    strcpy(data,"--------------当前待炒菜品--------------\n");//printf("%s",data);
    fputs(data,p);
    wsprintf(data,"订单号\t订单时间\t预计等待时间\t菜品及分数\n",i,node1->show_time);//printf("%s",data);
    fputs(data,p);
    while(node1!=NULL)
    {
      wsprintf(data,"%d\t%s\t%d分钟\t\t",i,node1->show_time,node1->wait_time);//printf("%s",data);
      fputs(data,p);
      for(j=0;j<5;j++)
        if(node1->chois[j]!=0)
        {
           wsprintf(data,"%-6s×%d  ",name[j],node1->chois[j]);//printf("%s",data);
           fputs(data,p);
        }
      i++;node1=node1->next;//printf("\n");
      fputs("\n",p);
    }
    strcpy(data,"--------------总共需炒份数--------------\n");//printf("%s",data);
    fputs(data,p);
    for(j=0;j<5;j++)
      if(waitDishes[j]!=0)
      {
         wsprintf(data,"【%s】：%d份\n",name[j],waitDishes[j]);//printf("%s",data);
         fputs(data,p);
      }
    strcpy(data,"---------------需先炒菜品---------------\n");//printf("%s",data);
    fputs(data,p);
    for(j=0;j<5;j++)
      if(head->chois[j]!=0)
      {
         wsprintf(data,"【%s】总共需炒：%d份\n",name[j],waitDishes[j]>3?3:waitDishes[j]);//printf("%s",data);
         fputs(data,p);
      }
    fclose(p);//Sleep(5000);
    node1=head;
    while(node1!=NULL)
    {
       node2=node1;node1=node1->next;free(node2);
    }
    while(kbhit())getch();
    printf("文件保存在本文件夹下的【订单数据.txt】中，按任意键退出....");getch();
}
/*
1、肉丝(5分钟)  2、蛋炒饭（2分钟）  3、炖猪蹄（10分钟）  4、炒白菜（1分钟）  5、炒腰花（5分钟）
*/

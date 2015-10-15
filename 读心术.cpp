#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
char shuoming(int c)
{
  printf("\t\t\t@#$ 读 心 术 游 戏 $#@\n\n");
  printf("游戏规则：1>>任意选择一个两位数（或者说，从10~99之间任意选择一个数）\n");
  printf("\t      把这个数的十位与个位相加，再把任意选择的数减去这个和。\n");
  printf("\t      例如：你选的数是23，然后2+3=5，然后23-5=18。\n"); 
  printf("\t   2>>在图表中找出与最后得出的数所相应的图形，并把这个图形牢记心中\n");
  printf("\t      你会发现，按回车后所显示出来的图形就是你刚刚心里记下的那个图形。\n");
  printf("\t   3>>当你连续试玩10次后，谜底将出现在你的屏幕上！\n"); 
  printf("按任意键开始第%d局。。。\n",c+1);
  getch();
}
int main()            // 9，18，27，36，45，54，63，72，81
{
    int a[100],b,c=0,i,j;
    do{
    shuoming(c);
    srand(time(NULL));
    b=rand()%42;
    if(b==0||b==8||b==9||b==10||b==11||b==12||b==13||b==32)
    b=15;
    for(i=0;i<100;i++)
    {
      a[i]=rand()%42;
      if(a[i]==0||a[i]==8||a[i]==9||a[i]==10||b==11||b==12||b==13||a[i]==32)
      a[i]=18;           
      if(i==9||i==18||i==27||i==36||i==45||i==54||i==63||i==72||i==81)
      a[i]=b;
      if(i==15||i==30||i==45||i==60||i==75||i==90)
      printf("\n");
      printf("%d:%c ",i,a[i]);
    }
    //getch();
    printf("\n默念你心中的图形，按回车。。。\n");
    getch();
    j=100;
    for(i=15;i<25;i++)
    {
       printf("%c ",i);
       _sleep(j);
       j=j+50;             
    }
    printf("你心中的图形是：%c\n",b);
    c++;
    system("pause");
    system("cls");
}while(c!=10);
system("cls");
printf("\n\t\t恭喜你坚持到了最后！\n原理就是：按回车。。。");
getch(); 
system("start http://zhidao.baidu.com/question/108715705.html"); 
printf("\n有时的自己学会寻找答案！");
    getch();
}

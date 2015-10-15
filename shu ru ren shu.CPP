#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
long a[20],e,f;char c[20];int d[20],b[20];
int n;
int abc(int g)
{
	for(int j=g;j<g+1;j++)
	{
	cout<<"===================基本信息==================="<<endl;
	cout<<" 姓名      "<<c<<endl;
	cout<<" 学号      "<<a[j]<<endl;
	if(b[j]==1)
	cout<<" 性别      男"<<endl;
	else
	cout<<" 性别      女"<<endl;
	if(d[j]==1)
	cout<<" 职位      学生"<<endl;
	else
	cout<<" 职位      老师"<<endl;
	cout<<"=============================================="<<endl;
	}
	return 0;
}
void main()
{
	 FILE *fp;
	 char x[10]={0},y[10]={0},z[10]={0},o[10]={0};
	cout<<"========初始化数据，请输入学生、职工信息======"<<endl;
     cout<<"输入学生、职工总人数:";
     cin>>n;
     for(int i=0;i<n;i++)
     {
	cout<<"输入第"<<i+1<<"个人的姓名: ";
	int f;
	for(int g=0;g<10;g++)
	{
	 cin>>c[g];
	 if(c[g]=='\n')
   {
   f=g;
   break;
   }
	}
	 fp=fopen("学生信息姓名.txt","a");
    fwrite(x,2,f,fp);
    fclose(fp);
	cout<<"输入第"<<i+1<<"个人的编号: ";
	cin>>a[i];
	// fp=fopen("学生信息编号.txt","w");
    //fwrite(y,2,100,fp);
   // fclose(fp);
	cout<<"输入第"<<i+1<<"个人的性别(男:1,女:2): ";
	cin>>b[i];
	 //fp=fopen("学生信息性别.txt","w");
    //fwrite(z,2,100,fp);
    //fclose(fp);
	cout<<"输入第"<<i+1<<"个人的职业(学生:1,老师:2): ";
	cin>>d[i];
	 //fp=fopen("学生信息职业.txt","w");
    //fwrite(o,2,100,fp);
    //fclose(fp);
     }
     do
     {
		 cout<<"输入编号查看学生、职工信息(输入0则退出): ";
         cin>>e;
         if(e==0)
         exit(0);
         for(f=0;f<20;f++)
         {          	
		   if(e==a[f])
		   
	       abc(f);
		   
         }
     }while(e!=0);
	
}
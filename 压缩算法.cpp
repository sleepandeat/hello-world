#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int i,j,k,len,how=0,flag,ll;
    char str[100]={"ni hao shi  jie,ni hao a shi "},zj[100],print[100]={"\0"},data[100][80],int_c[10]; 
    for(ll=0;ll<3;ll++)
    {
        //gets(str);
        len=strlen(str)+1;
        for(i=0,j=0;i<len;i++)
        {
            if(!(str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||i==len-1)
            {
               if(j==0){print[strlen(print)]=str[i];continue;}
               zj[j]='\0';flag=0;j=0;
               for(k=0;k<how;k++)
                   if(strstr(zj,data[k])!=NULL&&strstr(data[k],zj)!=NULL)
                   {
                      strcat(print,itoa(k,int_c,10));
                      flag=1;break;
                   }
               if(flag==0)
                   strcpy(data[how++],zj),strcat(print,zj);
               print[strlen(print)]=str[i];
               if(i==len-1)break;
               continue;
            }
            zj[j++]=str[i];
        }
    }
    printf("%s\n",print);
    getch(); 
} 

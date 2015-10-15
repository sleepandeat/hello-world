#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
    int s1[25],s2[25],i,j;
    char str[]={"ndaisuhdajsdkwhdlahJOHDNEIBAKHKFBAKBF"}; 
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    for(i=0;str[i]!='\0';i++)
    {
       for(j=0;j<25;j++)
         if(str[i]==j+65)s1[j]++;   
       for(j=0;j<25;j++)
         if(str[i]==j+97)s2[j]++;                    
    }
    for(j=0;j<25;j++)
         if(s1[j]!=0)printf("字母：%c有%d个\n",j+65,s1[j]);
    for(j=0;j<25;j++)
         if(s2[j]!=0)printf("字母：%c有%d个\n",j+97,s2[j]);
    getch();
} 


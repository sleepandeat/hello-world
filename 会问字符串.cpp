#include<stdio.h>
#include<conio.h>
int aa()
{
    int abc[26]={0},i,j,b=0,c=1;char str[]={"aaaaaa"};
    for(i=0;i<26;i++)abc[i]=0;
    for(i=0;str[i]!='\0';i++)
    {
       if(abc[str[i]-97]%2==0)
       {
          b++;abc[str[i]-97]++;
       }
       else abc[str[i]-97]++;
    }
    for(i=0;i<26;i++)
    if(abc[i]==b*2)return 1;
    for(i=0;i<26;i++)
    if(abc[i]%2!=0)return 0;
    for(i=1;i<=b;i++)c*=i;
    return c;
}
int main(void)
{
    printf("%d",aa()); 
    getch(); 
} 

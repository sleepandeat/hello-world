#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void aaa(char str[])
{
     int i=strlen(str),j,k,flag=0;
     char data[256];
     strcpy(data,str);
     for(j=0,k=0;j<i;j++) 
     {
         if(data[j]==' ')
         {
             if(flag++==0)
                 str[k++]=data[j];
         } 
         else 
         {
             str[k++]=data[j];flag=0; 
         }
     }
     str[k]='\0';i=strlen(str);
     if(str[i-1]==' ')str[i-1]='\0';
}
int main()
{
    char str[256];
    gets(str);aaa(str);
    printf("%s",str);
} 

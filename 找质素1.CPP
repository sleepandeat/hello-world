#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
    char str[]={"my,name,is,xiao,qiang."};
    int i=0,how_many=0,flag=0,orr=0,how_long=strlen(str)-1;
    do
    {
       if(str[i]!=' '&&str[i]!=','&&str[i]!='.'&&how_long!=i)
       {
           if(!((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')))
               orr=1;
           flag=1;
       }
       else
       {
           if(flag==1&&orr==0)
              how_many++;
           orr=0;flag=0;
       }
    }while(str[i++]);
    printf("%d",how_many);
	getch();
}






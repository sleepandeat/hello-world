#include <stdio.h>
int main(void){
   int year,month;
   scanf("%d%d",&year,&month);
   if(month>0&&month<13){
      switch(month){
        case 1:
	case 3:
	case 5:
	case 7:
	case 8:
        case 10:
	case 12:printf("31");
        case 4:
	case 6:
	case 9:
	case 11:printf("30");
        case 2: printf("%d",(year%4==0&&year%100!=0+year%400==0)?29:28);
      }      
   }
   else 
     printf("error");
   getchar();getchar();
   return 0;    
}

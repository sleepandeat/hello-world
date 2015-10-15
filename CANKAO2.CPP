#include <stdio.h>
#include<conio.h>
#include <time.h>
#include<dos.h>
main() 
{ 
clock_t start,end; 
int n=10;
start=end=clock(); 
while((n-(int)(end-start)/19)>=0&!kbhit()) 
{
printf("the time is: %d",n-(int)(end-start)/19); 
sleep(1);
end=clock(); 
} 
} 


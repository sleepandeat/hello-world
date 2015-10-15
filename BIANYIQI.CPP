#include<stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#define A   printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
int main()
{
  char a;
  char ab[18]="ni shi sha gua !";
  int shagua=0;
  int i,b=221,c=93,d=24,e=17,f=16,g=205,h=222,k=176;
  textbackground(1);
  textcolor(0);
  clrscr();
  window(1,25,80,25);
  textbackground(7);clrscr();
  printf("  F1 Help  Alt-F8 Next Msg  Alt-F7 Prev Msg  Alt-F9 Compile  F9 Make  F10 Menu");
  window(1,1,5,1);textbackground(7);clrscr();printf("  %c",240);
  window(5,1,11,1);textbackground(7);clrscr();printf(" File");
  window(11,1,17,1);textbackground(7);clrscr();printf(" Edit");
  window(17,1,25,1);textbackground(7);clrscr();printf(" Search");
  window(25,1,30,1);textbackground(7);clrscr();printf(" Run");
  window(30,1,39,1);textbackground(7);clrscr();printf(" Compile");
  window(39,1,46,1);textbackground(7);clrscr();printf(" Debug");
  window(46,1,55,1);textbackground(7);clrscr();printf(" Project");
  window(55,1,64,1);textbackground(7);clrscr();printf(" Options");
  window(64,1,74,1);textbackground(7);clrscr();printf("  Window");
  window(74,1,80,1);textbackground(7);clrscr();printf(" Help\n");
  printf("%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cNONAME00.C%c%c%c%c%c%c%c%c%c",201,g,91,93,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,d,c,g);
  window(6,2,6,2);textbackground(2);clrscr();
  printf("\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n",h,h,h,h,h,h,h,h,h,h,h,h,h,h);
  window(1,17,13,17);textbackground(9);clrscr();
  printf("%c%c%c%c%c%c1:",200,g,15,g,g,g);
  window(14,17,79,17);textbackground(3);clrscr();
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c--",e,221,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,k,f);
  window(1,18,80,24);textbackground(7);clrscr();A;A;A;A;A;A;A;A;A;A;A;A;A;
  printf("%c",176);
  window(79,3,80,3);textbackground(3);clrscr();printf(" %c",30);
  window(79,4,80,4);textbackground(3);clrscr();printf(" %c",219);
  window(79,5,80,5);textbackground(3);clrscr();printf(" %c",k);
  window(79,6,80,6);textbackground(3);clrscr();printf(" %c",k);
  window(79,7,80,7);textbackground(3);clrscr();printf(" %c",k);
  window(79,8,80,8);textbackground(3);clrscr();printf(" %c",k);
  window(79,9,80,9);textbackground(3);clrscr();printf(" %c",k);
  window(79,10,80,10);textbackground(3);clrscr();printf(" %c",k);
  window(79,11,80,11);textbackground(3);clrscr();printf(" %c",k);
  window(79,12,80,12);textbackground(3);clrscr();printf(" %c",k);
  window(79,13,80,13);textbackground(3);clrscr();printf(" %c",k);
  window(79,14,80,14);textbackground(3);clrscr();printf(" %c",k);
  window(79,15,80,15);textbackground(3);clrscr();printf(" %c",k);
  window(79,16,80,16);textbackground(3);clrscr();printf(" %c",31);

  window(2,3,79,16);textbackground(9);clrscr();
  do{
scanf("%s",&a);
printf("%c",222);
shagua++;
}while(shagua<2);
//printf("%c",222);
for(i=0;i<16;i++)
{
printf("%c",ab[i]);
sleep(1);
}
printf("  ha ha...\n%c\t",222);
getch();

for(int j=14;j<254;j++)
{
printf("%c ",j);
switch(j)
{
   case 30:
   case 60:
   case 90:
   case 120:
   case 150:
   case 180:
   case 210:
   case 230:printf("\n%c\t",222);sleep(1);break;

}
}
getch();
}


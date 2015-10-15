#include <stdio.h>
#include <math.h>
#include <conio.h> 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define LEN sizeof(struct TABLE)
#define SWAP(a,b) (t)=(b);(b)=(a);(a)=(t)
struct TABLE
{
  int num[3][3];
  struct TABLE*next;
};
struct TABLE*headofOPEN=NULL,*headofCLOSE=NULL,*pointer;
int t;
int target[3][3]={{2,8,3},{1,6,4},{7,0,5}};
main()
{
  int s0[3][3];
  int i,j,success=0;
  struct TABLE*AddtoOPEN(int array[3][3],struct TABLE*head1);
  struct TABLE*MovetoCLOSE(struct TABLE*head1,struct TABLE*head2);
  int ExtendOPEN(struct TABLE*point);
  void output(struct TABLE*head1);
  pointer=(struct TABLE*)malloc(LEN);
  printf("\n");
  for(i=0;i<3;i++)
    {
       printf("please input the %d line of s0:\n",i+1);
       for(j=0;j<3;j++)
       scanf("%d",&s0[i][j]);
     }
  headofOPEN=AddtoOPEN(s0,headofOPEN);
  while((headofOPEN!=NULL)&&(!success))
     {
        headofCLOSE=MovetoCLOSE(headofOPEN,headofCLOSE);
        success=ExtendOPEN(pointer);
      }
if(headofOPEN==NULL)
  printf("can't resolve this question!");
else
 {
  printf("this is the content of CLOSE:\n");
  output(headofCLOSE);
  printf("this is the content of OPEN:\n");
  output(headofOPEN);
  }
return 0;
}
struct TABLE*AddtoOPEN(int array[3][3],struct TABLE*head1)
{
   int i,j;
   struct TABLE*p0,*p1,*p2;
   p0=p1=p2=(struct TABLE*)malloc(LEN);
   if(head1==NULL)
  {
      for(i<0;i<3;i++)
      {
         for(j=0;j<3;j++)
           { 
              (p1->num)[i][j]=array[i][j];
            }
       }
    head1=p1;
    p1->next=NULL;
   }
   else
     {
        p1=head1;
        while(p1->next!=NULL)
         { 
              p2=p1;
              p1=p2->next;
          }
         for(i=0;i<3;i++)
            {
             for(j=0;j<3;j++)
                {
                   (p0->num)[i][j]=array[i][j];
                 }  
             }  
        p1->next=p0;
        p0->next=NULL;
      };
return(head1);
}
struct TABLE*MOVEtoCLOSE(struct TABLE*head1,struct TABLE*head2)
{
   int i,j;
   struct TABLE*p0,*p1,*p2;
   void output(struct TABLE*head1);
   p0=p1=p2=(struct TABLE*)malloc(LEN);
   if(head2==NULL)
  {
      for(i<0;i<3;i++)
      
         for(j=0;j<3;j++)
            
              (p1->num)[i][j]=(head1->num)[i][j];
            
       
    head2=p1;
    p1->next=NULL;
   }
   else
     {
        p1=head2;
        while(p1->next!=NULL)
         { 
              p2=p1;
              p1=p2->next;
          };
         for(i=0;i<3;i++)
            
             for(j=0;j<3;j++)
                
                   (p0->num)[i][j]=(head1->num)[i][j];
                   
             
        p1->next=p0;
        p0->next=NULL;
      };
pointer=headofOPEN;
headofOPEN=pointer->next;
return(head2);
}
int ExtendOPEN(struct TABLE*point)
{
   int i,j,positionx,positiony,flag,success=0;
   int temp1[3][3],temp2[3][3],temp3[3][3],temp4[3][3];
   int InOPEN(int array[3][3],struct TABLE*head1);
   int InCLOSE(int array[3][3],struct TABLE*head2);
   int Equal(int array1[3][3],int array2[3][3]);
   for(i=0;i<3;i++)
       {     
         for(j=0;j<3;j++)
            {
             if(((point->num)[i][j])==0)
               {
                 positionx=i; 
                 positiony=j;
                }
            }
       };
for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
     {
      temp1[i][j]=(point->num)[i][j];
      temp2[i][j]=(point->num)[i][j];
      temp3[i][j]=(point->num)[i][j];                                                                                                                                                                                                                                                      
      temp4[i][j]=(point->num)[i][j];
      }
   };
if((positiony>0)&&(!success))
{
SWAP(temp1[positionx][positiony],temp1[positionx][positiony-1]);
flag=((InOPEN(temp1,headofOPEN))||(InCLOSE(temp1,headofCLOSE)));
if(flag==0)
headofOPEN=AddtoOPEN(temp1,headofOPEN);
if(Equal(temp1,target))
success=1;
};
if((positiony>0)&&(!success))
{
SWAP(temp2[positionx][positiony],temp2[positionx-1][positiony]);
flag=((InOPEN(temp2,headofOPEN))||(InCLOSE(temp2,headofCLOSE)));
if(flag==0)
headofOPEN=AddtoOPEN(temp2,headofOPEN);
if(Equal(temp2,target))
success=1;
};
if((positiony<2)&&(!success))
{
SWAP(temp3[positionx][positiony],temp3[positionx][positiony+1]);
flag=((InOPEN(temp3,headofOPEN))||(InCLOSE(temp3,headofCLOSE)));
if(flag==0)
headofOPEN=AddtoOPEN(temp3,headofOPEN);
if(Equal(temp3,target))
success=1;
};
if((positiony<2)&&(!success))
{
SWAP(temp4[positionx][positiony],temp4[positionx+1][positiony]);
flag=((InOPEN(temp4,headofOPEN))||(InCLOSE(temp4,headofCLOSE)));
if(flag==0)
headofOPEN=AddtoOPEN(temp4,headofOPEN);
if(Equal(temp4,target))
success=1;
};
return(success);
}
int InOPEN(int array[3][3],struct TABLE*head1)
{
 int i,j,flag1,flag2=0;
 struct TABLE*p1,*p2;
 p1=head1;
 while((p1!=NULL)&&(!flag2))
   {
     flag1=0;
     for(i=0;i<3;i++)
        for(j=0;j<3;j++)
          if(array[i][j]!=(p1->num)[i][j])
             flag1=1;
     if(flag1==0)
        flag2=1;
       p2=p1;
       p1=p2->next;
       }
return(flag2);
}
int InCLOSE(int array[3][3],struct TABLE*head2)
{
 int i,j,flag1,flag2=0;
 struct TABLE*p1,*p2;
 p1=head2;
 while((p1!=NULL)&&(!flag2))
   {
     flag1=0;
     for(i=0;i<3;i++)
        for(j=0;j<3;j++)
          if(array[i][j]!=(p1->num)[i][j])
             flag1=1;
     if(flag1==0)
        flag2=1;
       p2=p1;
       p1=p2->next;
       }
return(flag2);
}
int Equal(int array1[3][3],int array2[3][3])
{
int i,j,flag3=1;
for(i=0;i<3;i++)
   {
   for(j=0;j<3;j++)
     {
      if(array1[i][j]!=array2[i][j])
      flag3=0;
      }
   }
return(flag3);
}
void output(struct TABLE*head1)
{
int i,j,k=0;
struct TABLE*p1,*p2;
p1=head1;
while(p1!=NULL)
    { 
      if(k%2==1)  printf("  ");
      k++;
      for(i=0;i<3;i++)
        {for(j=0;j<3;j++)
           printf("%",(p1->num)[i][j]);
         if(i!=2)printf(";");
         }

     
  if(k%2==0) printf("\n");
  p2=p1;
  p1=p2->next;
     }
}

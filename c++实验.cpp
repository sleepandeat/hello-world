#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std; 
void ddd(int a);
class student{
      public:
             int print(int x,int y);
             void init(int data,const char *string);
      private:
              int data;
              char str[50];
      };
int main()
{
    int data;
    student aa,bb;
    //student *spi=&aa;// new student ;
    //aa.init(10,"aaa");
    //cout<<spi->print(3,10)<<endl; 
    //cout<<(cin>>data)<<endl;
    ddd(2);
    getch();
    return 0;
} 
void ddd(int a)
{
     assert(a==1);
     printf("aasasaaa");
}
int student::print(int x,int y)
{
     //cout<<str<<endl;
     printf("%s\n",str);
     return (x+y+data);
}
void student::init(int data,const char *string)
{
     this->data=data;
     strcpy(str,string);
     cout<<data<<endl;
}

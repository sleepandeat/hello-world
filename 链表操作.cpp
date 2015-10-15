#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
#include<conio.h>
struct stu
{
       char name[50];
       int number;
       struct stu *next;
};
struct stu *head=NULL;
void link(struct stu *head,struct stu *new_node)//链接 参数1：head  参数2：新创建的结点  返回：head 
{
    struct stu *node1,*node2;
    if(new_node==NULL)return; 
    if(head==NULL) 
    {
        head=new_node;return;
    }
    node1=head;
    while(node1!=NULL)
    {
        node2=node1;
        node1=node1->next;              
    }
    node2->next=new_node;
}
void creat(char name[],int number)//链接 参数1：head  参数2：新节点的name 参数3：新节点的学号  返回：head 
{
    struct stu *node1,*node2;
    node1=(struct stu*)malloc(sizeof(struct stu));
    strcpy(node1->name,name);
    node1->number=number; 
    node1->next=NULL;
    link(head,node1);
    return;
}
int main()
{
    struct stu *node1,*node2;
    creat("张三",11101);printf("名字：%s\t学号：%d\n",head->name,head->number);getch();
    creat("李四",11102);
    creat("王五",11103);
    node1=head;
    while(node1!=NULL) 
    {
       printf("名字：%s\t学号：%d\n",node1->name,node1->number);
       node1=node1->next;
    }
    getch();
} 

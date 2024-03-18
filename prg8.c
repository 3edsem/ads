#include<stdio.h>
#include<stdlib.h>
struct employee
{
char name[15],ssn[15],dept[15],des[15],sal[15],phno[15];
struct employee *rlink,*llink;
};
struct employee *first=NULL,*temp,*cur,*prev;
void insertf();
void insertr();
void deletef();
void deleter();
void display();
int main( )
{
int choice;
while(1)
{
printf("\n ***Operations of Doubly linked list*** \n");
printf(" \n 1:Insert front\n 2:Insert rear \n 3:Delete front\n 4:Delete rear \n 5:Display\n 6:Exit \n");
printf("\n Enter your choice \n");
scanf("%d",&choice);
switch(choice)
{
case 1:insertf();
break;
case 2:insertr();
break;
case 3:deletef();
break;
case 4:deleter();
break;
case 5:display();
break;
case 6:exit(0);
}
}
}
void insertf()
{
temp=(struct employee*) malloc(sizeof(struct employee));
printf("\nEnter the name,ssn,dept,designation,salary and phone.no:");
scanf("%s%s%s%s%s%s",temp->name,temp->ssn,temp->dept,temp->des,temp->sal,temp->phno);
temp->llink=temp->rlink=NULL;
if(first==NULL)
{
first=temp;
return;
}
temp->rlink=first;
first->llink=temp;
first=temp;
}
void insertr()
{
temp=(struct employee*) malloc(sizeof(struct employee));
printf("\nEnter the name,ssn,dept,designation,salary and phone.no:");
scanf("%s%s%s%s%s%s",temp->name,temp->ssn,temp->dept,temp->des,temp->sal,temp->phno);
temp->llink=temp->rlink=NULL;
if(first==NULL)
{
first=temp;
return;
}
cur=first;
while(cur->rlink!=NULL)
cur=cur->rlink;
cur->rlink=temp;
temp->llink=cur;
}
void display( )
{
int c=0;
temp=(struct employee*) malloc(sizeof(struct employee));
if(first==NULL)
{
printf("\n list is empty \n");
return;
}
printf("\n The contents of linked list are \n");
printf("Name\t\tSSN\t\tDept\t\tDesignation\t\tSalary\t\tPhoneNo ");
printf("\n......................................................................\n");
temp=first;
while(temp!=NULL)
{
printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s",temp->name,temp->ssn,temp->dept,temp->des,temp->sal,temp->phno);
printf("\n");
temp=temp->rlink;
c++;
}
printf("\nTotal no.of Students:%d",c);
}
void deletef()
{
if(first==NULL)
{
printf("\n List is empty \n");
return;
}
temp=first;
printf("\n First node in the list is deleted\n");
first=first->rlink;
first->llink=NULL;
free(temp);
}
void deleter()
{
if(first==NULL)
{
printf("\n List is empty \n");
return;
}
if(first->rlink==NULL)
{
printf(" List contains only one node,that is deleted");
first=NULL;
return;
}
prev=NULL;
cur=first;
while(cur->rlink!=NULL)
{
prev=cur;
cur=cur->rlink;
}
prev->rlink=NULL;
printf("\n Last node in the list is deleted \n");
free(cur);
}
#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[15],sem[15],usn[15],branch[15],phone[15];
struct student *link;
};
struct student *first=NULL,*temp,*cur,*prev;
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
printf("\n ***Operations of Singly linked list*** \n");
printf(" \n 1:Insert front\n 2:Insert rear \n 3:Delete front\n 4:Delete rear \n 5:display\n 6:exit \n");
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
temp=(struct student*) malloc(sizeof(struct student));
printf("\nEnter the name,sem,usn,branch and phone.no:");
scanf("%s%s%s%s%s",temp->name,temp->sem,temp->usn,temp->branch,temp->phone);
temp->link=first;
first=temp;
}
void insertr()
{
temp=(struct student*) malloc(sizeof(struct student));
printf("\nEnter the name,sem,usn,branch and phone.no:");
scanf("%s%s%s%s%s",temp->name,temp->sem,temp->usn,temp->branch,temp->phone);
temp->link=NULL;
if(first==NULL)
{
first=temp;
return;
}
cur=first;
while(cur->link!=NULL)
cur=cur->link;
cur->link=temp;
}
void display( )
{
int c=0;
temp=(struct student*) malloc(sizeof(struct student));
if(first==NULL)
{
printf("\n list is empty \n");
return;
}
printf("\n The contents of linked list are \n");
printf("name\t\tsem\t\tusn\t\tBranch\t\tPhone no ");
printf("\n......................................................................\n");
temp=first;
while(temp!=NULL)
{
printf("%s\t\t%s\t\t%s\t\t%s\t\t%s",temp->name,temp->sem,temp->usn,temp->branch,temp->phone);
printf("\n");
temp=temp->link;
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
printf("\n First student details in the list is deleted\n");
first=first->link;
free(temp);
}
void deleter()
{
if(first==NULL)
{
printf("\n List is empty \n");
return;
}
if(first->link==NULL)
{
printf(" List contains one student details,that is deleted");
first=NULL;
return;
}
prev=NULL;
cur=first;
while(cur->link!=NULL)
{
prev=cur;
cur=cur->link;
}
prev->link=NULL;
printf("\n Last student details in the list is deleted \n");
free(cur);
}
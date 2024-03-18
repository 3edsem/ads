#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void insert();
void delete();
void display();
char q[MAX], elem;
int f=0, r=0, i, c=0, front, ch;
void insert()
{
if(c==MAX)
{
printf("\nQueue is full");
return;
}
printf("Enter the character to insert:");
scanf("%s",&elem);
q[r]=elem;
r=(r+1)%MAX;
c++;
}
void delete()
{
if (c == 0)
printf("Queue is empty");
else
{
printf("\nDeleted element is:%c",q[f]);
f = (f+1)% MAX;
c--;
}
}
void display()
{
if(c==0)
{
printf("Queue is empty\n");
return;
}
printf("\nQueue elements are:");
front=f;
for(i=0; i<c;i++)
{
printf("%c\t",q[front]);
front=(front+1)%MAX;
}
printf("\n");
}
int main()
{
while(1)
{
printf("\n*Circular Queue Operations*\n1.Insert\n2.Delete\n3.Display\n4.Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();
break;
case 2: delete();
break;
case 3: display();
break;
case 4: exit(0);
}
}
}
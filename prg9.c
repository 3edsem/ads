#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
struct poly
{
int cf,px,py,pz;
struct poly *link;
};
typedef struct poly *NODE;
void read(NODE head);
void display(NODE head);
void eval( );
void polysum( );
void main( )
{
int sum=0,ch;
while(1)
{
printf("\n 1:Polynomial Evaluation\n 2:Sum of two polynomial\n3:exit\n");
printf("\n Enter choice \n");
scanf("%d",&ch);
switch(ch)
{
case 1:eval( );
break;
case 2:polysum( );
break;
case 3:exit(0);
}
}
}
void read(NODE head)
{
NODE temp,cur;
int n,i,x,y,z;
printf("\nEnter no of terms \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
temp=(NODE)malloc(sizeof(struct poly));
printf("\n Enter cf,px,py and pz of %i term\n",i+1);
scanf("%d%d%d%d",&temp->cf,&temp->px,&temp->py,&temp->pz);
temp->link=head;
cur=head->link;
while(cur->link!=head)
cur=cur->link;
cur->link=temp;
}
}
void display(NODE head)
{
NODE temp;
if(head->link==head)
{
printf("\nPolynomial doesn't exist\n");
return;
}
temp=head->link;
while(temp!=head)
{
if(temp->cf<0)
printf(" %d",temp->cf);
else
printf(" + %d",temp->cf);
printf("x^%dy^%dz^%d",temp->px,temp->py,temp->pz);
temp=temp->link;
}
printf("\n");
}
void eval( )
{
int sum=0,x,y,z;
NODE head,temp;
head=(NODE)malloc(sizeof(struct poly));
head->link=head;
printf("\nEnter polynomial to Evaluate\n");
read(head);
printf("Polynomial : ");
display(head);
printf("\n Enter the value of x,y and z \n");
scanf("%d%d%d",&x,&y,&z);
temp=head->link;
while(temp!=head)
{
sum=sum+((temp->cf)*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz));
temp=temp->link;
}
printf("\n");
printf("\n Sum=%d",sum);
}
void polysum( )
{
NODE temp,cur,prev,cur1,cur2,head1,head2;
int cf,px,py,pz,x,y,z;
head1=(NODE)malloc(sizeof(struct poly));
head2=(NODE)malloc(sizeof(struct poly));
head1->link=head1;
head2->link=head2;
printf("\nEnter First polynomial");
read(head1);
printf("\nEnter Second polynomial");
read(head2);
printf("\nFirst polynomial : ");
display(head1);
printf("\nSecond polynomial : ");
display(head2);
cur1=head1->link;
while(cur1!=head1)
{
prev=head2;
cur2=head2->link;
while(cur2!=head2)
{
if(cur1->px==cur2->px && cur1->py==cur2->py &&cur1->pz==cur2->pz)
{
cur1->cf=cur1->cf+cur2->cf;
prev->link=cur2->link;
free(cur2);
break;
}
prev=cur2;
cur2=cur2->link;
}
prev=cur1;
cur1=cur1->link;
}
prev->link=head2->link;
head2->link=head1->link;
printf("\nResultant polynomial:");
display(head2);
}
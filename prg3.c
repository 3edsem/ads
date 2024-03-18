#include<stdlib.h>
#include<stdio.h>
#define max 20
int s[max],top=-1,ch;
int i,temp,elem;
void push();
void pop();
void display();
void pali();
int main()
{
while(1)
{
printf("\n\n--------STACK OPERATIONS--------\n");
printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\n");
printf("\nEnter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: pali();
break;
case 5:
exit(0);
}
}
}
void push()
{
printf("\nEnter the element to be inserted:");
scanf("%d",&elem);
if(top==max-1)
printf("\nStack overflow");
else
s[++top]=elem;
temp=top;
}
void pop()
{
if(top==-1)
printf("\nStack underflow");
else;
top--;
}
void display()
{
if(top==-1)
printf("\nStack underflow");
else
{
printf("\n Stack elements are:");
for(i=0;i<=top;i++)
printf("%d\t",s[i]);
}
}
void pali()
{
printf("\nEnter a number to check for palindrome:");
scanf("%d",&elem);
top=-1,temp=elem;
while(temp)
{
s[++top]=temp%10;
temp=temp/10;
}
temp=elem;
while(temp)
{
if(s[top--]!=(temp%10))
{
printf("\nNot a palindrome");
return;
}
temp=temp/10;
}
printf("\nIt is a palindrome");
}
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
char postfix[20];
int result, i, s[20], op1,op2, top=-1;
printf("\nEnter the postfix expression:");
scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++)
{
if(isdigit(postfix[i])) // if operand push on stack
s[++top]=postfix[i]-'0';
else
{
op2=s[top--];
op1=s[top--];
switch(postfix[i])
{
case '+':result=op1+op2;
break;
case '-':result=op1-op2;
break;
case '*':result=op1*op2;
break;
case '/':result=op1/op2;
break;
case '%':result=op1%op2;
break;
case '^':result=pow(op1,op2);
break;
}
s[++top]=result;
}
}
printf("\nResult=%d",result);
}
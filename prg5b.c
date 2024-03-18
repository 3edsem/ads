#include<stdio.h>
void tower(int n, char s, char d, char t)
{
if(n==0)
return;
tower(n-1,s,t,d);
printf("\n Move Disc %d from %c to %c", n,s,d);
tower(n-1,t,d,s);
}
int main()
{
int n;
printf("\nEnter no of discs\n");
scanf("%d",&n);
tower(n,'A','C','B');
}
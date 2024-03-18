#include<stdio.h>
#include<stdlib.h>
struct BST
{
int info;
struct BST *llink,*rlink;
};
struct BST *root=NULL,*temp,*cur,*prev;
int item;
void create();
void inorder();
void preorder();
void postorder();
void search();
void main( )
{
int choice;
while(1)
{
printf("\n\n Operations of Binary search tree \n");
printf(" \n 1:create \n 2:traverse \n 3:Search key element\n 4:exit \n");
printf("\n Enter your choice \n");
scanf("%d",&choice);
switch(choice)
{
case 1:create();
break;
case 2:if(root==NULL)
{
printf("\n Tree is empty \n");
break;
}
printf("\n Contents of the tree are \n");
printf("\n Inorder :");
inorder(root);
printf("\n Preorder :");
preorder(root);
printf("\n Postorder :");
postorder(root);
break;
case 3:search();
break;
case 4:exit(0);
}
}
}
void create()
{
temp=(struct BST*)malloc(sizeof(struct BST));
printf("\n Enter an element \n");
scanf("%d",&item);
temp->info=item;
temp->llink=temp->rlink=NULL;
if(root==NULL)
{
root=temp;
return;
}
prev=NULL;
cur=root;
while(cur!=NULL)
{
if(item==cur->info)
{
printf("\n Duplicate items are not allowed \n");
free(temp);
return;
}
prev=cur;
if(item<cur->info)
cur=cur->llink;
else
cur=cur->rlink;
}
if(item<prev->info)
prev->llink=temp;
else
prev->rlink=temp;
}
void inorder(struct BST *root)
{
if(root==NULL)
return;
inorder(root->llink);
printf("%d,",root->info);
inorder(root->rlink);
}
void preorder(struct BST *root)
{
if(root==NULL)
return;
printf("%d,",root->info);
preorder(root->llink);
preorder(root->rlink);
}
void postorder(struct BST *root)
{
if(root==NULL)
return;
postorder(root->llink);
postorder(root->rlink);
printf("%d,",root->info);
}
void search()
{
if(root==NULL)
{
printf("\n Tree is empty \n");
return;
}
printf("\n Enter key element \n");
scanf("%d",&item);
cur=root;
while(cur!=NULL)
{
if(item==cur->info)
{
printf("\n Element is found \n");
return;
}
if(item<cur->info)
cur=cur->llink;
else
cur=cur->rlink;
}
if(cur==NULL)
printf("\n Element is not found \n");
}
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
void create(struct node **root,int num);
void Inorder(struct node *temp);
void Preorder(struct node *temp);
void Postorder(struct node *temp);
int main()
{
	int ch ,dat;
	struct node *root=NULL;
	struct node *temp=NULL;
	while (1)
	{
		printf("1.create\n");
		printf("2.Inorder\n");
		printf("3.Preorder\n");
		printf("4.Postorder\n");
		printf("5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data \n");
				scanf("%d",&dat);
				create(&root,dat);
				break;
			case 2:
				temp=root;
				Inorder(temp);
				printf("\n");
				break;
			case 3:
				temp=root;
				Preorder(temp);
				printf("\n");
				break;
			case 4:
				temp=root;
				Postorder(temp);
				printf("\n");
				break;
			case 5:
				exit(1);
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void create(struct node **root,int num)
{
	struct node *temp,*point,*parent;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->left=NULL;
	temp->right=NULL;
	if(*root==NULL)
	{
		*root=temp;
	}
	else
	{
		point=*root;
		parent=*root;
		while(point!=NULL)
		{
			parent=point;
		if(temp->data < point->data)
		{
			point=point->left;
			}	
			else
			{
			point=point->right;	
			}
		}
		if(temp->data < parent->data)
{
	parent->left=temp;
}
else
{
parent->right=temp;
}
	}
}
void Inorder(struct node *temp)
  {
  	if(temp!=NULL)
  	{
  Inorder(temp->left);                         //Inorder
  printf("%d\t",temp->data);
  Inorder(temp->right);
}
}
void Preorder(struct node *temp)
  {
  	if(temp!=NULL)
  	{                  //preorder
  printf("%d\t",temp->data);
  Preorder(temp->left);
  Preorder(temp->right);
}
}
void Postorder(struct node *temp)
  {
  	if(temp!=NULL)
  	{
  Postorder(temp->left);    
  Postorder(temp->right);                     //postorder
  printf("%d\t",temp->data);
}
}

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
struct node *Preorder(struct node *temp);
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
	struct node *newnode,*parent,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->left=NULL;
	newnode->right=NULL;
	if (*root==NULL)
	{
		*root=newnode;
	}
	else 
	{
		ptr=*root;
		parent=*root;
		while(ptr!=NULL)
		{
			parent=ptr;
			if (num<ptr->data)
			{
				ptr=ptr->left;
			}
			else  
			{
				ptr=ptr->right;
			}
		}
	if (num<parent->data)
	{
		parent->left=newnode;
	}
	else
	{
		parent->right=newnode;
	}
  }
}
void Inorder(struct node *temp)
  {
  	if(temp!=NULL)
  	{
  Inorder(temp->left);                         //Inorder
  printf("%d,",temp->data);
  Inorder(temp->right);
}
}
struct node *Preorder(struct node *temp)
  {
  if (temp!=NULL)
	{
		printf("\n%d",temp->data);
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
  printf("%d,",temp->data);
}
}

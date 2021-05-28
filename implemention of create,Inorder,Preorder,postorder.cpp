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
	int ch,dat;
	struct node *root=NULL;
	struct node *temp=NULL;
	while(1)
	{
		printf("1.create\n");
		printf("2.Inorder traversal\n");
		printf("3.Preorder traversal\n");
		printf("4.Postorder traversal\n");
		printf("5.Exit\n");
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
void create (struct node **root,int num)
{
	struct node *temp,*parent1,*parent2;
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
		parent1=*root;
		parent2=*root;
		while(parent1!=NULL)
	{
		parent2=parent1;
		if(temp->data < parent1->data)
		{
			parent1=parent1->left;
		}
		else
		{
			parent1=parent1->right;
		}
	}
		if(temp->data < parent2->data)
		{
			parent2->left=temp;
		}
		else
		{
			parent2->right=temp;
		}
	}	
}
void Inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		Inorder(temp->left);
		printf("%d,",temp->data);
		Inorder(temp->right);
	}
}
void Preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d,",temp->data);
		Preorder(temp->left);
		Preorder(temp->right);
	}
}
void Postorder(struct node *temp)
{
	if(temp!=NULL)
	{
		Postorder(temp->left);
		Postorder(temp->right);
		printf("%d,",temp->data);
	}
}




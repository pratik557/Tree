#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node *leftchild;
	struct node *rightchild;
};
struct node *root=NULL;
int n,num,i;
struct node *create()
{
		struct node *temp,*point;
		printf("enter the number of nodes");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
    temp=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&num);
	temp->data=num;
    temp->leftchild=NULL;
	temp->rightchild=NULL;
	if(i==0)
	root=temp;
	else 
	{
		point=root;
		while(point)
		{
			if(temp->data > point->data)
			{
				if(point->rightchild=NULL)
				{
				point->rightchild=temp;
				break;
		    }
				else
			   point=point->rightchild;
			}
		}
	}
			if(point->leftchild=NULL)
			{
				point->leftchild=temp;
				break;
			}
			else
			{
				point=point->leftchild;
			}
	}
}
int main()
{
	create();
	return 0;
}

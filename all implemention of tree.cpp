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
struct node *smallestelement(struct node *temp);
struct node *largestelement(struct node *temp);
int totalnode(struct node *temp);
struct node *mirrorimage(struct node *temp);
struct node *deletionoftree(struct node *temp);
int heightoftree(struct node *temp);
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
		printf("5.smallest element \n");
		printf("6.largest element\n");
		printf("7.total number of nodes in tree\n");
        printf("8.mirror image of tree\n");
        printf("9.The Height/Depth of the tree is\n");
		printf("10.deletion of tree\n");
		printf("11.Exit\n");
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
				temp=root;
				smallestelement(temp);
				printf("\n Smallest element is : %d ",temp->data);
				printf("\n");
				break;
			case 6:
				temp=root;
				largestelement(temp);
				printf("\n largest element is : %d ",temp->data);
				printf("\n");
				break;
			case 7:
				printf("Total number of the tree : %d",totalnode(temp));
				printf("\n");
				break;
			case 8:
				mirrorimage(temp);
				printf("\n");
				break;
			case 9:
				temp=root;
				printf("The heigth/Depth of the tree is: %d ",heightoftree(temp));
				printf("\n");
				break;	
			case 10:
				deletionoftree(temp);
				printf("The tree is deleted");
				printf("\n");
				break;			
			case 11:
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
			parent1=parent1->left;   //as we know if value is less than root then left otherwise,right.
		}                            //here,parent1 is used to initilize the the path.
		else
		{
			parent1=parent1->right;
		}
	}
		if(temp->data < parent2->data)
		{
			parent2->left=temp;        //parent2 is used to put the value of temp after comparing with root.
		}
		else
		{
			parent2->right=temp;
		}
	}	
}
void Inorder(struct node *temp)
{                                    //As per rule of INORDER--->LR*R(let, R*=root)
	if(temp!=NULL)
	{
		Inorder(temp->left);
		printf("%d,",temp->data);
		Inorder(temp->right);
	}
}
void Preorder(struct node *temp)
{                                    //As per the rule of PREORDER-->R*LR
	if(temp!=NULL)
	{
		printf("%d,",temp->data);
		Preorder(temp->left);
		Preorder(temp->right);
	}
}
void Postorder(struct node *temp)
{                                         //As per the rule of postorder-->LRR*
	if(temp!=NULL)
	{
		Postorder(temp->left);
		Postorder(temp->right);
		printf("%d,",temp->data);
	}
}
struct node *smallestelement(struct node *temp)
{                                               
	if((temp==NULL)|| (temp->left==NULL))
	return temp;
	else
	return smallestelement(temp->left);    //as we know smallest will go through left so we return left data.
}
struct node *largestelement(struct node *temp)
{
	if((temp==NULL)||(temp->right==NULL))
	return temp;
	else
	return largestelement(temp->right);    //as we know largest will go through right so we return right data.
}
int totalnode(struct node *temp)
{
	if(temp!=NULL)
	return(totalnode(temp->left) + totalnode(temp->right) + 1);    // as we know the logic of counting totalnode.
}
struct node *mirrorimage(struct node *temp)
{
	struct node *parent1;
	if(temp!=NULL)
	{
	mirrorimage(temp->left);
	mirrorimage(temp->right);
	parent1=temp->left;
	parent1->left=parent1->right;    //using swapping logic.
	temp->right=parent1;
}
}
int heightoftree(struct node *temp)
{
	int leftheight,rightheight;
	if (temp==NULL)
	{
		return 0;
	}
	else
	{
	leftheight=heightoftree(temp->left);
	rightheight=heightoftree(temp->right);    
	if(leftheight>rightheight)               //choose the longest chain which is height/depth of the tree.
	return (leftheight+1);                   // so,if left > right then left+1(:->+1 for root) else right+1
	else
	return (rightheight+1);
}	
}
struct node *deletionoftree(struct node *temp)
{
	if(temp!=NULL)
	{
		deletionoftree(temp->left);
		deletionoftree(temp->right);
		free(temp);                         //here we free the temp which is considered as root.  
	}
}

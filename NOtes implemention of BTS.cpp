#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
void create(struct node **root,int num);
int kthlevel(struct node *temp,int n);
int countleafnode(struct node *temp);
int countNonleafnode(struct node *temp);
int totalnode(struct node *temp);
int sumofnode(struct node *temp);
int depthoftree(struct node *temp);
int IsBST(struct node *temp);
int nodeatmaxdepth(struct node *temp);
int AncestorsOfNode(struct node *temp,int num);
int main()
{
	int ch,dat,n;
	struct node *root=NULL;
	struct node *temp=NULL;
	while(1)
	{
		printf("1.create\n");
		printf("2.The element of the kth level\n");
		printf("3.count number of leaf\n");
		printf("4.count number of leaf\n");
		printf("5.count number of total node in tree\n");
		printf("6.sum of total node in tree\n");
	    printf("7.Depth/Height of the tree\n");
		printf("8.check whether it is binary tree or not\n");
		printf("9.print the ancestor of the selected node\n");
		printf("10.Exit\n");
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
				printf("Enter the Nth level: \n");
				scanf("%d",&n);
				printf("The element of selected level : %d \n are : ",n);
				kthlevel( temp ,n);
				printf("\n");
				break;
			case 3:
				temp=root;
				printf("Number of the leaf node in tree is: %d ",countleafnode(temp));
				printf("\n");
				break;
			case 4:
				temp=root;
				printf("Number of the Non-leaf node in tree is: %d ",countNonleafnode(temp));
				printf("\n");
				break;
			case 5:
				temp=root;
				printf("total number of nodes in tree: %d ",totalnode(temp));
				printf("\n");
				break;
			case 6:
				temp=root;
				printf("sum of the total node: %d ",sumofnode(temp));
				printf("\n");
				break;
			case 7:
				temp=root;
				printf("The heigth/Depth of the tree is: %d ",depthoftree(temp));
				printf("\n");
				break;
			case 8:
				temp=root;
			    if(IsBST(temp)) 
                printf("The binary tree is a binary search tree"); 
                else
                printf("The binary tree is not a binary search tree");
     		    printf("\n");
     		    break;
     		case 9:
			    temp=root;
				printf("Enter the Nth node: \n");
				scanf("%d",&n);
				printf("The ancestor of the given node : %d : ",AncestorsOfNode(temp,n));
				printf("\n");
				break;
			case 10:
				exit(1); 
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void create(struct node **root,int num)
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
int kthlevel(struct node *temp,int n)
{	
	if(n==0)
	{
		printf("%d",temp->data); //if k value is 0 then the root value get printed else,temp->left or temp->right value
	}                           //get printed
	else
	{
		kthlevel(temp->left,n-1);
		kthlevel(temp->right,n-1);
	}
}
int countleafnode(struct node *temp)
{
	if(temp==NULL)
	return 0;                       
	else if(temp->left==NULL && temp->right==NULL)
	return 1;                                       
	else                                            
	return countleafnode(temp->left) + countleafnode(temp->right);   //leaf node=left+right.
}
int countNonleafnode(struct node *temp)
{
	if(temp==NULL || (temp->left==NULL && temp->right==NULL))
	return 0;
	else                                                      
	return 1 + countNonleafnode(temp->left) + countNonleafnode(temp->right);
	//here we are taking return 1(as root node) + left + right cause root node is also an non leaf node. 
}
int totalnode(struct node *temp)
{
	if(temp!=NULL)
	return(totalnode(temp->left) + totalnode(temp->right) + 1);    // as we know the logic of counting totalnode.
}
int sumofnode(struct node *temp)
{
	if(temp!=NULL)
	return (temp->data + sumofnode(temp->left) + sumofnode(temp->right));
}//here,we add temp->data(as root node) + sum of left + sum of right.

int depthoftree(struct node *temp)
{
	int leftdepth,rightdepth;
	if (temp==NULL)
	{
		return 0;
	}
	else
	{
	leftdepth=depthoftree(temp->left);
	rightdepth=depthoftree(temp->right);    
	if(leftdepth>rightdepth)               //choose the longest chain which is height/depth of the tree.
	return (leftdepth+1);                 // so,if left > right then left+1(:->+1 for root) else right+1
	else
	return (rightdepth+1);
}
}
int IsBST(struct node *temp)
{    
  if (temp==NULL)  
    return 1;   //if root=temp will be NULL then return true which is (1)
  if (temp->left!=NULL && temp->left->data > temp->data)  
    return 0;  // if left->data > root->data then return false which is (0)
  if (temp->right!=NULL && temp->right->data < temp->data)  
    return 0;  // if right->data < root->data then return false which is (0)
  if (!IsBST(temp->left) || !IsBST(temp->right))  
    return 0;   //if both are not BST tree then return false which is (0)
	else  
    return 1;   	//when the all if part will be false then return true which is (1) that means its a BTS.
}
int AncestorsOfNode(struct node *temp, int num)
{
  if (temp == NULL)
    return 0;  
  if (temp->data == num)
  {
  if (AncestorsOfNode(temp->left, num) || AncestorsOfNode(temp->right, num) ) 
	{
    printf("%d ", temp->data); //If num is present is any any of the two sub tree of root 
    }                          //then root is an ancestor of num 
  else 
  {
    return 0;   //If none of the sub tree of root contains num,then root is not an ancestor of num     
  }
}
}

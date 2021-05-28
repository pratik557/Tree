#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct NODE
    {
        struct NODE *left;
        int data;
        struct NODE *right;
    }*root=NULL;

struct NODE *getNode(int num)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=num;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }

void addNode(struct NODE **root)
    {
        int num;
        printf("\nEnter the value: ");
        scanf(" %d",&num);
        
        if(*root==NULL)
            *root=getNode(num);
        else
            {
                struct NODE *temp=*root;
                struct NODE *ptr;
                while(temp)
            }
                if(num<ptr->data)
                    ptr->left=getNode(num);
                else
                    ptr->right=getNode(num);
            }
    }

bool isPresent(struct NODE **root,int num)
    {
        bool flag=false;
        struct NODE *temp=*root;
        while(temp)
            {
                if(num==temp->data)
                    {
                        flag=true;
                        break;
                    }
                else if(num<temp->data)
                    temp=temp->left;
                else
                    temp=temp->right;
            }
        return flag;
    }
int main()
{
	getnode(5);
	addnode();
	ispresent();
	
}

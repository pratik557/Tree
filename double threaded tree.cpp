#include<stdio.h>
#include<stdlib.h>

struct Node 
{ 
	int data; 
	Node *left, *right; 
	bool rightThread; 
}; 
struct Node* leftMost(struct Node *n) 
{ 
	if (n == NULL) 
	return NULL; 
	while (n->left != NULL) 
	n = n->left; 
	return n; 
}  
void inOrder(struct Node *root) 
{ 
	struct Node *cur = leftmost(root) 
	while (cur != NULL) 
	{ 
		printf("%d ", cur->data); 
		if (cur->rightThread) 
			cur = cur->right; 
		else  
			cur = leftmost(cur->right); 
	} 
}
void inOrder(struct Node *root) 
{ 
    struct Node *cur = leftmost(root); 
    while (cur != NULL) 
    { 
        printf("%d ", cur->data);  
        if (cur->rightThread) 
            cur = cur->right; 
        else 
            cur = leftmost(cur->right); 
    } 
}


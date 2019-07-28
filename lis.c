#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left,*right;
};

int max(int a,int b)
{
	return(a>b?a:b);
}

struct node* newNode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int liss(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	
}

int main() 
{ 
    struct node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25); 
    printf ("Size of the Largest Independent Set is %d ", liss(root)); 
    return 0; 
} 

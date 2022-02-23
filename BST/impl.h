#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

struct bst* insert(struct bst *t, int c)
{
	if(t == NULL)
	{
		t = (struct bst*)malloc(sizeof(struct bst));
		t->data = c;
		t->right = NULL;
		t->left = NULL;
	}
	
	else if(c < t->data)
		t->left = insert(t->left,c);
		
	else if(c > t->data)
		t->right = insert(t->right,c);
		
	return t;
}

void normal_display(struct bst *t, int depth)
{
	if(t!=NULL)
	{
		for(int i = 0; i<depth; i++)
			printf("\t");
			
		printf("%d\n",t->data);
		normal_display(t->left,depth+1);
		normal_display(t->right,depth+1);
	}
}

struct bst* find(struct bst *t, int item)
{
	if(t==NULL || t->data == item)
		return t;
		
	else if(item < t->data)
		return find(t->left,item);
		
	else if(item > t->data)
		return find(t->right,item);
}

struct bst* findmin(struct bst *t)
{
	if(t->left == NULL || t==NULL)
		return t;
		
	else
		return findmin(t->left);
}

void inorder(struct bst *t)
{
	if(t->left != NULL)
		inorder(t->left);
		
	printf("%d ",t->data);
	
	if(t->right != NULL)
		inorder(t->right);
}

void preorder(struct bst *t)
{
	printf("%d ",t->data);
	
	if(t->left != NULL)
		preorder(t->left);
	
	if(t->right != NULL)
		preorder(t->right);
}

void postorder(struct bst *t)
{	
	if(t->left != NULL)
		postorder(t->left);
	
	if(t->right != NULL)
		postorder(t->right);
		
	printf("%d ",t->data);
}

void inordermodified(struct bst *t, int a[], int *n)
{
	int k=0;

	if(t->left != NULL)
		inordermodified(t->left,a,n);

	a[k++] = t->data;
	(*n)++;

	if(t->right != NULL)
		inordermodified(t->right,a,n);
}

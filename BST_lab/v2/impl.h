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

struct bst* Delete(struct bst *t,int x)
{
	struct bst *temp;
	
	if(x<t->data)
		t->left = Delete(t->left,x);
		
	else if(x>t->data)
		t->right = Delete(t->right,x);
		
	else if(t->left && t->right)
	{
		temp = findmin(t->right);
		t->data = temp->data;
		t->right = Delete(t->right,t->data);
	}
	
	else
	{
		temp = t;
		if(t->right == NULL)
			t = t->left;
			
		else if(t->left == NULL)
			t = t->right;
			
		free(temp);
		return t;
	}
	
	return t;
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

void printCurrentLevel(struct bst *t, int level)
{
    if (t == NULL)
        return;
        
    if (level == 1)
       printf("%d ",t->data);
       
    else if (level > 1) 
    {
        printCurrentLevel(t->left, level - 1);
        printCurrentLevel(t->right, level - 1);
    }
}
 
int height(struct bst *t)
{
    if (t == NULL)
        return 0;
        
    else 
    {
    	int lheight = height(t->left);
        int rheight = height(t->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

void levelorder(struct bst *t)
{
    int h = height(t);
    int i;
    for (i = 1; i <= h; i++)
    {
        printf("Level %d -> ",i);
        printCurrentLevel(t, i);
        printf("\n");
    }
}
 
void inordermodified(struct bst *t, int a[], int *n)
{

	if(t->left != NULL)
		inordermodified(t->left,a,n);

	a[(*n)++] = t->data;

	if(t->right != NULL)
		inordermodified(t->right,a,n);
}

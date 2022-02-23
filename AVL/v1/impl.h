#include<stdio.h>
#include "adt.h"
#include <stdlib.h>
int height(struct avl *t)
{
	if(t==NULL)
		return -1;
	else
		return t->h;
}

int max(int a, int b)
{
	if(a>b)
		return a;
	
	else
		return b;
}

struct avl* singlerotatewithleft(struct avl *k2)
{
	struct avl *k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->h = max(height(k2->left),height(k2->right))+1;
	k1->h = max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct avl* singlerotatewithright(struct avl *k2)
{
	struct avl *k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k2->h = max(height(k2->left),height(k2->right))+1;
	k1->h = max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct avl* doublerotatewithleft(struct avl *k3)
{ 
    //rotate between k1 and k2
	k3->left=singlerotatewithright(k3->left);

	//rotate between k3 and k2
	return singlerotatewithleft(k3);
}

struct avl* doublerotatewithright(struct avl *k3)
{ 
    //rotate between k1 and k2
	k3->right=singlerotatewithleft(k3->left);

	//rotate between k3 and k2
	return singlerotatewithright(k3);
}

struct avl* insert (struct avl *t, int x)
{
	if(t==NULL)
	{
		t=(struct avl*)malloc(sizeof(struct avl));
		t->data=x;		
		t->h=0;
		t->left=t->right=NULL;	
	}
	
	else if(x<t->data)
	{
		t->left=insert(t->left,x);
		if(height(t->left)-height(t->right) ==2)
		{
			if(x<t->left->data)
				t=singlerotatewithleft(t);
			else
				t=doublerotatewithleft(t);
		}
	}
	
	else if(x>t->data)
	{
		t->right=insert(t->right,x);
	    	if(height(t->left)-height(t->right) ==2)
	    	{
			if(x>t->right->data)
				t=singlerotatewithright(t);
			else
				t=doublerotatewithright(t);
		}
	}
	
	t->h = max(height(t->left),height(t->right))+1;
	return t;

}
void inorder(struct avl* t)
{
	if(t->left != NULL)
		inorder(t->left);
		
	printf("%d ",t->data);
	
	if(t->right != NULL)
		inorder(t->right);
}

void printCurrentLevel(struct avl *t, int level)
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

int height_print(struct avl *t)
{
    if (t == NULL)
        return 0;
        
    else 
    {
    	int lheight = height_print(t->left);
        int rheight = height_print(t->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

void display(struct avl *t)
{
    int h = height_print(t);
    int i;
    for (i = 1; i <= h; i++)
    {
        printf("Level %d -> ",i);
        printCurrentLevel(t, i);
        printf("\n");
    }
}

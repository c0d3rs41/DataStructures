#include <stdio.h>
#include "adt.h"
#include <stdlib.h>
#include <string.h>
int height(struct dictionaryADT *t)
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

struct dictionaryADT* singlerotatewithleft(struct dictionaryADT *k2)
{
	struct dictionaryADT *k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->h = max(height(k2->left),height(k2->right))+1;
	k1->h = max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct dictionaryADT* singlerotatewithright(struct dictionaryADT *k2)
{
	struct dictionaryADT *k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k2->h = max(height(k2->left),height(k2->right))+1;
	k1->h = max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct dictionaryADT* doublerotatewithleft(struct dictionaryADT *k3)
{ 
    //rotate between k1 and k2
	k3->left=singlerotatewithright(k3->left);

	//rotate between k3 and k2
	return singlerotatewithleft(k3);
}

struct dictionaryADT* doublerotatewithright(struct dictionaryADT *k3)
{ 
    //rotate between k1 and k2
	k3->right=singlerotatewithleft(k3->left);

	//rotate between k3 and k2
	return singlerotatewithright(k3);
}

struct dictionaryADT* insert(struct dictionaryADT *t, struct wordMeaning x)
{
	if(t==NULL)
	{
		t=(struct dictionaryADT*)malloc(sizeof(struct dictionaryADT));
		t->data=x;		
		t->h=0;
		t->left=t->right=NULL;	
	}
	
	else if(strcmp(x.word,t->data.word)<0)
	{
		t->left=insert(t->left,x);
		if(height(t->left)-height(t->right) ==2)
		{
			if(strcmp(x.word,t->left->data.word)<0)
				t=singlerotatewithleft(t);
			else
				t=doublerotatewithleft(t);
		}
	}
	
	else if(strcmp(x.word,t->data.word)>0)
	{
		t->right=insert(t->right,x);
	    	if(height(t->left)-height(t->right) ==2)
	    	{
			if(strcmp(x.word,t->data.word)>0)
				t=singlerotatewithright(t);
			else
				t=doublerotatewithright(t);
		}
	}
	
	t->h = max(height(t->left),height(t->right))+1;
	return t;

}

void disp(struct dictionaryADT *d)
{
	if(d->left != NULL)
		disp(d->left);
		
	printf("%s\t%s\n",d->data.word,d->data.meaning);
	
	if(d->right != NULL)
		disp(d->right);
}

char* search(struct dictionaryADT *d, char w[])
{
	if(d==NULL)
		return NULL;
		
	if(strcmp(d->data.word,w)==0)
		return d->data.meaning;
	
	else if(strcmp(w,d->data.word)<0)
		return search(d->left,w);
		
	else if(strcmp(w,d->data.word)>0)
		return search(d->right,w);
}

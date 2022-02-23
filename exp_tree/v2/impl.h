#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void initAddrStack(struct AddrStack *s,int limit)
{
	s->top = -1;
	s->size = limit;
}

void push(struct AddrStack *s, struct node *x)
{
	if(isFull(s))
		printf("\nOverflow.");
		
	else
	{
		s->top++;
		s->addr[s->top] = x;
	}
}

void pop(struct AddrStack *s)
{
	if(isEmpty(s))
		printf("\nUnderflow.");
		
	else
	{
		s->top--;
	}
}

void display(struct AddrStack *s)
{
	if(isEmpty(s))
		printf("\nUnderflow.");
		
	else
	{
		printf("\nElements are: ");
		for(int i = s->top; i>=0; i--)
			printf("%c ",s->addr[i]->c);
	}	
}

int isFull(struct AddrStack *s)
{
	if(s->top == s->size-1)
		return 1;
	else
		return 0;
}

int isEmpty(struct AddrStack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

struct node* top(struct AddrStack *s)
{
	if(isEmpty(s))
		return NULL;
		
	else
		return s->addr[s->top];
}

/*Node details*/
struct node* createNode(char ch)
{
	struct node *t;
	t = (struct node*)malloc(sizeof(struct node));
	t->c = ch;
	t->right = NULL;
	t->left = NULL;
}

void construct(struct ET *t, char *postfixexp)
{
	char *p = postfixexp;
	t->s = (struct AddrStack*)malloc(sizeof(struct AddrStack));
	
	while(*p != '\0')
	{
		if(isdigit(*p))		
			push(t->s,createNode(*p));

		else if(*p == '+' || *p == '*' || *p == '-' || *p == '/')
		{
			struct node *temp = createNode(*p);
			temp->right = top(t->s);
			pop(t->s);
			
			temp->left = top(t->s);
			pop(t->s);

			push(t->s,temp);
		}
		
		p++;
		
	}

	t->n = top(t->s);
}

void basicInorder(struct node *n)
{
	if(n->left!=NULL)
		basicInorder(n->left);

	printf("%c ",n->c);

	if(n->right!=NULL)
		basicInorder(n->right);
}

void basicPreorder(struct node *n)
{
	printf("%c ",n->c);
	
	if(n->left!=NULL)
		basicPreorder(n->left);


	if(n->right!=NULL)
		basicPreorder(n->right);
}

void basicPostorder(struct node *n)
{
	
	if(n->left!=NULL)
		basicPostorder(n->left);


	if(n->right!=NULL)
		basicPostorder(n->right);

	printf("%c ",n->c);
}

void inorder(struct ET *t)
{
	basicInorder(t->n);
}

void preorder(struct ET *t)
{
	basicPreorder(t->n);
}

void postorder(struct ET *t)
{
	basicPostorder(t->n);
}

#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

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

#include "adt.h"
#include <stdio.h>

void initStack(struct stack *s,int maxSize)
{
	s->top = -1;
	s->size = maxSize;
}

void push(struct stack *s, int x)
{
	if(isFull(s))
		printf("\nOverflow.");
		
	else
	{
		s->top++;
		s->data[s->top] = x;
	}
}

void pop(struct stack *s)
{
	if(isEmpty(s))
		printf("\nUnderflow.");
		
	else
	{
		//printf("\nPopped value = %d",s->data[s->top]);
		s->top--;
	}
}

int top(struct stack *s)
{
	if(isEmpty(s))
		return -1;
		
	else
		return s->data[s->top];
}

int isFull(struct stack *s)
{
	if(s->top == s->size-1)
		return 1;
	else
		return 0;
}

int isEmpty(struct stack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

void display(struct stack *s)
{
	if(isEmpty(s))
		printf("\nUnderflow.");
		
	else
	{
		printf("\nElements are: ");
		for(int i = s->top; i>=0; i--)
			printf("%d ",s->data[i]);
	}	
}

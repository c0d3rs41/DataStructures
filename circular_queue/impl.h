#include "adt.h"
#include <stdio.h>

void init(struct queue *q,int s)
{
	q->size = s;
	q->front = -1;
	q->rear = -1;
}

void enqueue(struct queue *q, int x)
{
	if(isFull(q))
		printf("\nQueue overflow.");
		
	else if(isEmpty(q))
	{
		q->front++;
		q->rear++;
		q->data[q->rear] = x;
	}
	
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->data[q->rear] = x;
	}	
}

int dequeue(struct queue *q)
{
	int temp;
	
	if(isEmpty(q))
	{
		return -1;
	}
	
	else if(q->front == q->rear)
	{
		temp = q->data[q->front];
		q->front = q->rear = -1;
		return temp;
	}
	
	else
	{
		temp = q->data[q->front];
		q->front = (q->front + 1) % q->size;
		return temp;
	}
}

void disp(struct queue *q)
{
	if(isEmpty(q))
		printf("\nQueue is empty.");

	else
	{
		printf("\nElements are: ");
		
		int i = q->front;
		while(i!=q->rear)
		{
			printf("%d ", q->data[i]);
			i = (i+1) % q->size;
		}
		
		printf("%d\n",q->data[i]);
	}
}

int isEmpty(struct queue *q)
{
	if(q->front == -1)
		return 1;
		
	else 
		return 0;
}

int isFull(struct queue *q)
{
	if((q->rear + 1) % q->size == q->front)
		return 1;
		
	else
		return 0;
}

#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

void create(struct cityADT *c)
{
	char edges[50][50];
	int v,e;
	
	printf("\nEnter the no of vertices: ");
	scanf("%d",&v);

	printf("\nEnter the no of edges: ");
	scanf("%d",&e);

	c->order = v;

	for(int i=0;i<e;i++)
	{
		printf("Enter edge %d: ",(i+1));
		scanf(" %s",edges[i]);
	}

	for(int i=0;i<e;i++)
	{
		for(int j=0;j<e;j++)
		{
			c->adj_mat[i][j] = 0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		c->adj_mat[(int)edges[i][0]-65][(int)edges[i][1]-65]= 1; 	
	} 
}

void disp(struct cityADT *c)
{
	printf("\n");

	for(int i=0;i<c->order;i++)
	{
		for(int j=0;j<c->order;j++)
		{
			printf("%d\t",c->adj_mat[i][j]);
		}
		printf("\n");
	}
}

int unvisited(int v[],int n)
{
	int flag = 0;
	
	for(int i=0;i<n;i++)
	{
		if(v[i] == 0)
		{
			flag =1;
			break;
		}
	}

	return flag;
}

void BFS(struct cityADT *c,char start)
{
	int x,y,z;
	int visited[50];
	
	//Setting the visited values as 0
	for(int i=0;i<c->order;i++)
		visited[i] = 0;
		
	struct queue *q;
	q = (struct queue*)malloc(sizeof(struct queue));
	init(q,50);
	
	x = (int)start - 65;
	while(unvisited(visited,c->order))
	{
		
		enqueue(q,x);
		visited[x] = 1;
		printf("%c ",(char)(x+65));
		
		while(!isEmpty(q))
		{
			z = dequeue(q);
			for(int i=0;i<c->order;i++)
			{
				if(c->adj_mat[z][i] == 1 && visited[i] == 0)
				{
					visited[i] = 1;
					printf("%c ",(char)(i+65));
					enqueue(q,i);
				}
			}
			
		}
		
		for(int i=0;i<c->order;i++)
		{
			if(visited[i]==0)
			{
				x=i;
				break;
			}
		}
		
	}
	
} 
void DFS(struct cityADT *c, char start) 
{
	struct stack *s;
	s = (struct stack*)malloc(sizeof(struct stack));
	initStack(s,50);
	
	int x,t;
	int visited [50];
	
	//Setting the visited values as 0
	for(int i=0;i<c->order;i++)
		visited[i] = 0;
	
	x = (int)start - 65;
	
	int flag;
	while(unvisited(visited,c->order))
	{
		visited[x] = 1;
		push(s,x);
		printf("%c ",(char)(x+65));
		
		while(!isEmptyStack(s))
		{
			flag = 0;
			t = top(s);
			
			for(int i=0;i<c->order;i++)
			{
				if(c->adj_mat[t][i] == 1 && visited[i] == 0)
				{
					visited[i] = 1;
					printf("%c ",(char)(i+65));
					push(s,i);
					flag = 1;
					break;
				}
			}

			if(flag == 0)
				pop(s);
			
		}
		
		for(int i=0;i<c->order;i++)
		{
			if(visited[i]==0)
			{
				x=i;
				break;
			}
		}	
	}
	
}

int check_path(struct cityADT *c, char start,char dest)
{
	struct stack *s;
	s = (struct stack*)malloc(sizeof(struct stack));
	initStack(s,50);
	
	int x,t;
	int visited [50];
	
	//Setting the visited values as 0
	for(int i=0;i<c->order;i++)
		visited[i] = 0;
	
	x = (int)start - 65;
	
	int flag;
	while(unvisited(visited,c->order))
	{
		visited[x] = 1;
		push(s,x);
		
		while(!isEmptyStack(s))
		{
			flag = 0;
			t = top(s);
			
			for(int i=0;i<c->order;i++)
			{
				if(c->adj_mat[t][i] == 1 && visited[i] == 0)
				{
					visited[i] = 1;
					//printf("%c ",(char)(i+65));
					push(s,i);
					if(i==(int)dest-65)
						return 1;
					flag = 1;
					break;
				}
			}

			if(flag == 0)
				pop(s);
			
		}
		return 0;
		for(int i=0;i<c->order;i++)
		{
			if(visited[i]==0)
			{
				x=i;
				break;
			}
		}	
	}
	
}

void connected_comp(struct cityADT *c)
{
	int x,y,z;
	int visited[50];
	
	//Setting the visited values as 0
	for(int i=0;i<c->order;i++)
		visited[i] = 0;
		
	struct queue *q;
	q = (struct queue*)malloc(sizeof(struct queue));
	init(q,50);
	
	
	while(unvisited(visited,c->order))
	{
		
		for(int i=0;i<c->order;i++)
		{
			if(visited[i]==0)
			{
				x=i;
				break;
			}
		}
		
		enqueue(q,x);
		visited[x] = 1;
		printf("%c ",(char)(x+65));
		
		while(!isEmpty(q))
		{
			z = dequeue(q);
			for(int i=0;i<c->order;i++)
			{
				if(c->adj_mat[z][i] == 1 && visited[i] == 0)
				{
					visited[i] = 1;
					printf("%c ",(char)(i+65));
					enqueue(q,i);
				}
			}
			
		}
		printf("\n");
		
	}
}

/*Functions for queue*/
void init(struct queue *q, int s)
{
	q->front = -1;
	q->rear = -1;
	q->size = s;
}
int isFull(struct queue *q)
{
	if(q->rear == q->size-1)
		return 1;
	else
		return 0;
}

int isEmpty(struct queue *q)
{
	if(q->front == -1)
		return 1;
		
	else
		return 0;
}

void enqueue(struct queue *q, int x)
{
	if(isFull(q))
		printf("\nQueue is full.");
		
	else if(q->rear == -1)
	{
		q->front = 0;
		q->rear = 0;
		q->data[q->rear] = x;
	}
	
	else
	{
		q->rear++;
		q->data[q->rear] = x;
	}
}

int dequeue(struct queue *q)
{
	int value;
	
	if(isEmpty(q))
		return -1;
		
	else if(q->front == q->rear)
	{
		value = q->data[q->front];
		q->front = -1;
		q->rear = -1;
	}
	
	else
	{
		value = q->data[q->front];
		q->front++;
	}
	
	return value;
}

/*Stack functions*/
void initStack(struct stack *s,int maxSize)
{
	s->top = -1;
	s->size = maxSize;
}

void push(struct stack *s, int x)
{
	if(isFullStack(s))
		printf("\nOverflow.");
		
	else
	{
		s->top++;
		s->data[s->top] = x;
	}
}

void pop(struct stack *s)
{
	if(isEmptyStack(s))
		printf("\nUnderflow.");
		
	else
	{
		//printf("\nPopped value = %d",s->data[s->top]);
		s->top--;
	}
}

int top(struct stack *s)
{
	if(isEmptyStack(s))
		return -1;
		
	else
		return s->data[s->top];
}

int isFullStack(struct stack *s)
{
	if(s->top == s->size-1)
		return 1;
	else
		return 0;
}

int isEmptyStack(struct stack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

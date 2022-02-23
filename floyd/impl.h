#include <stdio.h>
#include "adt.h"

void init(struct graph * g,int n)
{
	g->no=n;
	
	for(int i=1;i<=g->no;i++)	
	{
		for(int j=1;j<=g->no;j++)
		{
			g->P[i][j] = 0;
			if(i==j)
				g->D[i][j]=0;
			else
				g->D[i][j]=999;
		}
	}
}
void distanceMatrix(struct graph * g,int start,int end,int cost)
{
	g->D[start][end]=cost;
}

void FloydWarshall(struct graph *g)
{
	for(int k=1;k<=g->no;k++)
	{
		for(int i=1;i<=g->no;i++)
		{
			for(int j=1;j<=g->no;j++)
			{
				if(g->D[i][j]>g->D[i][k]+g->D[k][j])
				{
					g->D[i][j] = g->D[i][k]+g->D[k][j];
					g->P[i][j]=k;
				}
			}
		}
		
		Print(g);
	}
}

void printPath(struct graph * g,int source,int desti)
{
	if(g->P[source][desti]==0)
	{
		printf(" %d",desti);
	}
	
	else
	{
		printPath(g,source,g->P[source][desti]);
		printPath(g,g->P[source][desti],desti);
	}
}

void Print(struct graph * g)
{
	printf("\nDistance Matrix: \n");
	for(int i=1;i<=g->no;i++)
	{
		for(int j=1;j<=g->no;j++)
		{
			printf("%d\t",g->D[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPredecessor Matrix: \n");
	for(int i=1;i<=g->no;i++)
	{
		for(int j=1;j<=g->no;j++)
		{
			printf("%d\t",g->P[i][j]);
		}
		printf("\n");
	}
}

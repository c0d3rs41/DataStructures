#include <stdlib.h>
#include "impl.h"

void main()
{
	struct graph *g = (struct graph*)malloc(sizeof(struct graph));
	int n,e,start,end,cost;
	
	printf("\nEnter the no of vertices: ");;
	scanf("%d",&n);
	
	init(g,n);
	Print(g);
	
	printf("\nEnter the no of edges: ");;
	scanf("%d",&e);
	
	for(int i=1;i<=e;i++)
	{
		printf("Enter start end and cost: ");
		scanf("%d %d %d",&start,&end,&cost);
		distanceMatrix(g,start,end,cost);
	}
	
	FloydWarshall(g);
	printf("1");
	printPath(g,1,3);
}

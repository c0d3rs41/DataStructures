#include "impl.h"

void main()
{
	struct cityADT *c;
	c = (struct cityADT*)malloc(sizeof(struct cityADT));
	create(c);
	printf("\nAdjacency matrix: \n");
	disp(c);
	
	printf("\nBFS traversal:\n");
	BFS(c,'A');
	printf("\nDFS traversal:\n");
	DFS(c,'A');
	printf("\n");
}

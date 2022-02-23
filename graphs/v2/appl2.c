#include "impl.h"
#include <stdlib.h>

void main()
{
	struct cityADT *c=(struct cityADT*)malloc(sizeof(struct cityADT));
	create(c);
	printf("\nAdjacency matrix: \n");
	disp(c);
	
	printf("\nConnected components:\n");
	connected_comp(c);
}

#include "impl.h"
#include <stdlib.h>

void main()
{
	struct cityADT *c=(struct cityADT*)malloc(sizeof(struct cityADT));
	create(c);
	printf("\nAdjacency matrix: \n");
	disp(c);
	
	printf("\nChecking path for D and F: %d",check_path(c,'D','F'));
	printf("\nChecking path for F and B: %d",check_path(c,'F','B'));

}

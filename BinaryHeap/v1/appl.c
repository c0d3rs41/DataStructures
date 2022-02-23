#include "impl.h"
#include <stdlib.h>

void main()
{
	struct PQ *p = (struct PQ*) malloc(sizeof(struct PQ));
	
	init(p,20);
	
	insert(p,14);    
	insert(p,16);
	insert(p,22);    
	insert(p,11);
	insert(p,9);      
	insert(p,18);
	insert(p,10);    
	insert(p,7);
	insert(p,4);    
	insert(p,1);
	
	printf("\nElements: ");
	display(p);
	printf("\n");
	
}

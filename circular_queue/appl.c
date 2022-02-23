#include "impl.h"
#include <stdlib.h>

void main()
{
	struct queue *q = (struct queue *) malloc(sizeof(struct queue));
	init(q,3);
	
	
	enqueue(q,5);
	enqueue(q,6);
	enqueue(q,7);
	
	disp(q);
	printf("\n%d", dequeue(q));
	printf("\n%d", dequeue(q));
	printf("\n%d", dequeue(q));
	printf("\n%d", dequeue(q));
	disp(q);
	/*printf("\n%d", dequeue(q));*/
}

#include "impl.h"
#include <stdlib.h>

void main()
{
	struct HashTableADT *h = (struct HashTableADT *)malloc(sizeof(struct HashTableADT));
	
	init(h,10);
	insertElementL(h,23);
	insertElementL(h,45);
	insertElementL(h,69);
	insertElementL(h,87);
	insertElementL(h,48);
	insertElementL(h,67);
	insertElementL(h,54);
	insertElementL(h,66);
	insertElementL(h,53);
	
	displayHT(h);
	printf("\nSearch result for 67 = %d",searchElement(h,67));
	printf("\nSearch result for 53 = %d",searchElement(h,53));
	printf("\nSearch result for 10 = %d\n",searchElement(h,10));
}

#include "impl.h"
#include <stdlib.h>

void main()
{
	struct HashTableADT *h1 = (struct HashTableADT*)malloc(sizeof(struct HashTableADT));
	struct HashTableADT *h2 = (struct HashTableADT*)malloc(sizeof(struct HashTableADT));
	
	init(h1,10);
	init(h2,10);
	
	int lb,ub;
	
	insertElementQ(h1,23);
	insertElementQ(h1,45);
	insertElementQ(h1,69);
	insertElementQ(h1,87);
	insertElementQ(h1,48);
	insertElementQ(h1,67);
	insertElementQ(h1,54);
	insertElementQ(h1,66);
	insertElementQ(h1,53);
	
	insertElementD(h2,23);
	insertElementD(h2,45);
	insertElementD(h2,69);
	insertElementD(h2,87);
	insertElementD(h2,48);
	insertElementD(h2,67);
	insertElementD(h2,54);
	insertElementD(h2,66);
	insertElementD(h2,53);
	
	displayHT(h1);
	displayHT(h2);
	
	printf("\nEnter lower bound: ");
	scanf("%d",&lb);
	
	printf("\nEnter upper bound: ");
	scanf("%d",&ub);
	
	printf("\nElements in the given range are: \n");
	for(int i=lb;i<=ub;i++)
	{
		if(searchElement(h1,i)==1)
			printf("%d found\n",i);
			
	}
}

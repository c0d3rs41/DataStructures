#include "impl.h"
#include <stdlib.h>

void main()
{
	struct HashTableADT *h = (struct HashTableADT *)malloc(sizeof(struct HashTableADT));
	
	int n,choice,element,key;
	char option;
	
	printf("\nEnter the size of the hashtable: ");
	scanf("%d",&n);
	
	init(h,n);
	
	do
	{
		printf("\n1)Insert an element.");
		printf("\n2)Search for an element.");
		printf("\n3)Display hash table.");
		printf("\n4)Exit program.");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\nEnter the element: ");
				scanf("%d",&element);
				insertElementL(h,element);
				printf("\nElement inserted successfully.");
				break;
				
			case 2: printf("\nEnter the key to be searched: ");
				scanf("%d",&key);
				if(searchElement(h,key)==-1)
					printf("\nElement not found.");
					
				else
					printf("\nElement found.");
				break;
				
			case 3: displayHT(h);
				break;
				
			case 4: exit(0);
			default: printf("\nWrong choice. Try again.");
		}
		
		printf("\nDo you want to continue?(Enter Y/y): ");
		scanf(" %c",&option);
		
	}while(option == 'y'||option == 'Y');	
}

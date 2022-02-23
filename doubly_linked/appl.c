#include "impl.h"

void main()
{
	struct listADT *l;
	
	char option;
	int choice;
	int k;
	
	struct listADT *ptr;
	
	struct listADT *temp;
	
	/*To store consonants*/
	struct listADT *c;
	c = (struct listADT *)malloc(sizeof(struct listADT));
	init(c);
	
	/*To store vowels*/
	struct listADT *v;
	v = (struct listADT *)malloc(sizeof(struct listADT));
	init(v);
	
	do
	{
		l = (struct listADT *)malloc(sizeof(struct listADT));
		init(l);
		input(l); //Taking input for l
		
		printf("\n1) Check whether the list is palindrome or not.");
		printf("\n2) Create separate lists containing vowels and consonants from the list.");
		printf("\n3) Swap kth node from the beginning with kth node from the end.");	
		printf("\n4) Number of times a letter occurrs in a list.");	
		printf("\n5) Insert a character in the middle.");
		printf("\n6) Delete a character.");
		printf("\n7) Exit.");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: ptr = l->next;
				temp = (struct listADT *)malloc(sizeof(struct listADT));
				init(temp);
				
				while(ptr!=NULL)
				{
					insertFront(temp,ptr->item);
					ptr = ptr->next;
				}
				
				if(listCompare(temp,l)==0)
				{
					printf("\n\n");
					displayItems(l);
					printf(" is a palindrome.");
				}
					
				else
				{
					printf("\n");
					displayItems(l);
					printf(" is NOT a palindrome.");
				}
				break;
				
			case 2: ptr = l->next;
				while(ptr!=NULL)
				{
					if(ptr->item == 'A' || ptr->item == 'E' || ptr->item == 'I' || ptr->item == 'O' || ptr->item == 'U' )
						insertEnd(v,ptr->item);
						
					else
						insertEnd(c,ptr->item);
						
					ptr = ptr->next;
				}
				
				printf("\nVowels: ");
				displayItems(v);
				
				printf("\nConsonants: ");
				displayItems(c);
				break;
				
			case 3: printf("\nEnter the value of k: ");
				scanf("%d",&k);
				
				int counter = 1;
				struct listADT *pstart, *pend;
				
				pend = l->next;
				pstart = l->next;
				
				while(pend->next!=NULL)
					pend = pend->next;
					
				while(counter != k)
				{
					pstart = pstart->next;
					pend = pend->prev;
					counter++;
				}
				
				char temp = pstart->item;
				pstart->item = pend->item;
				pend->item = temp;
				
				printf("\nList after swapping is ");
				displayItems(l);
				break;
				
			case 4: printf("\nEnter the character: ");
				char item;
				
				scanf(" %c",&item);
				printf("\nNo of occurences = %d",searchItem(l,item));
				break;
				
			case 5: printf("\nEnter the character after which a character has to be inserted: ");
				scanf(" %c",&item);
				
				printf("\nEnter the character to be inserted: ");
				char t;
				
				scanf(" %c",&t);
				
				insertMiddle(l,item,t);
				printf("\nNew list = ");
				displayItems(l);
				break;
				
			case 6: printf("\nEnter the character to be deleted: ");
				scanf(" %c",&item);
				
				deleteItem(l,item);
				printf("\nNew list = ");
				displayItems(l);
				break;
				
			case 7: exit(0);
				
			default: printf("\nWrong choice. Try again.");
		}
		
		printf("\nDo you want to continue?(y/n): ");
		scanf(" %c",&option);
	}while(option == 'y');
	
}

#include "impl.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int choice;
	int poly_option;
	int x;
	
	char option;
	
	struct polyADT *p1 = NULL;
	struct polyADT *p2 = NULL;
	struct polyADT *p = NULL;
	
	printf("\nEnter polynomial 1: ");
	p1 = polyInp(p1);
	
	printf("\nEnter polynomial 2: ");
	p2 = polyInp(p2);
	
	do
	{
		printf("\nMAIN MENU");
		printf("\n1)Add two polynomials. ");
		printf("\n2)Multiply two polynomials. ");
		printf("\n3)Print the degree of the polynomials. ");
		printf("\n4)Evaluate a polynomial. ");
		printf("\n5)Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: p = polyAdd(p1,p2);
				printf ("\nAddition result: ");
				display(p);
				break;
				
			case 2: p = polyMul(p1,p2);
				p = polySimplify(p); //Using polySimplify() to simplify the multiplication result
				
				/*polyMul returns NULL if the result is 0. We need to check for that.*/
				if(p == NULL)
					printf("\nMultiplication result = 0");
					
				else
				{
					printf ("\nMultiplication result: ");
					display(p);
				}
				
				break;
				
			case 3: printf("\nDegree of poly1 = %d",polyDegree(p1));
				printf("\nDegree of poly2 = %d",polyDegree(p2));
				break;
				
			case 4: printf("\nEnter the polynomial to be evaluated (1/2): ");
				scanf("%d",&poly_option);
				
				printf("\nEnter the value of x: ");
				scanf("%d",&x);
				
				if(poly_option == 1)
					printf("\nValue of poly 1 at x = %d is %d",x,polyEvaluate(p1,x));
				
				
				else if(poly_option == 2)
					printf("\nValue of poly 2 at x = %d is %d",x,polyEvaluate(p2,x));
				
				else
				{
					printf("\nERROR: Wrong choice. Try again.");
					continue;
				}
				
				break;
				
			case 5: exit(0);
			
			default: printf("\nERROR. Wrong choice. Try again.");
				
		}
		
		printf("\nDo you want to continue? (y/n): ");
		scanf(" %c",&option);
		
	}while(option == 'y');
}

/*Program to implement and play the game twoStacks.

Written by: Sai Shashaank R.
Date: 17/10/2021

*/

#include <stdlib.h>
#include "impl.h"

void playGame(struct stack *a,struct stack *b,int maxSum)
{
	int score = 0;
	int currSum = 0;
	char choice;
	
	while((currSum < maxSum) && !isEmpty(a) && !isEmpty(b))
	{
		printf("\nWhich stack do you want to pop?Enter a/b: ");
		scanf(" %c",&choice);
		
		if(choice == 'a')
		{
			if(currSum + top(a)>maxSum)
				break;
				
			currSum += top(a);
			pop(a);
			score++;
		}
		
		else if(choice == 'b')
		{
			if(currSum + top(b)>maxSum)
				break;
				
			currSum += top(b);
			pop(b);
			score++;
		}
		
		else
			printf("\nWrong choice. Try again.");
	}
	
	printf("\nYour score is %d.\n",score);
}

void main()
{
	int sizeA,sizeB,element,maxSum;;
	
	struct stack *a = (struct stack*)malloc(sizeof(struct stack));
	struct stack *b = (struct stack*)malloc(sizeof(struct stack));
	
	printf("\nEnter the size of stack A: ");
	scanf("%d",&sizeA);
	
	printf("\nEnter the size of stack B: ");
	scanf("%d",&sizeB);
	
	/*Initialising the stacks*/
	initStack(a,sizeA);
	initStack(b,sizeB);
	
	/*Filling the stacks with values*/
	printf("\nEnter the elements of stack A.");
	for(int i=1;i<=sizeA;i++)
	{
		printf("\nEnter the element: ");
		scanf("%d",&element);
		push(a,element);
	}
	
	printf("\nEnter the elements of stack B.");
	for(int i=1;i<=sizeB;i++)
	{
		printf("\nEnter the element: ");
		scanf("%d",&element);
		push(b,element);
	}
	
	printf("\nEnter the max sum for the game: ");
	scanf("%d",&maxSum);
	
	playGame(a,b,maxSum);
}

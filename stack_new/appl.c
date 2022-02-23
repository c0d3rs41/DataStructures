/*Program to ensure check if the StackAdt is functioning correctly.

Written by: Sai Shashaank R.
Date: 17/10/2021

*/

#include "impl.h"
#include<stdlib.h>

void main()
{
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	initStack(s,3); 
	push(s,1);
	push(s,2); 
	push(s,3); 
	push(s,4); 
	
	printf("\nTop value = %d",top(s)); 
	pop(s); 
	
	printf("\nTop value = %d",top(s)); 
	pop(s); 
	
	printf("\nTop value = %d",top(s)); 
	pop(s); 
	
	printf("\nTop value = %d\n",top(s)); 
}

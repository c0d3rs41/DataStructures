/*Application to evaluate postfix expression using expression tree

Written by: Sai Shashaank R
Date: 29/11/21

*/

#include "impl.h"

void main()
{
	struct ET *t = (struct ET*)malloc(sizeof(struct ET));
	
	char postfix[50];
	printf("\nEnter a postfix expression: ");
	scanf(" %s",postfix);
	
	construct(t,postfix);
	printf("\nAnswer = %d\n",eval(t->n));
}

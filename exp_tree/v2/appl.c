#include "impl.h"

void main()
{
	char post[] = "45*6+";
	
	struct ET *t = (struct ET*)malloc(sizeof(struct ET));
	 
	construct(t,&post[0]);
	
	
	printf("Inorder: ");
	inorder(t);

	printf("\nPreorder: ");
	preorder(t);

	printf("\nPostorder: ");
	postorder(t);
	printf("\n");
}

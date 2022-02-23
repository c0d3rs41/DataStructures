#include "impl.h"

void main()
{
	struct bst *t = NULL;
	
	t = insert(t,29);
	t = insert(t,23);
	t = insert(t,4);
	t = insert(t,13);
	t = insert(t,39);
	t = insert(t,31);
	t = insert(t,45);
	t = insert(t,56);
	t = insert(t,49);
	
	printf("\nInorder display:\n");
	inorder(t);
	printf("\n\nLevel order display:\n");
	levelorder(t);
	printf("\n\nMinimum value = %d",findmin(t)->data);
	
	printf("\n\nSearch result for 13 = %s",find(t,13) == NULL?"not found":"found");
	printf("\n\nSearch result for 3 = %s\n",find(t,3) == NULL?"not found":"found");
}

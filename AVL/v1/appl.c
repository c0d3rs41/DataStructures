#include <stdio.h>
#include "impl.h"

void main()
{
	struct avl *t = NULL;
	
	t = insert(t,23); 
	t = insert(t,12);
	t = insert(t,13);
	t = insert(t,4);
	t = insert(t,45);
	t = insert(t,54);

	printf("\nInorder: ");
	inorder(t);
	printf("\n\nHierarchical display of elements:\n");
	display(t);
}

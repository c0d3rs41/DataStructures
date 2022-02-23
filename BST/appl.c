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
	
	//inorder(t);
	normal_display(t,0);
}

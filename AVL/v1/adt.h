struct avl
{
	int data;
	struct avl *left, *right;
	int h;
};

struct avl* insert(struct avl *t, int x);
void inorder(struct avl* t);
void display(struct avl *t);


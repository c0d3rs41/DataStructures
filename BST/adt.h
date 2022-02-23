struct bst
{
	int data;
	struct bst *left,*right;
};

struct bst* insert(struct bst *t, int c); 
void normal_display(struct bst *t, int depth); //displays the tree in an indented fashion
struct bst* find(struct bst* t, int item);
struct bst* findmin(struct bst *t);
void inorder(struct bst *t);
void preorder(struct bst *t);
void inordermodified(struct bst *t, int a[], int *n);

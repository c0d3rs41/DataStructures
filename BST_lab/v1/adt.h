struct bst
{
	int data;
	struct bst *left,*right;
};

struct bst* insert(struct bst *t, int c); 
struct bst* Delete(struct bst *t,int x);
void inorder(struct bst *t);
void levelorder(struct bst *t);
struct bst* find(struct bst* t, int item);
struct bst* findmin(struct bst *t);

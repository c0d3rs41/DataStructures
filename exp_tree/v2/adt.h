struct AddrStack
{
	struct node* addr[50];
	int top;
	int size;
};

void initAddrStack(struct AddrStack *s,int limit);
void push(struct AddrStack *s, struct node *x);
void pop(struct AddrStack *s);
void display(struct AddrStack *s);

int isFull(struct AddrStack *s);
int isEmpty(struct AddrStack *s);
struct node* top(struct AddrStack *s);


/*Node details*/
struct node
{
	char c;
	struct node *left,*right;
	
};

struct node* createNode(char c);

struct ET
{
	struct AddrStack *s;
	struct node *n;
};
void construct(struct ET *t, char *postfixexp);
void inorder(struct ET *t);
void preorder(struct ET *t);
void postorder(struct ET *t);


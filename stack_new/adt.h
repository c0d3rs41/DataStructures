
struct stack
{
	int data[10];
	int top;
	int size;
};

void initStack(struct stack *s,int maxSize);
void push(struct stack *s, int x);
void pop(struct stack *s);
void display(struct stack *s);

int isFull(struct stack *s);
int isEmpty(struct stack *s);
int top(struct stack *s);


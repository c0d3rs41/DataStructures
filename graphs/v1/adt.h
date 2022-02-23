struct cityADT
{
	int adj_mat[50][50];
	int order;
};

struct queue
{
	int data[100];
	int front,rear;
	int size;
};

struct stack
{
	int data[100];
	int top;
	int size;
};

void create(struct cityADT *c);
void disp(struct cityADT *c);
void BFS(struct cityADT *c,char start); 
void DFS(struct cityADT *c,char start); 

/*queue function prototypes*/
void init(struct queue *q, int s);
int isFull(struct queue *q);
int isEmpty(struct queue *q);
void enqueue(struct queue *q, int x);
int dequeue(struct queue *q);

/*stack function prototypes*/
void initStack(struct stack *s,int maxSize);
void push(struct stack *s, int x);
void pop(struct stack *s);
int isFullStack(struct stack *s);
int isEmptyStack(struct stack *s);
int top(struct stack *s);

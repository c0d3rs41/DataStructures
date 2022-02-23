struct queue
{
	int data[100];
	int size;
	int front,rear;
};

void init(struct queue *q,int s);
void enqueue(struct queue *q, int x);
int dequeue(struct queue *q);
void disp(struct queue *q);
int isEmpty(struct queue *q);
int isFull(struct queue *q);

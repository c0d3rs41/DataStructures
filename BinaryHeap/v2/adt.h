struct emp
{
	char id;
	int amount;
};

struct PQ
{
	struct emp elt[100];
	int size;
	int ctptr;
};

void init(struct PQ *p, int s);
void insert(struct PQ *p, struct emp e);
void display(struct PQ *p);
struct emp mindelete(struct PQ *p);

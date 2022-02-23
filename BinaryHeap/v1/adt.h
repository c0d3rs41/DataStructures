struct PQ
{
	int elt[100];
	int size;
	int ctptr;
};

void init(struct PQ *p, int s);
void insert(struct PQ *p, int d);
void display(struct PQ *p);
int mindelete(struct PQ *p);

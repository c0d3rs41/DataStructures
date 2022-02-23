struct graph
{
	int D[50][50];
	int P[50][50];
	int no;
};

void init(struct graph * g,int n);
void distanceMatrix(struct graph * g,int start,int end,int cost);
void FloydWarshall(struct graph *g);
void printPath(struct graph * g,int source,int desti);
void Print(struct graph * g);

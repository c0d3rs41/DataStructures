struct HashTableADT
{
	int hashtable[50];
	int size;
};

void init(struct HashTableADT *h, int s);
void insertElementL(struct HashTableADT *h,int x);
int searchElement(struct HashTableADT *h, int key);
void displayHT(struct HashTableADT *h);

struct HashTableADT
{
	int hashtable[50];
	int size;
};

void init(struct HashTableADT *h, int s);
void insertElementQ(struct HashTableADT *h,int x); //To insert element using quad probing
void insertElementD(struct HashTableADT *h,int x); //To insert element using double hashing
int searchElement(struct HashTableADT *h, int key);
void displayHT(struct HashTableADT *h);

struct listADT
{
	char item;
	struct listADT *next;
	struct listADT *prev;
};

void insertFront(struct listADT *l, char c);
void insertEnd(struct listADT *l, char c);
void insertMiddle(struct listADT *l,char c,char d);
void displayItems(struct listADT *l);
void deleteItem(struct listADT *l,char c);
int searchItem(struct listADT *l,char c);

/*-----Extra functions----------*/
void init (struct listADT *l); //To initialise the header of a list
int listCompare(struct listADT *l1,struct listADT *l2); //To compare two doubly linked lists
void input(struct listADT *l); //To take input for the doubly linked list


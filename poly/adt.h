struct polyADT
{
	int coeff;
	int exp;
	struct polyADT *next;
};

struct polyADT* insertEnd(struct polyADT *p, int coeff, int exp); //To create polynomial through insertion at the end
struct polyADT* polyAdd(struct polyADT *p1, struct polyADT *p2); //To add two polynomials and return the pointer to the resulting polynomial
struct polyADT* polyMul(struct polyADT *p1, struct polyADT *p2); //To multiply two polynomials and return the pointer to the resulting polynomial
struct polyADT* polySimplify(struct polyADT *p); //To simplify a polynomial
int polyEvaluate(struct polyADT *p, int x); //To evaluate a polynomial
int polyDegree(struct polyADT *p); //To find the degree of a polynomial

void display(struct polyADT *p); //To display a listADT implementation of polynomial
int isZero(struct polyADT *p); //To check if a polynomial is zero
int item_in(int arr[],int size,int item); //To check if an item exists in an array; used in polySimplify()
struct polyADT* polyInp(struct polyADT *p); //To take input for a polynomial

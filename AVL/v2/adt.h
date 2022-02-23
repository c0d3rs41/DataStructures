struct wordMeaning
{
	char word[50];
	char meaning[50];
};

struct dictionaryADT
{
	struct wordMeaning data;
	struct dictionaryADT *left, *right;
	int h;
};

struct dictionaryADT* insert(struct dictionaryADT *d, struct wordMeaning x);
void disp(struct dictionaryADT *d);
char* search(struct dictionaryADT *d, char word[]);


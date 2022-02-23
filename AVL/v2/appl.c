#include <stdio.h>
#include "impl.h"

void main()
{
	struct wordMeaning w;
	struct dictionaryADT *d;
	
	strcpy(w.word,"bisk");
	strcpy(w.meaning , "soup");
	d = insert(d,w);
	
	strcpy(w.word,"cite");
	strcpy(w.meaning,"refer");
	d = insert(d,w);
	
	strcpy(w.word,"boom");
	strcpy(w.meaning,"sound");
	d = insert(d,w);
	
	strcpy(w.word,"able");
	strcpy(w.meaning,"opportunity");
	d = insert(d,w);
	
	strcpy(w.word,"aged");
	strcpy(w.meaning,"old");
	d = insert(d,w);

	strcpy(w.word,"crew");
	strcpy(w.meaning,"group of people");
	d = insert(d,w);
	
	printf("\nContents of dictionary listed in ascending order: \n");
	disp(d);
	
	printf("\nMeaning of cite = %s\n\n",search(d,"cite"));
}

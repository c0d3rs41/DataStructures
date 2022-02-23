#include "impl.h"
#include <stdlib.h>

void main()
{
	struct PQ *p = (struct PQ*) malloc(sizeof(struct PQ));
	
	init(p,20);
	
	struct emp e; 
	
	e.id = 'A';
	e.amount = 15000;
	insert(p,e);    
	
	e.id = 'K';
	e.amount = 12000;
	insert(p,e);    
	
	e.id = 'R';
	e.amount = 4000;
	insert(p,e);   
	
	e.id = 'T';
	e.amount = 3500;
	insert(p,e);    
	
	e.id = 'L';
	e.amount = 4600;
	insert(p,e);    
	
	e.id = 'P';
	e.amount = 6000;
	insert(p,e);    
	
	e.id = 'Y';
	e.amount = 8600;
	insert(p,e);    
	 
	struct emp rm = mindelete(p);
	printf("\nRemoved elt = %c %d\n",rm.id,rm.amount);
	
	rm = mindelete(p);
	printf("\nRemoved elt = %c %d\n",rm.id,rm.amount);
	
	rm = mindelete(p);
	printf("\nRemoved elt = %c %d\n",rm.id,rm.amount);
	
	rm = mindelete(p);
	printf("\nRemoved elt = %c %d\n",rm.id,rm.amount);
	
	rm = mindelete(p);
	printf("\nRemoved elt = %c %d\n",rm.id,rm.amount);
	
	rm = mindelete(p);
	printf("\nRemoved elt = %c %d\n",rm.id,rm.amount);
	
	rm = mindelete(p);
	printf("\nRemoved elt = %c %d\n",rm.id,rm.amount);
}

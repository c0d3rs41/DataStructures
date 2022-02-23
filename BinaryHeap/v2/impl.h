#include "adt.h"
#include <stdio.h>

void init(struct PQ *p, int s)
{
	p->size = s;
	p->ctptr = 0;
	p->elt[p->ctptr].amount = -10;
}

void insert(struct PQ *p, struct emp e)
{
	p->ctptr++;
	p->elt[p->ctptr] = e;
	
	for(int i = p->ctptr ; p->elt[i/2].amount>e.amount ; i=i/2)
	{
		p->elt[i] = p->elt[i/2];
		p->elt[i/2] = e;
	}
}

void display(struct PQ *p)
{
	for(int i=0; i<=p->ctptr; i++)
		printf("%c %d\n",p->elt[i].id,p->elt[i].amount);
}

struct emp mindelete(struct PQ *p)
{
	struct emp min = p->elt[1];
	p->elt[1] = p->elt[p->ctptr];
	p->ctptr--;
	int child;
	
	for(int i=1; 2*i<=p->ctptr; i=child)
	{
		child = 2*i;
		
		if(p->elt[child].amount< p->elt[i].amount || p->elt[child+1].amount<p->elt[i].amount)
		{
			if(p->elt[child+1].amount< p->elt[child].amount)
				child++;
				
			struct emp t = p->elt[i];
			p->elt[i] = p->elt[child];
			p->elt[child] = t;
			
		}
	}
	
	return min;
}

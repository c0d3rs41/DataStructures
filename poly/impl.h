#include "adt.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct polyADT* insertEnd(struct polyADT *p, int c, int e)
{	
	struct polyADT *temp;
	temp = (struct polyADT *) malloc(sizeof(struct polyADT));
	temp->coeff = c;
	temp->exp = e;
	temp->next = NULL;
	
	if(p==NULL)
	{	
		p=temp;
	}
	else
	{		
		struct polyADT *i = p;
		while(i->next!=NULL)
			i=i->next;
		i->next = temp;
	}
	return p;
	
}

struct polyADT* polyAdd(struct polyADT *p1, struct polyADT *p2)
{
	if(isZero(p1))
		return p2;

	else if(isZero(p2))
		return p1;

	struct polyADT *p = NULL;

	while(p1!=NULL && p2!=NULL)
	{		
		if((p1->exp) > (p2->exp))
		{
			p = insertEnd(p,p1->coeff,p1->exp);
			p1=p1->next;
		}

		else if((p1->exp) == (p2->exp))
		{			
			p = insertEnd(p,(p1->coeff + p2->coeff),p1->exp);
			p1 = p1->next;
			p2 = p2->next;
		}

		else if((p1->exp) < (p2->exp))
		{			
			p = insertEnd(p,p2->coeff,p2->exp);
			p2=p2->next;
		}
	}

	if(p1 == NULL)
	{
		while(p2!=NULL)
		{
			p = insertEnd(p,p2->coeff,p2->exp);
			p2 = p2->next;
		}
	}

	if(p2==NULL)
	{
		while(p1!=NULL)
		{
			p = insertEnd(p,p1->coeff,p1->exp);
			p1 = p1->next;
		}
	}
	return p;
}

struct polyADT* polyMul(struct polyADT *p1, struct polyADT *p2)
{
	if(isZero(p1)||isZero(p2))
		return NULL;
	
	struct polyADT *p = NULL,*t;
	
	while(p1!=NULL)
	{
		t = p2;
		while(t!=NULL)
		{
			p = insertEnd(p,(p1->coeff * t->coeff),(p1->exp + t->exp));
			t = t->next;
		}
		
		p1=p1->next;
	}
	
	return p;
}

struct polyADT* polySimplify(struct polyADT *p)
{
	struct polyADT *temp;
	struct polyADT *p1 = NULL;
	
	int c[50];
	int e[50];
	
	int k=0;
	int result;
	
	while(p!=NULL)
	{
		result = 0;
		if(!item_in(e,k,p->exp))
		{
			result += p->coeff;
			temp = p->next;
			
			while(temp!=NULL)
			{
				if(temp->exp == p->exp)
					result += temp->coeff;
				temp = temp -> next;
			}
			
			e[k] = p->exp;
			c[k++] = result;
		}
		
		p = p->next;
	}
	
	for(int i=0; i<k ; i++)
	{
		p1 = insertEnd(p1,c[i],e[i]);
	}
	
	return p1;
}

int polyEvaluate(struct polyADT *p, int x)
{
	int result=0;
	while(p!=NULL)
	{
		result += p->coeff * (int)pow(x,p->exp);
		p = p->next;
	}
	
	return result;
}

int polyDegree(struct polyADT *p)
{
	int largest = p->exp;
	while(p!=NULL)
	{
		if(largest < p->exp)
			largest = p->exp;
		p = p->next;
	}
	
	return largest;
}

int item_in(int arr[],int size,int item)
{
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i] == item)
		{
			flag = 1;
			break;
		}
	}
	
	return flag;	
}

int isZero(struct polyADT *p)
{
	int flag=1;
	struct polyADT *i = p;
	while(i!=NULL)
	{
		if(i->coeff !=0)
		{
			flag = 0;
			break;
		}
		
		i = i->next;
	}

	return flag;
}

struct polyADT* polyInp(struct polyADT *p)
{
	char choice;
	int term =1;
	int c,e;
	do
	{
		printf("\nEnter coeff and exp for term %d: ",term++);
		scanf("%d %d",&c,&e);
		p = insertEnd(p,c,e);
		
		printf("\nDo you want to add another term?(y/n): ");
		scanf(" %c",&choice);
		
	}while(choice == 'y');
	
	return p;
}

void display(struct polyADT *p)
{
	struct polyADT *ptr = p;
	while(ptr!=NULL)
	{
		printf("%dx^%d + ",ptr->coeff,ptr->exp);
		ptr=ptr->next;
		
	}
	printf("\b\b");		
}

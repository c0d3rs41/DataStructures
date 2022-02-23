#include "adt.h"
#include <stdio.h>
#include <math.h>

void init(struct HashTableADT *h, int s)
{
	h->size=s;
	for(int i=0;i<h->size;i++)
		h->hashtable[i]=-1;
}

void insertElementQ(struct HashTableADT *h,int x)
{
	int location;
	location=x%h->size;
	int i=1;
	int start=location;
	
	while(h->hashtable[location]!=-1)
	{
		location = (start+(int)pow(i,2))%h->size;
		i++;
	}
	
	h->hashtable[location]=x;
}

void insertElementD(struct HashTableADT *h,int x)
{
	int location;
	location=x%h->size;
	int i=1;
	
	while(h->hashtable[location]!=-1)
	{
		location = (location+7-(x%7))%h->size;
	}
	
	h->hashtable[location]=x;
}

int searchElement(struct HashTableADT *h, int key)
{
	int location,start;
	location = key%h->size;
	
	if(h->hashtable[location]==key)
		return 1;
		
	else
	{
		start = location;
		location = (location+1)%h->size;
		
		while(location != start)
		{
			if(h->hashtable[location]==key)
				return 1;
				
			else
				location = (location+1)%h->size;
		}
	}
	
	return -1;
}

void displayHT(struct HashTableADT *h)
{
	printf("\nElements present in hash table are: ");
	
	for(int i=0;i<h->size;i++)
		printf("%d ",h->hashtable[i]);
	printf("\n");
}

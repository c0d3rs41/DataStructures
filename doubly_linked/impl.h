#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

void init(struct listADT *l)
{
	l->next = NULL;
	l->prev = NULL;
}

void insertFront(struct listADT *l,char c)
{
	struct listADT *temp = (struct listADT *) malloc(sizeof(struct listADT));
	temp->item = c;
	temp->next = l->next;
	
	if(l->next != NULL)
		l->next->prev = temp;
		
	l->next = temp;
	temp->prev = l;
}

void insertEnd(struct listADT *l, char c)
{
	struct listADT *temp = (struct listADT *) malloc(sizeof(struct listADT));
	
	temp->item = c;
	temp->next = NULL;
	
	if(l->next == NULL)
	{
		l->next = temp;
		temp->prev = l;
	}
	
	else
	{
		struct listADT *ptr = l;
		while(ptr->next!=NULL)
			ptr = ptr->next;
			
		ptr->next = temp;
		temp->prev = ptr;
	}
}

void insertMiddle(struct listADT *l,char c,char d)
{
	int flag = 0;
	struct listADT *ptr = l->next;
	
	while(ptr!=NULL)
	{
		if(ptr->item == c)
		{
			flag = 1;
			break;
		}
		
		ptr = ptr->next;
	}
	
	if(flag == 1)
	{
		struct listADT *temp = (struct listADT *) malloc(sizeof(struct listADT));
		temp->item = d;
		temp ->next = ptr->next;
		
		if(ptr->next != NULL)
			ptr->next->prev = temp;
			
		ptr->next = temp;
		temp->prev = ptr;
		printf("\nElement has been inserted.");
	}
	
	else
		printf("\nERROR: Element not found.");
}

void displayItems(struct listADT *l)
{
	if(l->next == NULL)
		printf("\nList is empty.");
	
	else
	{
		struct listADT *ptr = l->next;
		while(ptr!=NULL)
		{
			printf("%c",ptr->item);
			ptr=ptr->next;
		}
	}
}

void deleteItem(struct listADT *l,char c)
{
	int flag = 0;
	struct listADT *ptr = l->next;
	
	while(ptr!=NULL)
	{
		if(ptr->item == c)
		{
			flag = 1;
			break;
		}
		
		ptr = ptr->next;
	}
	
	if(flag == 1)
	{
		ptr->prev->next = ptr->next;
		if(ptr->next != NULL)
			ptr->next->prev = ptr->prev;
			
		printf("%c has been deleted successfully!",ptr->item);
		free(ptr);
	}
	
	else
		printf("\nItem wasn't found.");
}

int searchItem(struct listADT *l,char c)
{
	int counter = 0;
	struct listADT *ptr = l->next;
	
	while(ptr!=NULL)
	{
		if(ptr->item == c)
			counter++;
			
		ptr = ptr->next;
	}
	
	return counter;
}

int listCompare(struct listADT *l1,struct listADT *l2)
{
	int flag = 0;
	
	struct listADT *p1 = l1->next;
	struct listADT *p2 = l2->next;
	
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->item != p2->item)
		{
			flag = 1;
			break;
		}
		
		p1 = p1->next;
		p2 = p2->next;
	}
	
	if(p1 != NULL)
		flag = 1;
		
	else if(p2 != NULL)
		flag = 1;
		
	return flag;
}

void input(struct listADT *l)
{
	char str[50];
	printf("\nEnter the string: ");
	scanf(" %s",str);
	for(int i=0; str[i]!='\0'; i++)
	{
		insertEnd(l,str[i]);
	}
}

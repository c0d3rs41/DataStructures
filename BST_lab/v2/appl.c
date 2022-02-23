#include "impl.h"

int count(struct bst *t)
{
	int *a=malloc(sizeof(int));
	*a=0;
	int A[50];
	int d=0;
	inordermodified(t,A,a);
	
	for(int i=0;i<*a;i++)
	{
		d++;
	}
	
	return d;
}
int isComplete(struct bst *t,int index,int ct)
{
	if(t==NULL)
     		return 1;
     
   	else if(index>ct)
     		return 0;
     		
   	return(isComplete(t->left,2*index+1,ct)&&isComplete(t->right,2*index+2,ct));     
}
void main()
{
	struct bst *t1 = NULL;
	struct bst *t2 = NULL;
	
	t1 = insert(t1,10);
	t1 = insert(t1,5);
	t1 = insert(t1,50);
	t1 = insert(t1,1);
	t1 = insert(t1,40);
	t1 = insert(t1,100);
	
	t2 = insert(t2,10);
	t2 = insert(t2,5);
	t2 = insert(t2,50);
	t2 = insert(t2,1);
	t2 = insert(t2,40);
	t2 = insert(t2,100);
	
	printf("\nTwo trees are:\n");
	printf("\nTree 1\n");
	levelorder(t1);
	printf("\n");
	printf("\nTree 2\n");
	levelorder(t1);
	
	int *n1 = (int *)malloc(sizeof(int));
	int *n2 = (int *)malloc(sizeof(int));
	
	int a1[50],a2[50];
	*n1 = 0;
	*n2 = 0;
	
	inordermodified(t1,a1,n1);
	inordermodified(t2,a2,n2);
	
	
	/*Code to check if two trees are identical*/
	if(*n1 != *n2)
		printf("\n\nTwo trees are not identical.");

	
		
	else
	{
		int flag = 1;
		for(int i=0; i<*n1;i++)
		{
			if(a1[i] != a2[i])
			{
				flag = 0;
				break;
			}
			
		}
		
		if(flag == 0)
			printf("\n\nTwo trees are not identical.");
			
		else
			printf("\n\nTwo trees are identical.");
		
	}
	
	/*Code to check if tree 1 is complete*/
	int ct=count(t1);
    	if(isComplete(t1,0,ct))
        	printf("\nComplete tree.\n");
        	
    	else 
        	printf("\nIncomplete tree.\n");
        	
        /*To count the no of nodes within the given range*/
        int l,u;
        int count = 0;
        
        printf("\nEnter the range for tree 1: ");
        scanf("%d %d",&l,&u); 
        
        for(int i=0; i<*n1;i++)
	{
		if(a1[i]>=l && a1[i]<=u)
			count++;
	}
	
	printf("\nThe no of nodes within the given range for tree 1 = %d\n",count);
	
	printf("\nEnter the range for tree 2: ");
        scanf("%d %d",&l,&u); 
        
        count = 0;
        for(int i=0; i<*n2;i++)
	{
		if(a2[i]>=l && a2[i]<=u)
			count++;
	}
	
	printf("\nThe no of nodes within the given range for tree 2 = %d\n",count);
}

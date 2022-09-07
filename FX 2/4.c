#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop2(i,a,b) for(int i=a;i>=b;i--)
#define loop(i,a,b) for(int i=a;i<=b;i++) 

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

typedef struct numLink
{
	int no;
	struct numLink *next;
}NODE;

void movenode( NODE *head)
{
	if(head->next!=NULL)
{
	NODE *head2=head->next->next;
	NODE *k=head->next;
	NODE *k2=head->next->next;
	while(k!=NULL&&k2!=NULL&&k->next!=NULL&&k2->next!=NULL)
	{
		k->next=k->next->next;
		k2->next=k2->next->next;
		k=k->next;
		k2=k2->next;
	}
	k->next=head2;
	k2=NULL;
}
} 
//by LQ_gdwind

void SetLink( NODE *h, int n )
{
	NODE *p=NULL, *q=NULL;
	int i;
	for( i=0; i<n; i++)
	{
		p = (NODE *)malloc(sizeof(NODE));
		p->no = i+1;
		p->next = NULL;
		if( h->next == NULL )
		{
			h->next = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = q->next;
		}
	}
	return;
}

int main( )
{
	int n;
	NODE *head=NULL, *q=NULL;
	scanf("%d",&n);

	head = (NODE *)malloc(sizeof(NODE));
	head->no = -1;
	head->next = NULL;

	SetLink( head, n );
	movenode( head );

	q = head;
    while (q->next){
   		printf("%d ",q->next->no);
        q = q->next;
	} 
	printf("\n");
	
	system("pause");
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

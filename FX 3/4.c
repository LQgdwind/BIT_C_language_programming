#include "stdio.h"
#include "stdlib.h"

//别看别人代码了，赶快复习。 by LQ_gdwind; 

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

void outlist( PNODE );
void deletenode(NODE *head, int num);

int main ( )
{
    int num=1;
    PNODE head, p, newnode;
    int index = -1, value = 0;

    head = (PNODE)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1;

    p= head;
    while ( num!=0 )
    {
        scanf("%d", &num);
        if ( num!=0 )
        {
            newnode = (PNODE)malloc( sizeof(NODE) );
            newnode->next= NULL;
            newnode->data  = num;

            p->next = newnode;
            p = p->next;
        }
    }

    scanf("%d", &value);

    deletenode(head, value);
    outlist(head);
    system("pause");
    return 0;
}

void outlist( PNODE head )
{   PNODE p;
    p = head->next;
    while ( p != NULL )
    {   printf("%d\n", p->data);
        p = p->next;
    }
}

void deletenode(NODE *head, int num)
{
	int len=0;
	NODE* p=head;
	while(p!=NULL)
	{
		p=p->next;
		if(p!=NULL) len++;
	}
	if(num>len)
	{
		printf("X is too large!\n");//你tm是sb吧 x就真用x; 
		exit(0);
	}
	if(num==1)
	{
		head->next=head->next->next;
		return 0;
	}
	p=head;
	for(int i=1;i<num;i++)
	{
		p=p->next;
	}
	if(num==len) p->next=NULL;
	else p->next=p->next->next;
	return 0;
}


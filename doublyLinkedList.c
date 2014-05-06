#include<stdio.h>
#include<stdlib.h>

/* node structure for doubly linked list */
struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *prev;
};

/* adds the node in the end of the doubly linked list */
void d_append(struct dnode **q , int num )
{
	struct dnode *temp, *r;
	
	if(*q == NULL ) //Initially the doubly linked list is empty .
	{
		temp = (struct dnode *)malloc(sizeof(struct dnode));
		temp->next = NULL;
		temp->prev = NULL;
		temp->data = num;
		*q = temp;		
	}
	else
	{
		temp = *q;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		r = (struct dnode *)malloc(sizeof(struct dnode));
		r->data = num;
		r->next = NULL;
		r->prev = temp;
		temp->next = r;
	}	
}

/* adds a new node at the beginning of the linked list */
void d_addatbeg(struct dnode **q , int num )
{
	struct dnode *temp;	
	temp = (struct dnode *)malloc( sizeof(struct dnode ));
	temp->data = num;
	temp->prev = NULL;
	temp->next = *q;
	
	(*q)->prev = temp;
	*q = temp;
}

/* add a new node after the given position */	
void d_addafter(struct dnode *q , int num , int position )
{
	struct dnode *temp, *r;
	int i;
	temp = q;
	for( i = 1 ; i < position ; i++ )
	{
		temp = temp->next;
		if(temp == NULL ) 
		{
			printf("OUT OF BOUNDS");
			return;
		}
	}
	
	r = (struct dnode * )malloc(sizeof(struct dnode ));
	r->data = num;
	r->next = temp->next;
	r->prev = temp;
	temp->next = r;
	r->next->prev = r;
}
	
/* displays the doubly linked list */
void d_display(struct dnode *q )
{
	printf("\n");
	while(q != NULL)
	{
		printf("<-%d->", q->data);
		if(q->next == NULL)
		{
			printf("NULL");
		}
		q = q->next;
	}
}

/* Count the number of the nodes */
int d_count(struct dnode *q)
{
	int c = 0;
	while(q != NULL )
	{
		q = q->next;
		c++;
	}
	return c;
}

/*Display the data in the reverse direction */
void d_reversedisplay(struct dnode *q)
{
	struct dnode *temp ;
	temp = q;
	
	while(temp->next != NULL )
	{
		temp = temp->next;
	}
		
	while(temp != NULL) 
	{	
		printf("<-%d->", temp->data);
		if(temp->prev == NULL)
		{
			printf("NULL");
		}
		temp = temp->prev;
	}	
}	

/*  Delete the nodes */
void d_delete(struct dnode **q, int num )
{
	struct dnode *temp ;
	
	temp = *q;
	
	while( temp != NULL) 
	{
		if(temp->data == num )
		{
			if(temp == *q )
			{
				(*q) = (*q)->next;
				(*q)->prev = NULL;
			}
			else
			{
				if(temp->next == NULL )
				{
					temp->prev->next  = NULL;	
				}
				else
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}	
				free(temp);
			}
			 return;
		}
		temp = temp->next;
	}	
	printf("%d NOT FOUND ", num);
}

int main()
{
	struct dnode *p = NULL;
	
	printf("No. of Elements in DLL is %d ", d_count(p));	
	printf("\nAppending node in the end .");
	d_append(&p, 1);
	d_append(&p, 2);
	d_append(&p, 3);
	d_append(&p, 13);
	d_append(&p, 14);
	d_append(&p, 19);
	d_append(&p, 41);
	d_append(&p, 51);
	d_append(&p, 5);
	d_append(&p, 77);
	d_display(p);
	printf("\n");
	d_reversedisplay(p);
	printf("\nNo. of Elements in DLL is %d ", d_count(p));	
	printf("\nAppending node in the beginning.");
	
	d_addatbeg(&p, 666);
	d_addatbeg(&p, 777);
	d_addatbeg(&p, 888);
	d_addatbeg(&p, 999);
	d_display(p);
	printf("\n");
	d_reversedisplay(p);
	printf("\nNo. of Elements in DLL is %d ", d_count(p));	
	printf("\nAppending node in the position.");
	
	d_addafter(p, 40, 4);
	d_addafter(p, 10, 1);
	d_addafter(p, 60, 6);
	d_addafter(p, 40, 4);
	d_display(p);
	printf("\n");
	d_reversedisplay(p);
	printf("\nNo. of Elements in DLL is %d ", d_count(p));	
	
	printf("\nDeleting Nodes\n");
	
	d_delete(&p , 1000);
	d_delete(&p, 77);
	d_delete(&p, 13);
	d_display(p);
	printf("\n");
	d_reversedisplay(p);
	printf("\nNo. of Elements in DLL is %d \n", d_count(p));	
	

	
return 0;
}

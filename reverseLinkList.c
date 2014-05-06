#include<stdio.h>
#include<stdlib.h>

/* Singly Linked list node structure */
struct node 
{
	int data;
	struct node *next;	
};

/* adding node in sorted linked list */
void sorted_add(struct node **q , int num )
{
	struct node *temp , *r;
		
	r = (struct node *)malloc(sizeof(struct node));
	r->data = num;
	temp = *q;
	if(*q == NULL || (*q)->data > num ) 
	{
		*q = r;
		(*q)->next  = temp;
	}
	else
	{	
		while( temp != NULL )
		{	
			if(temp->data <= num)
			{
				//printf("%d\n", temp->data);
				if( temp->next == NULL ) 
				{
					//printf("rr\n");
					r->next = temp->next;
					temp->next = r;	
					return;	
				}
				else if(temp->next->data > num )
				{
					r->next = temp->next;
					temp->next = r;
					return;
				}		
			}
			temp = temp->next; 
		}
	}
}

void sorted_display(struct node *q)
{
	while(q != NULL) 
	{
		printf("%d->", q->data);
		if(q->next == NULL )
		{
			printf("NULL");
		}
		q = q->next;
	}
}

int sorted_count(struct node *q )
{
	int c = 0;
	while(q != NULL) 
	{
		c++;
		q = q->next;	
	}
	return c;
}

void reverse_linklist(struct node **q )
{
	struct node *x, *r, *s;
	r = NULL;
	x = *q;
	while(x != NULL)
	{
		s = r;
		r = x;
		x = x->next;
		r->next = s;
	}
	*q = r;
}

int main()
{
	struct node *p = NULL;
	sorted_add(&p, 1);
	sorted_add(&p, 3);
	sorted_add(&p, 2);
	sorted_add(&p, 7);
	sorted_add(&p, 6);
	sorted_add(&p, 5);
	sorted_add(&p, 4);
	sorted_add(&p, 8);
	sorted_add(&p, 10);
	sorted_add(&p, 9);
	
	sorted_display(p);
	printf("\nNo. of the elements are : %d \n", sorted_count(p));
		
	reverse_linklist(&p);
	sorted_display(p);
	printf("\nNo. of the elements are : %d \n", sorted_count(p));
		

	return 0;
}

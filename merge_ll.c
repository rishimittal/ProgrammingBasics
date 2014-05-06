#include<stdio.h>
#include<stdlib.h>
	

struct node 
{
	int data;
	struct node *next;
};

// adds in the sorted fashion
void add(struct node **q, int num )
{
	struct node *temp, *r;
	
	r = (struct node *)malloc(sizeof(struct node ));
	r->data = num;
	temp = *q;

	if(*q == NULL || (*q)->data > num )
	{
		r->next = temp;
		*q = r;
	}
	else
	{
		while(temp != NULL )
		{
			if(temp->data < num )
			{	
				if(temp->next == NULL)
				{
					temp->next = r;
					r->next = NULL;
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

/*Merging with restriction of the common element to occur only once .*/
void merge(struct node *q, struct node *p, struct node **f )
{
	struct node *z;
	
	z =NULL;	
	if(q == NULL && p == NULL)
	{
		return;
	}		

	while(q != NULL && p != NULL )
	{	
		if(*f == NULL) 
		{		
			*f = (struct node *)malloc(sizeof(struct node));
			z = *f;
		}
		else
		{
			z->next = (struct node *)malloc(sizeof(struct node ));
			z = z->next;
		}
	
		if(q->data > p->data )
		{
			z->data  = p->data;
			p = p->next;		
		}
		else if(q->data < p->data )
		{
			z->data = q->data;
			q = q->next;
		}
		else if(q->data == p->data)		
		{
			z->data = q->data;
			q = q->next;
			p = p->next;
		}
	}	
	
	while( p != NULL)
	{
		z->next = (struct node *)malloc(sizeof(struct node));
		z = z->next;
		z->data = p->data;
		p = p->next;
	}
	while( q != NULL)
	{
		z->next = (struct node *)malloc(sizeof(struct node ));
		z = z->next;
		z->data = q->data;
		q = q->next;	
	}	
	
	z->next = NULL;
}

void display(struct node *q )
{
	while(q != NULL )
	{
		printf("%d->", q->data);
		if(q->next == NULL)
		{
			printf("NULL");
		}
		q = q->next;
	}
}

int count(struct node *q)
{
	int c = 0;
	while(q != NULL )
	{
		c++;
		q = q->next;
	}
	return c;
}


int main()
{	
	struct node *first, *second , *third;
	first = second = third = NULL;
	
	add(&first , 1);
	add(&first , 3);
	add(&first , 2);
	add(&first , 4);
	add(&first , 5);
	add(&first , 9);
	add(&first , 6);

	printf("First Linked List : \n");
	display(first);
	printf("\nNo. of Elements in the first linked list : %d ", count(first));

	add(&second, 11);
	add(&second, 33);
	add(&second, 9);
	add(&second, 8);
	add(&second, 5);
	add(&second, 77);
	add(&second, 88);
	
	printf("\nSecond Linked List : \n");
	display(second);
	printf("\nNo. of the Elements in the second Linked List %d ", count(second));


	merge(first, second, &third);

	printf("\nMerged Linked List : \n");
	display(third);
	printf("\nNo. of the Elements in the Merged Linked List %d \n", count(third));

	return 0;
}

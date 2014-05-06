#include<stdio.h>
#include<stdlib.h>

/* structure of the node */
struct node
{
	int data;
	struct node *next;
};

/* adds a node at the end of the linked list */
void append(struct node **q, int num)
{
	struct node *temp , *r;
	//temp = *q;
	
	if(*q == NULL)  /* list is empty , create first node */ 
	{
		temp = (struct node * )malloc(sizeof(struct node));
		temp->data = num;
		temp->next = NULL;
		*q = temp;	
	}
	else
	{
		temp  = *q;
		/* go to the last node */
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		r = (struct node *)malloc(sizeof(struct node));
		r->data = num;
		r->next = NULL;
		temp->next = r;
	}

}

/* adds the new node in the begininng of the linked list */
void addatbeg(struct node **q, int num)
{
	struct node* temp;
	/* adds new node */
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = num;
	temp->next = *q;
	*q = temp;
	
}

/* add the new node in the specified position in linked list */
void addafter(struct node *q , int num , int position ) 
{
	struct node *temp, *r;
	int i;
	temp = q;
	for(i = 1 ; i < position  ; i++ )
	{
		temp = temp->next;
		if(temp == NULL) 
		{
			printf("OUT OF BOUNDS");
			return ;
		}
	
	}
	
	r = (struct node *)malloc(sizeof(struct node));
	r->data = num;
	r->next = temp->next;
	temp->next = r;
}

/* Display the contents of the linked list */
void display(struct node *q )
{
	printf("\n");	
	while(q != NULL )
	{
		printf("%d ->", q->data );
		if(q->next == NULL )
		{
			printf("NULL");
		}
		q = q->next;
	}
}

/* counts the number of the nodes in the linked list */
int count(struct node *q )
{
	int c = 0 ;
	while(q != NULL )
	{
		c++;
		q = q->next;
	}
return c;
}

/* Deletes the specified node from the linked list */
void delete(struct node **q, int num) 
{
	struct node *old, *temp;
	temp = *q;
	
	while(temp !=  NULL ) 
	{
		if(temp->data == num) 
		{
			if(temp == *q ) 
			{
				*q = temp->next;
				free(temp);
				return;
			}
			else
			{
				old->next = temp->next;
				free(temp);
				return;
			}
		}
		else
		{
			old = temp;
			temp = temp->next;
		}
	}
	printf("Element %d not found \n", num);
}


int main()
{
	
	struct node *p = NULL;
	
	printf("No. of the elements in the Linked List is = %d\n",count(p));
	printf("Adding nodes in the end \n");
	append(&p , 1);
	append(&p , 2);
	append(&p , 3);
	append(&p , 7);
	append(&p , 8);
	append(&p , 17);
	append(&p , 34);
	append(&p , 223);
	append(&p , 13);
	append(&p , 32);
	display(p);
	printf("\nNo. of the elements in the Linked List is = %d\n",count(p));
	printf("Adding nodes in the begining \n");	
	addatbeg(&p, 999);
	addatbeg(&p, 888);
	addatbeg(&p, 777);
	addatbeg(&p, 666);
	display(p);
	printf("\nNo. of the elements in the Linked List is = %d\n",count(p));
	printf("Adding nodes after the specified nodes \n ");
	addafter(p, 17, 4);	
	addafter(p, 34, 5);	
	addafter(p, 223, 6);	
	addafter(p, 13, 2);
	display(p);
	printf("\nNo. of the elements in the Linked List is = %d\n",count(p));
	printf("Deleting few nodes \n");
	delete(&p , 1000);
	delete(&p , 17);
	delete(&p, 223);	
	display(p);
	printf("\nNo. of the elements in the Linked List is = %d\n",count(p));
	
return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;	
};

void push(struct node **q, int num )
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = num;
	temp->next = *q;
	*q = temp;
}

int pop(struct node **q )
{
	int item;
	struct node *temp ;
	if(*q == NULL )
	{
		printf("Stack is Empty");
	}
	else
	{
		temp = *q;
		*q = temp->next;
		item = temp->data;
		free(temp);
		return item;	
	}
return 0;
}

int peek(struct node  *q ) 
{	
	if(q == NULL)
	{
		printf("Stack Empty");
	}
	else
	{
		return q->data;
	}
return 0;
}


void stack_display(struct node *q )
{
	while(q != NULL )
	{	
		printf("%d -> ", q->data);
		if(q->next == NULL )
		{
			printf("NULL");
		}
		q = q->next;
	}
}

int stack_count(struct node *q )
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
	int r;
	struct node *top = NULL;
	push(&top, 11);
	push(&top, 12);
	push(&top, 14);
	push(&top, 16);
	push(&top, 18);
	push(&top, 33);
	push(&top, 44);
	
	stack_display(top);
	printf("\nNo.  of items in stack are  %d ", stack_count(top));
	printf("\nPeeked Element : %d", peek(top));	
		
	r = pop(&top);
	printf("\nElement Popped : %d ",r );
	r = pop(&top);
	printf("\nElement Popped : %d ",r );
	r = pop(&top);
	printf("\nElement Popped : %d \n",r );
	
	stack_display(top);
	printf("\nNo.  of items in stack are  %d ", stack_count(top));
	printf("\nPeeked Element : %d\n", peek(top));	
	return 0;	
}

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

void addq(struct node **f, struct node **r, int num )
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;

	if(*f == NULL )
	{
		*f = temp;
		*r = temp;
	}
	else
	{
		(*r)->next = temp;
		*r = temp;
	}
}

int delq(struct node **f, struct node **r )
{
	struct node *q;
	int item;	
	
	if(*f == NULL )
	{
		printf("Queue  is Empty\n");
	}
	else
	{
		q = *f;	
		item = q->data;
		*f = q->next;
		free(q);
		if(*f == NULL)
		{
			*r = NULL;	
		}
		return item;	
	}
return 0;	
}

void q_display(struct node *q )
{	
	printf("front->");
	while(q !=NULL )
	{
		printf("%d->", q->data);
		if(q->next == NULL)
		{
			printf("rear");
		}
		q = q->next;
	}
}

int q_count(struct node *q )
{
	int c = 0;
	while(q != NULL )
	{
		q = q->next;
		c++;
	}
	return c;
}

int main()
{	
	struct node *front , *rear;
	int item;
	
	front = rear = NULL;	
	
	addq(&front, &rear , 11);	
	addq(&front, &rear , 12);	
	addq(&front, &rear , 14);	
	addq(&front, &rear , 11);	
	addq(&front, &rear , 44);	
	addq(&front, &rear , 55);	
	addq(&front, &rear , 232);	
	addq(&front, &rear , 33);	
	addq(&front, &rear , 22);	
	addq(&front, &rear , 90);	
	
		
	q_display(front);
	printf("\n No. of the elements in queue are : %d", q_count(front));

	item = delq(&front, &rear );
	printf("\n Item deleted : %d", item);
	item = delq(&front, &rear );
	printf("\n Item deleted : %d", item);
	item = delq(&front, &rear );
	printf("\n Item deleted : %d", item);
	item = delq(&front, &rear );
	printf("\n Item deleted : %d\n", item);

	q_display(front);
	printf("\n No. of the elements in queue are : %d\n", q_count(front));

	return 0;
}

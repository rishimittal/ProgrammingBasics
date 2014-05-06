#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


void addqatend(struct node **f , struct node **r, int num )
{
	struct node *temp;
	
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	if(*f == NULL )
	{	
		temp->next = NULL;
		*f = *r = temp;
	}
	else
	{
		(*r)->next = temp;
		*r = temp;
	}
}

void addqatbeg(struct node **f, struct node **r , int num)
{
	struct node *temp;
	
	temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = num;
	if(*f == NULL)
	{
		temp->next = NULL;	
		*f = *r = temp;
	}
	else
	{
		temp->next = *f;
		*f = temp;
	}
}

int delqatbeg(struct node **f, struct node **r)
{
	struct node *temp;
        int item;
        if(*f == NULL)
        {
                printf("Dequeue Already Empty .");
        }
        else
        {
		temp = *f;
		if(temp->next == NULL )
		{
			*f = NULL;	
			*r = NULL;	
			item = temp->data;
			free(temp);
			return (item);
		}
		else
		{
			*f = temp->next;
			item = temp->data;
			free(temp);
			return item;
		}
	}
	return 0;
}

int delqatend(struct node **f, struct node **r )
{	
	struct node *temp;
	int item;
	if(*f == NULL)
	{
		printf("Dequeue Already Empty .");
	}
	else
	{
		temp = *f;
		if(temp->next == NULL )
		{
			*f = NULL;	
			*r = NULL;	
			item = temp->data;
			free(temp);
			return (item);
		}	
		while(temp->next != *r )
		{	
			temp = temp->next;
		}
		item = temp->next->data;
		temp->next = NULL;
		free(*r);
		*r = temp;
		return (item);
	}
	return 0;
}

int deqcount(struct node *q )
{
	int c = 0;
	while(q != NULL)
	{
		c++;
		q = q->next;
	}
	return c;
}

void deqdisplay(struct node *q )
{
	while(q != NULL)
	{
		printf("%d->", q->data);
		if(q->next == NULL)
		{
			printf("NULL");
		}
		q = q->next;
	}
}

int main()
{
	struct node *front , *rear;
	
	front = rear = NULL;	
	addqatend(&front, &rear, 1);	
	addqatend(&front, &rear, 2);	
	addqatend(&front, &rear, 3);	
	addqatend(&front, &rear, 11);	
	addqatend(&front, &rear, 12);	
	addqatend(&front, &rear, 13);	
	deqdisplay(front);
	printf("\nNumber of Elements are : %d\n", deqcount(front));	

	addqatbeg(&front, &rear, 22);
	addqatbeg(&front, &rear, 33);
	addqatbeg(&front, &rear, 44);
	addqatbeg(&front, &rear, 55);
	addqatbeg(&front, &rear, 66);
	addqatbeg(&front, &rear, 77);
	
	deqdisplay(front);
	printf("\nNumber of Elements are : %d\n", deqcount(front));	

	delqatbeg(&front, &rear);
	delqatbeg(&front, &rear);
	
	deqdisplay(front);
	printf("\nNumber of Elements are : %d", deqcount(front));	
	
	printf("\n");
	delqatend(&front, &rear);
	delqatend(&front, &rear);

	deqdisplay(front);
	printf("\nNumber of Elements are : %d\n", deqcount(front));	

	return 0;	
}

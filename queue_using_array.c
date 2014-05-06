#include<stdio.h>

#define SIZE 100

struct queue 
{
	int data[SIZE];
	int front;
	int rear;
}qu;

void add(int num)
{
	if(qu.rear > SIZE)
	{
		printf("QUEUE FULL");
		return ;
	}	
	qu.rear++;
	qu.data[qu.rear] = num;
	if(qu.rear == 0)
	{
		qu.front++;
	}
}

int p_remove()
{
	if(qu.front < 0)
	{
		printf("QUEUE EMPTY");
		return 0;
	}
	int item = qu.data[qu.front];
	qu.data[qu.front] = 0;
	qu.front++;
	if(qu.front == qu.rear )
	{
		qu.front = -1;
		qu.rear = -1;
	}
return item;
}
	
void display()
{	
	int pos = 0;
	while(pos < SIZE )
	{		
		if(qu.data[pos] != 0)
		{			
			printf("%d ", qu.data[pos]);
		}
		pos++;
	}
	printf("\n");
}

int main()
{
	qu.front = -1;
	qu.rear = -1;
	
	add(3);
	add(4);
	add(56);
	add(5);
	add(8);
	add(10);
	add(11);

	display();
	
	int p;
	p = p_remove();
	printf("Item Removed : %d ", p);
	p = p_remove();
	printf("\nItem Removed : %d ", p);
	p = p_remove();
	printf("\nItem Removed : %d \n", p);
		
	display();

	add(43);
	add(99);
	add(89);

	display();
	
	p = p_remove();	
	printf("Item Removed : %d ", p);
	p = p_remove();
	printf("\nItem Removed : %d \n", p);

	display();	
	return 0;
}


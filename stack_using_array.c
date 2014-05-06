#include<stdio.h>

#define SIZE 100

struct stack 
{
	int data[SIZE];
	int top;
}st;

void push(int num)
{	
	if(st.top >= SIZE )
	{	
		printf("STACK OVERFLOW");
	}
	st.top++;
	st.data[st.top] = num;		

}

int pop()
{
	int item;
	if(st.top < 0 )
	{
		printf("STACK UNDERFLOW");
	}
	item = st.data[st.top];
	st.data[st.top] = '\0'; //Helps to dispaly the result properly.
	st.top--;
	return item;
}

int peek()
{
	//int item;
	if(st.top < 0)
	{
		printf("Stack Empty");
		return 0;
	}	
	return st.data[st.top];
}

void display()
{	
	int i = 0;
	while(st.data[i] != '\0')
	{	
		printf("%d ", st.data[i]);
		i++;
	}	
	printf("\n");
}

int main()
{
	st.top = -1;
	
	push(1);
	push(3);
	push(5);
	push(10);
	push(20);	
	push(11);
	push(32);
	push(54);
	push(55);
	push(205);
	
	display();

	int item;
	item = pop();
	printf("Item Popped : %d", item);
	item = pop();	
	printf("\nItem Popped : %d \n", item );
		
	printf("Peeked Element : %d \n", peek());
	display();
	return 0;	
}

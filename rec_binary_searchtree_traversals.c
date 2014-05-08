#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

void insert(struct node **sr, int num )
{
	if(*sr == NULL )
	{
		*sr = (struct node *)malloc(sizeof(struct node));
		(*sr)->left = NULL;
		(*sr)->data = num;
		(*sr)->right = NULL;
		return ;
	}
	else
	{
		if(num < (*sr)->data)
		{
			insert( &((*sr)->left) , num );
		}
		else
		{
			insert( &((*sr)->right) , num );
		}	
	}
	return ;
}

void inorder(struct node *s )
{
	if(s == NULL ) 
		return;
	else
	{
		inorder(s->left);
		printf("%d ", s->data);
		inorder(s->right);
	}
}	

void preorder(struct node *s)
{
	if(s == NULL )
		return;
	else
	{
		printf("%d ", s->data );
		preorder(s->left);
		preorder(s->right);
	}
}

void postorder(struct node *s )
{
	if(s == NULL)
		return;
	else
	{
		postorder(s->left);
		postorder(s->right);
		printf("%d ", s->data);
	}
}






int main()
{
	struct node *bt;
	bt = NULL;
		
	int nodes, i;	
	printf("Enter the number of the nodes in the tree  : ");
	scanf("%d", &nodes);
	
	i = 0;
	int value;
	while(i < nodes)
	{
		i++;
		printf("Enter Node %d : " , i);
		scanf("%d", &value);
		insert(&bt, value);	
	}

	printf("\nInorder traversal\n");	
	inorder(bt);
	
	printf("\nPreorder traversal\n");
	preorder(bt);
	
	printf("\nPostOrder traversal\n");
	postorder(bt);
	
	printf("\n");
	return 0;
}

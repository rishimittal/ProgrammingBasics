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

void search(struct node **root, int num, struct node **par, struct node **x , int *found )
{
        struct node *q ;
        q = *root;
        *found = 0;
        *par  = NULL;

        while(q != NULL )
        {
                if(q->data == num )
                {
                        *found = 1;
                        *x = q;
                        return;
                }

                if(q->data > num )
                {
                        *par = q;
                        q = q->left;
                }
                else
                {
                        *par = q;
                        q = q->right;
                }
        }
}

void delete_node(struct node **root, int num )
{
	int found;
	struct node *parent, *x, *xsucc;
	
	if(*root == NULL )	
	{
		printf("Tree is empty\n");
		return ;
	}
	parent = x = NULL;
	
	search(root, num, &parent, &x, &found);

	if(found == 0)
	{
		printf("Data to be deleted , not found ");
		return ;
	}
	//printf("tt\n");	
	//If node to be deleted has 2 children .
	if(x->left != NULL && x->right  != NULL )
	{
		parent = x;	
		xsucc = x->right;

		while(xsucc->left != NULL )	
		{
			parent = xsucc;
			xsucc = xsucc->left;
		}
		x->data = xsucc->data;
		x = xsucc;
	}		
	
	//If node to be deleted has 1 left children
	if(x->left != NULL && x->right == NULL)
	{
		if(parent->left == x )
		{
			parent->left  = x->left;
		}
		else
		{
			parent->right = x->left;
		}
		free(x);
		return;
	}	

	//If node to be deleted has 1 right children
	if(x->left == NULL && x->right != NULL)
	{
		if(parent->left == x)
		{
			parent->left = x->right;
		}
		else
		{
			parent->right = x->right;
		}
		free(x);
		return;	
	}	

	//If node to be deleted has 0 children
	if(x->left  == NULL && x->right == NULL )
	{
		if(parent->right == x)
		{
			parent->right = NULL;
		}
		else
		{
			parent->left = NULL;
		}
		free(x);
		return;
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
	
	int val;
	printf("\nEnter the node to be deleted : ");
	scanf("%d", &val);
	delete_node(&bt, val);
	
	printf("\nAfter Deletion, Inorder traversal\n");
        inorder(bt);

	printf("\n");
	return 0;
}

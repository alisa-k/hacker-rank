/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node * insert(node * root, int value)
{
	// create node to insert
	
	if (root == 0)
	{
		node *newNode = new node;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
	}
	else
	{
		if (root->data > value)
			root->left = insert(root->left, value);
		else
			root->right = insert(root->right, value);
	}
	return root;
}

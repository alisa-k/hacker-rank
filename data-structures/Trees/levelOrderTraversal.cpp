#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

node **createQueue(int *front, int *back)
{
	node **queue = new node * [MAX_SIZE];

	*front = 0;
    *back = 0;
	return queue;
} 
 
void enQueue(node **queue, int *back, node *newNode)
{
  	queue[*back] = newNode;
  	(*back)++;
}     
 
node *deQueue(node **queue, int *front)
{
  	(*front)++;
  	return queue[*front - 1];
}     

void LevelOrder(node *root)
{
	/* create the queue */
	int back, front;
  	node **queue = createQueue(&front, &back);  
  	node *tmpNode = root; 
 
	while(tmpNode)
	{
		cout << tmpNode->data << " ";

		/* enqueue the left child */
		if(tmpNode->left)
	  		enQueue(queue, &back, tmpNode->left);

		/* enqueue the right child */
		if(tmpNode->right)
	  		enQueue(queue, &back, tmpNode->right);

		/* dequeue the node and make it the tmpNode */
		tmpNode = deQueue(queue, &front);
	}
	cout << endl;
}
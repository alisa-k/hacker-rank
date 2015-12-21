/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
	Node *pN = head;

	if (head == NULL)
		return NULL;
	if (position == 0)
	{
		head = head->next;
		return head;
	}

	Node *prev = head;

	for (int i = 0; i < position - 1; i++)
	{
		prev = prev->next;
	}
	if (prev->next)
	{
		Node *tmp = prev->next->next;
		prev->next = tmp;
	}
	return head;
}
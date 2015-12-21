/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
	Node *pA = headA;
	Node *pB = headB;
	
	while (pA && pB)
	{
		if (pA->data != pB->data)
			return 0;
		pA = pA->next;
		pB = pB->next;
	}
	if (pB != 0)
		return 0;
	return 1;
}
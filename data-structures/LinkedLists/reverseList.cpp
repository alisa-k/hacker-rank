/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
  Node *prv = NULL;
  Node *cur = head;
  Node *nxt = NULL;

  while (cur != NULL)
  {
  	nxt = cur->next;
  	cur->next = prv;
	prv = cur;
	cur = nxt;

  }
  head = prv;
  return head;
}
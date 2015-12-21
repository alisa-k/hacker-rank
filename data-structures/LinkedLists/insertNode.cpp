/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 

	Node *pn = new Node;
    pn->data = data;
    
    if(position == 0)
    {
        pn->next = head;
        head = pn;
        return head;
    }
    
    Node *curr = head;
 
    for(int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }
    
    if(curr != NULL)
    {
        Node *next = curr->next;
        curr->next = pn;
        pn->next = next;
        return head;
    }

    return head;
}
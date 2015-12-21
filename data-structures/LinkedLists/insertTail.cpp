Node* Insert(Node *head,int data)
{
	Node *pN = new Node;
	pN->data = data;
	pN->next = NULL;

	if (head == NULL)
	{
		head = pN;
		return head;
	}

	Node *qN = head;
	while (qN->next)
	{
		qN = qN->next;
	}
	qN->next = pN; 
    return head; 
}
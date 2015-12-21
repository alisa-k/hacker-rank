/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void printLeft(node *node)
{
    if (node == NULL)
        return;
    /* call on left */ 
    printLeft(node->left);
    cout << node->data << " ";   
}

void printRight(node *node)
{
    if (node == NULL)
        return;
    /* call on right */
    cout << node->data << " ";
    printRight(node->right);
}
void top_view(node *root)
{
    if (root == NULL)
        return;
    printLeft(root->left);
    cout << root->data << " ";
    printRight(root->right);
}

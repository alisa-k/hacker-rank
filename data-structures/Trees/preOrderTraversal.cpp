/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Preorder(node *root) {
    
    if (root == NULL)
          return;
    
    cout << root->data << " ";
    
    /* left subtree */
    Preorder(root->left);
    
    /* right subtree */
    Preorder(root->right);
}
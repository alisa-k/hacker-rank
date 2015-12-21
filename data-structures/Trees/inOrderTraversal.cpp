/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Inorder(node *root) {
    
    if (root == NULL)
        return;
    
    /* call on left subtree */
    Inorder(root->left);
 
    /* print node data */
    cout << root->data << " ";  
 
    /* call on right subtree */
    Inorder(root->right);
}

/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Postorder(node *root) {

    if (root == NULL)
        return;
 
    /* call on left subtree */
    Postorder(root->left);
 
    /* call on right subtree */
    Postorder(root->right);
 
    cout << root->data << " ";
}
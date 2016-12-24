/* Given a binary tree, your task is to complete the function minDepth which takes one argument the root of the binary tree and prints the min depth of  binary tree */

int minDepth(Node *node)
{
//Your code here
    if (node == NULL) return 0;
    
    if (node->left == NULL && node->right == NULL) return 1;
    
    if (node->left == NULL) return minDepth(node->right) + 1;
    if (node->right == NULL) return minDepth(node->left) + 1;
    
    return min(minDepth(node->left), minDepth(node->right)) + 1;
}

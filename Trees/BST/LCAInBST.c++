/*LCA in BST is simpler and easy way to do it is check at every node one target is in
left subtree and other is in right subtree then current node is LCA
if both are in left subtree then move to left
if both are in right subtree then move to right
*/


TreeNode LCA(TreeNode* root, int a, int b) {
    if (root == NULL) return NULL;

    // If both a and b are smaller than root, then LCA lies in left subtree
    if (a < root->val && b < root->val) {
        return LCA(root->left, a, b);
    }
    
    // If both a and b are greater than root, then LCA lies in right subtree
    if (a > root->val && b > root->val) {
        return LCA(root->right, a, b);
    }
    
    if( a == root->val || b == root->val) {
        return root; // If one of the nodes is the root, return root
    }
    if((root->val > a && root->val < b) || (root->val < a && root->val > b)) {
        return root; // If one node is in left and other is in right, return root
    }
    // If we reach here, then root is the LCA
    return root;
}
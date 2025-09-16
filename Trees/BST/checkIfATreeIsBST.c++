/*we can a basic implementation is do inorder traversal and store the values and 
then check whether the values that were stored are in the asc or not
if not then it is not a BST */

/*second approach is best approach range validating 
as we know if it is a BST tree then the left subtree of the given node should be less than the root node and right subtree should be greater than the root 
node so for the root node we may not the upper and lower range so we will use max and minimim as inT_MAX and INT_MIN
as there range and for left suntree we use [min, root->data] and 
for right subtree we use [root->data, max]
for every node we check whether the value is in the range or not
if it is in range then we move to left and right if not then we will return to 
if we get atleast one false then we return false

*/



//simple inorder using a vector
void inorder(TreeNode* root, vector<int>& v) {
    if (root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}


bool isSorted(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= v[i - 1]) return false;
    }
    return true;
}





//second approach 

bool IsBST(TreeNode  * root,int left_Range,int right_Range) {
    if(root==NULL)return true;
    bool left = IsBST(root->left,left_Range,root->val);
    bool right = IsBST(root->right,root->val,right_Range);
    if(root->val>left_Range and root->val<right_Range and left and right){
        return true;
    }
    return false;
}


//MAXIMUM path sum is one of the good problem that teaches hoe to do manipulation in the traversal of the tree
//it is a problem that can be solved using the basic tree traversal and some manipulation in between



//i will try to explain this problem as 2 problems 

//lets say there are only positive numbers prensent in the tree then the maximum path sum will be the sum of all node in the path which 
//giving max sum

//use reference variable to track the maximum path sum
int maxiPathSum(TreeNode* root,int &maxi) {
    if(root==NULL)return 0;
    int lh=max(0,maxiPathSum(root->left,maxi)); //if the left child is negative then we will take 0
    int rh=max(0,maxiPathSum(root->right,maxi)); //if the right child is negative then we will take 0
    maxi=max(maxi,lh+rh+root->val); //we will take the maximum of the current node and the left and right child
    return root->val+max(lh,rh); //returning the maximum path sum from the current node
}



//if there are negative numbers present in the tree 

//in this we do the same traversal but we need to do slight manipulation in the code
int maxiPathSum(TreeNode *root,int &maxi){
    if(root==NULL)return 0;
    int left = max(0, maxiPathSum(root->left, maxi)); //if the left child is negative then we will take 0
    int right = max(0, maxiPathSum(root->right, maxi)); //if the right child is negative then we will take 0
    maxi = max(maxi, left + right + root->val); //we will take the maximum of the current node and the left and right child
    return root->val + max(left, right); //returning the maximum path sum from the current node
}


//if there is a specification we should reach atleast one leaf then we can remove zero conditioon and the code looks like

int maxiPathSum(TreeNode *root,int &maxi){
    if(root==NULL)return LLONG_MIN;
    if(root->left==NULL && root->right==NULL) return root->val; //if it is leaf node then return the value of the node
    int left = maxiPathSum(root->left, maxi); //if the left child is
    int right = maxiPathSum(root->right, maxi); //if the right child is negative then we will take 0
    maxi = max(maxi, left + right + root->val); //we will take the maximum of the current node and the left and right child
    return root->val + max(left, right); //returning the maximum path sum from
}
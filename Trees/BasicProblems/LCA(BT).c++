//we can do it in 2 ways 

//first ids tarverse for individal node path from the root and store them and then compare the paths
//second is to use the parent pointer and go up the tree till we find the common node


//second code will be more efficient as it will take O(h) time where h is the height of the tree
//first code will take O(n) time where n is the number of nodes in the tree


//first code
bool PathToNode(TreeNode  *root,vector<TreeNode*>&v,int target){
    if(root==NULL)return false;
    v.push_back(root);
    if(root->val==target)return true;
    if(PathToNode(root->left,v,target)||PathToNode(root->right,v,target))return true;
    v.pop_back();
    return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode *>ans1,ans2;
    PathToNode(root,ans1,p->val);
    PathToNode(root,ans2,q->val);
    int len=min(ans1.size(),ans2.size());
    TreeNode* ans=root;
    for(int i=0;i<len;i++){
        if(ans1[i]!=ans2[i])break;
        ans=ans1[i];
    }
    return ans;
}



//second code
TreeNode* PathToNode(TreeNode  *root,vector<TreeNode*>&v,int p,int q){
    if(root==NULL)return root;
    if(root->val==p || root->val==q)return root;
   TreeNode * left=PathToNode(root->left,v,p,q);
   TreeNode * right=PathToNode(root->right,v,p,q);
   if(left and right)return root;
   
   return left!=nullptr?left:right;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode *>ans1,ans2;
    TreeNode *ans=PathToNode(root,ans1,p->val,q->val);
     return ans;
}
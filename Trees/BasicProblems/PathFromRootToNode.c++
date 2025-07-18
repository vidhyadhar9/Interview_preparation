//here we need to find the path from root to given node and store in the array 
//intiall traverse from the root node by pushing it into the vector and travwrse left and then right
//if you find the node thern push it and return true 
//if you find true from anyof the side (right or left ) then dont pop and return true;
//if no side return true then pop and return false;
//repeat it
bool PathToNode(TreeNode  *root,vector<TreeNode*>&v,int target){
    if(root==NULL)return false;
    v.push_back(root);
    if(root->val==target)return true;
    if(PathToNode(root->left,v,target)||PathToNode(root->right,v,target))return true;
    v.pop_back();
    return false;
}


//similar kind of question path from root to leaf

//here there will be no target but every leaf act as a target 
//we detremine like root->left and root->right==null then it is a leaf

void PathRootToLeaf(TreeNode *root,vector<vector<int>>&ans,vector<int>&v){
    if(!root->left and !root->right){
        v.push_back(root->val);
        ans.push_back(v);
        v.pop_back();
        return ;
    }
    v.push_back(root->val);
    if(root->left)PathRootToLeaf(root->left,ans,v);
    if(root->right)PathRootToLeaf(root->right,ans,v);
    v.pop_back();
    return ;
}
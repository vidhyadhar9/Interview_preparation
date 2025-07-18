//it is a classic example of level order traversal with slight modifications
//while doing bfs or level order traversal we will be using queue
///we estimate the level size by using q.size then we will declare the size of the array and then 
//based on the zigzag counter we will insert the elemnts either from front or back 
//while inserting we will push the nodes left and right into queue if they existed
//for every level that vector will be pushed into vector<vector<in>> ans
//then return the answer
//Tc would be o(n) and space will be o(n)


vector<vector<int>> zigzag(TreeNode *root){
    //bfs
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<TreeNode*>q;
    q.push(root);
    int f=0;
    while(q.size()){
        int s=q.size();
        vector<int>v(s);
        k=f==1?s-1:0;
        for(int i=0;i<s;i++){
            TreeNode * node =q.front();
            q.pop();
            if(f)v[k--]=node->val;
            else v[k++]=node->val;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        ans.push_back(v);
        f=!f;
    }
    return ans;
}
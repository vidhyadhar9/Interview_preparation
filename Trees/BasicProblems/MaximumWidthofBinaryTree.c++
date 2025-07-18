//the max width of the tree is the maximum distance between the left and right most nodes at any level

//the process is finding the position of each node and for each level claculating right-left distance
//the node value /position could be get by 2*i+1 for left node and 2*i+2 for right node
//if the i is the current node value/position

int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL)
    return 0;
    queue<pair<TreeNode*,long long int>>q;
    q.push({root,0});
    int ans=1;
    while(!q.empty())
    {
        int n=q.size();
        int mini=q.front().second;
        long long last=0,first=0;
        first=q.front().second;
        last=q.back().second;
        ans=max(last-first*1ll+1,ans*1ll);
        for(int i=0;i<n;i++)
        {
            int curr=first=q.front().second;
            TreeNode* node=q.front().first;
            q.pop();
            if(node->left)
            q.push({node->left,2*1ll*curr+1});
            if(node->right)
            q.push({node->right,2*1ll*curr+2});
        }
        
    }
    return ans;
}
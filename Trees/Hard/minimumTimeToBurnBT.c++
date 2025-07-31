/*Here in this problem we will be given a binary Tree and target will be given we need to find the minimum time to burn whole tree from the target
for each level it takes 1 unit of time 
Approach
In this solution  i will try to explain the solution using the bfs as it is durning level wise i will try to convert the whole tree 
into graph and the  we will do bfs from the given start node which takes the max level from the target
*/

/*time complexity will as we traversing the whole tree onec (ex:inorder)-->o(n) and we will be using bfs which will be O(V+E) where v will be the Nodes n and E will be the 
edges which will be the 2*edges of trees*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //building a Graph
    void build(TreeNode * root,map<int,vector<int>>&mp){
        if(root==NULL)return ;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        build(root->left,mp);
        build(root->right,mp);
    }


    int bfs(map<int ,vector<int>>&mp,int start){
        int c=0;
        queue<pair<int ,int>>q;
        unordered_map<int,int>vis;
        vis[start]=1;
        q.push({start,0});
        while(q.size()){
            int  node = q.front().first;
            int count = q.front().second;
            q.pop();
            vis[node]=1;
            c=max(c,count);
            for(auto it:mp[node]){
                if(vis[it]==0)
                q.push({it,count+1});
            }
        }
        return c;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>>mp;
        build(root,mp);
       return  bfs(mp,start);
    }
};
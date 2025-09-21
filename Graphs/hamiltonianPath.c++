/*path from one to all other node and each node is visited exactly once
e.g 0->1->2->3 is a hamiltonian path

each node visiting once mean you cannot comback to the node and again do traversal you need to visit all the nodes
0->1->2->0->3 is not a hamiltonian path
because in backtracking you should not visit the node again
if you are trying to visit the node again you need to backtrack and eliminate that path
and again you have to explore in other ways


Approach 1:
we will be using backtracking to solve this problem
*/


//solution

class Solution {
  public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,int c){
        
        vis[node]=1;
        if(c==graph.size()-1)return true;
        for(auto it:graph[node]){
            if(vis[it]==0)
            if(dfs(it,graph,vis,c+1))
            return true;
        }
        vis[node]=0;
        return false;
    }
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        
        vector<vector<int>>graph(n+1);
        vector<int>vis(n+1,0);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int c = 1;
        for(int i=1;i<=n;i++)
        if(dfs(i,graph,vis,c))
        return true;
        return false;
        
        
    }
};

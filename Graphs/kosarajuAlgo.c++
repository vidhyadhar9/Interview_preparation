/*
its helpful to find the scc and longest cycle in a directed graph

Kosaraju's algorithm is a two-pass algorithm for finding strongly connected components (SCCs) in a directed graph. The algorithm works as follows:

1. Perform a depth-first search (DFS) on the original graph to determine the finishing order of vertices.
2. Reverse the graph (i.e., reverse the direction of all edges).
3. Perform DFS on the reversed graph, processing vertices in the order determined in step 1. Each DFS call will identify one SCC.

The algorithm has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges.

To find the longest cycle in a directed graph, you can use a modified version of the DFS algorithm. The idea is to keep track of the length of the current path and update the maximum
length whenever you encounter a back edge (i.e., an edge that points to an ancestor in the DFS tree). This approach can also be implemented in O(V + E) time.

Overall, Kosaraju's algorithm is a powerful tool for analyzing the structure of directed graphs and can be used to solve a variety of problems related to connectivity and cycles.


types of problems can be solved using kosaraju's algorithm:

1. Finding Strongly Connected Components (SCCs): Kosaraju's algorithm is primarily used to identify SCCs in a directed graph.
 An SCC is a maximal subgraph where every vertex is reachable from every other vertex within the subgraph.

2. Detecting Cycles: By identifying SCCs, Kosaraju's algorithm can help detect cycles in directed graphs.

3. Condensed Graph Construction: After finding SCCs, you can create a condensed graph where each SCC is 
represented as a single vertex.
 This condensed graph is a Directed Acyclic Graph (DAG), which can be useful for further analysis.

4. Topological Sorting: Once you have the condensed graph (DAG), you can perform a topological sort on it.

*/


//longest cycle in the directed graph it can be detected using kosaraju's algorithm

class Solution {
public:
    void dfs(int node ,vector<int>& edges,vector<int>&vis,stack<int>&st){
        vis[node]=1;
        if(edges[node] != -1 && vis[edges[node]]==0){
        dfs(edges[node],edges,vis,st);
    }
        st.push(node);
    }
    int dfs2(int node,vector<vector<int>>&graph,vector<int>&vis){
        if(vis[node])return 0;

        vis[node]=1;
        
        int ans = 0;
        for(auto it:graph[node]){
            if(vis[it]==0){
               ans= max(dfs2(it,graph,vis)+1,ans);
            }
        }
        return ans;

    }
    int longestCycle(vector<int>& edges) {
        
        vector<int>vis(edges.size(),0);
        stack<int>st;
        for(int i=0;i<edges.size();i++){
            if(vis[i]==0)
            dfs(i,edges,vis,st);
        }

        vector<int>revis(edges.size());

        vector<vector<int>>revgraph(edges.size());

        for(int i=0;i<edges.size();i++){
            if(edges[i]==-1)continue;
            revgraph[edges[i]].push_back(i);
        }
        int ans = 0;
        while(st.size()){
            int u = st.top();
            st.pop();
            if(revis[u])continue;
            ans = max(dfs2(u,revgraph,revis),ans);
        }
        return ans<1?-1:ans+1;
    }
};



/*


*/
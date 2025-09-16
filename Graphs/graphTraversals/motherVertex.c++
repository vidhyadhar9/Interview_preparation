/* question 

to find the parent here the parent node will the node which helps us to traverse the whole graph in one go
A Mother Vertex in a Graph G is a vertex v such that all other vertices in G can be reached by a path from v.

*/












//solution 

/*
approach 1 -->Do dfs from each and every node and check if we can visit all the nodes or not
Tc = v*(v+e)
sc = o(v)


approach -2 : do the dfs for the first time we will get a node which might help us to iterate the whole graph in one go 
so to deternin that node we  need to do one dfs
after dfs we will track the last tarversed node which helsp us to traverse the complete graph 

if we encounter any of the non v isted node then it might be the last visted node because previous
nodes doesnt helped us to traverse the whole graph

so we will traverse one more dfs using last visted node again if we found it helpsed us to  tarverse all the nodes then it will teh  
anser else -1

tc o(2*V)
sc = o(v)
*/


class Solution {
  public:
    // Function to find a Mother Vertex in the Graph.
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it :adj[node]){
            if(vis[it]==0)dfs(it,adj,vis);
        }
        
    }
    int findMotherVertex(int V, vector<int> adj[]) {
        // Code here
        //we will find the last visited node whcih might made us to trvaerse the whole graph
        //its like checking for the possiblity
        
        vector<int>vis(V,0),vis2(V,0);
        int lastNode = 0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                lastNode = i;//0,4
            }
        }
        
        
        dfs(lastNode,adj,vis2);
        
        for(int i=0;i<V;i++){
            if(vis2[i]==0)return -1;
        }
        return lastNode;
        
        
        
    }
};
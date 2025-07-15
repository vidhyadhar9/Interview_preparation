//toplogical sorting in dfs way
#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> topo_order;
    //we can use stack instead of vector and then no nee of reversing just have to 
    // push elements in stack and then po and store the elemenst (if we usestack)
    
    function<void(int)> dfs = [&](int node) {
        visited[node] = 1; // mark as visited
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor);
            }
        }
        topo_order.push_back(node); // add to topo order after visiting all neighbors
    };
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    
    reverse(topo_order.begin(), topo_order.end()); // reverse to get correct order
    return topo_order;

}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> topo_order = topological_sort(adj);
    for(int i : topo_order){
        cout << i << " ";
    }
    return 0;
}
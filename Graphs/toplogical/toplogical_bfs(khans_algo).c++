//khans algo
#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    vector<int> topo_order;
    
    // Calculate indegree of each node
    for(int i = 0; i < n; i++) {
        for(int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    
    queue<int> q;
    
    // Enqueue nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo_order.push_back(node);
        
        // Decrease indegree of neighbors
        for(int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return topo_order;
}
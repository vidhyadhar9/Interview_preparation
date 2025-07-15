// Shortest Path in Directed Acyclic Graph (DAG)
//in DAG we can find shortest path in O(V+E) time complexity
//in DAG we can use topological sort to find the shortest path
//since in topological sort the first visited node itself the parent then the parent + edge weight will be the distace from the source
//this is the code for the DAG shortest path using d=bfs(khan's algorithm  )
// Time Complexity: O(V + E)
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int V) {
   
    vector<int> distance(V, INT_MAX);
    distance[0] = 0;
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int j : adj[i]) {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (distance[neighbor] > distance[node] + 1) {//relaxation step
                //this is the relaxation step where we update the distance if we find a shorter path
                distance[neighbor] = distance[node] + 1;//if weight exist the add wieght here of weigt from node to it(neighbor)
            }
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

}



//if there is any weight use the queue with pair where pair will be (node, weight)
//thye at relaxation add the weight to the distance
//for example if the edge is (u, v) with weight w then we will do
//if (distance[v] > distance[u] + w) {
//    distance[v] = distance[u] + w;
//    q.push({v, distance[v]});
//}
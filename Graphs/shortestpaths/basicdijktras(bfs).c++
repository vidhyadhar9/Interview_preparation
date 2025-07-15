//the basic implementation of Dijkstra's algorithm using BFS
//in this the traversal from the source to the other nodes using bfs -->in bfs 
//the shortest path is always found : as the undirected graph is traversed level by level
//and the first time a node is reached is the shortest path to it (since it is level wise (bfs)\

//the time complexity is O(V+E) where V is the number of vertices and E is the number of edges
//space complexity is O(V) for the queue and O(V) for the visited arrayor distance array

#include <bits/stdc++.h>
using namespace std;

//given adjacny list of the graph
vector<int> bfs(vector<vector<int>>& graph, int source) {
   
    vector<int>distance(graph.size(), INT_MAX);
    queue<int> q;
    q.push(source);
    distance[source] = 0; // distance from source to itself is 0

    while(q.size()){
        int node =q.front();
        q.pop();
        for(auto  it:graph[node]) {
           if(distance[it]>distance[node]+1){
                q.push(it);
                distance[it]=distance[node]+1; // update the distance to the node and instead of 1 you can add the weight if it is a weighted graph
                //if the graph is weighted then you can use a pair in the queue to store the weight as well
                //for example if the edge is (u, v) with weight w then we will
           }
        }

    }
    return distance;
}
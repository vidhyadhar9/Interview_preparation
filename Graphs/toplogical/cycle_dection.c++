//cycle can be detected using toplogical sorting 
//because topological sorting is only possible if there is no cycle in the graph
//if there is a cycle then the topological sorting will not be possible 
//that mena if we cannot get all nodes after topological sorting then there is a cycle in the graph
#include <bits/stdc++.h>
using namespace std;

bool cycle_detection(vector<vector<int>>& adj) {
   
    queue<int> q;
    int n = adj.size();
    vector<int>indegree(n, 0);
    vector<int> topo_order;

    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(q.size()){
        int node= q.front();
        q.pop();
        topo_order.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    //now check the size of the topo_order vector
    //if it is not equal to n then there is a cycle in the graph
   if(topo_order.size() != n){
       //there is a cycle
       return true;
   }
   return false;
}
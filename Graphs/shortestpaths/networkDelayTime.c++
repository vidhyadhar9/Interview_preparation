/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.*/


//normal dijktras algorithm using bfs
//the time complexity is O(E + V log V) where E is the number of edges
//the space complexity is O(V) for the distance array and O(V) for the priority queue
//you will given with nodes and edges and the time it takes to travel from one node to another
//here k will be the source node from which the signal is sent
//we will use a priority queue to store the nodes and the distance from the source node

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    priority_queue<vector<int> ,vector<vector<int>>,greater<vector<int>>>pq;
    vector<vector<pair<int,int>>>nodes(n+1);
    for(auto it:times){
        nodes[it[0]].push_back({it[1],it[2]});
    }

    vector<int>dis(n+1,1e9);
    pq.push({0,k});
    dis[k]=0;
    while(pq.size()){
        auto it = pq.top();
        pq.pop();
        int cost = it[0];
        int source = it[1];
        for(auto node : nodes[source]){
            if(dis[node.first]>cost+node.second){
                pq.push({cost+node.second,node.first});//cost,node
                //here we are pushing the cost and the node into the priority queue
                dis[node.first]=cost+node.second;
            }
        }
    }

    dis[0]=0;
    int cost=0;
    for(auto it:dis){
        if(it==1e9)return -1;
        cost=max(it,cost);
    }
    return cost;       
}
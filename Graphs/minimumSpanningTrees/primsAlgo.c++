/*in minimum spanning tree we will be given the tree with nodes and edges we need to 
draw a tree from the nodes and edges provided
A tree is with N nodes and N-1 edges and is acyclic
In minimum spanning tree the over all sum of all edges should be minimum and each and every node has
 to be visited from anyother node
*/


int minimumSpanningTree(vector<vector<int>>&graph,int V){


    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>vis(V,0);

    pq.push({0,0});
    int ans =  0;
    while(pq.size()){
        int node = pq.front().second;
        int cost = pq.front().first ;
        pq.pop();
        if (vis[node]==1)continue;
        vis[node] = 1;
        ans += cost ;

        for(auto it :graph[node]){
            if(vis[it.first]){
                continue;
            }
            pq.push({it.second,it.first});
        }

    }
    return ans;



}
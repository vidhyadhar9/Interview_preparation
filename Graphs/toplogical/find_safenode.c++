    //no outgoing edges
    //try to make the array in reveerse order i.e.., reverse the edge directions
    //apply the topological sorting
    //if indegree is 0 then it is a safe node

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

    vector<int>indegree(graph.size());//o(n)
    int n = graph.size();
    vector<vector<int>>graph2(n);//o(n*n)
    //reverse the graph o(n +E)
    for(int i=0;i<n;i++){
        for(auto it:graph[i]){
            graph2[it].push_back(i);
        }
    }
    //indegree of the graph2
    //o(n+E)-->n for visiting each node and E for visiting each edge
    for(int i=0;i<n;i++){
        for(auto it:graph2[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    //push all the nodes with indegree 0
    for(int i=0;i<n;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int>ans;
    //BFS -->o(v+e)
    while(q.size()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:graph2[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    sort(ans.begin(),ans.end());//sort the answer in ascending order o(ans.size() * log(ans.size())) + o(2*ans.size()) for the sort and the push_back operations
    return ans;

}
/*
given an undirected graph return the length of the shortest cycle in the graph. 
If no cycle exists, return -1.

Approach done Bfs for each and every node and check if we can reach the starting 
node again if yes then we have found a cycle

as it is BFS we are sure that it is the shortest cycle
*/


class Solution {
public:
    int bfs(int start,vector<vector<int>>&edges,vector<int>&vis){
        queue<pair<pair<int,int>,int>>q;
        q.push({{start,1},-1});
        int mini = 1e9;
        while(q.size()){
            int node = q.front().first.first;
            int cost = q.front().first.second;
            int parent = q.front().second;
            vis[node]=1;
            q.pop();
            for(auto it:edges[node]){
                if(it==parent)continue;
                if(start==it)return cost;
                q.push({{it,cost+1},node});
            }
        }

        return mini;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int maxi  = 0;
        for(int i=0;i<edges.size();i++){
            maxi = max(maxi,edges[i][0]);
            maxi = max(maxi,edges[i][1]);
        }
        vector<vector<int>>v(maxi+1);
        for(auto it :edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }

        
        int ans = 1e9;
        for(int i=0;i<maxi;i++){
            vector<int>vis(maxi+1,0);
            int tarversal = bfs(i,v,vis);
            ans= min(ans,tarversal);
            
        }
        return ans==1e9?-1:ans;
    }
};
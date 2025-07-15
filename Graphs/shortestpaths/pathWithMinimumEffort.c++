/*You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell*/

//Approach: Variation of Dijkstra's algorithm
//in this i maintained the visisted array which also a distance array 
//in distance array i tried to track the max absolute difference through the path and also minimum effort to reach that particular cell
//whenever i reach a cell i check if the current effort is less than the previous effort to reach that cell
//if it is then i update the distance array and push the cell into the queue

//for example you reached cell (i, j) with effort e and the previous effort to reach that cell was prev_e
//if e < prev_e then we update the distance array and push the cell into the queue


//code
int minimumEffortPath(vector<vector<int>>& heights) {
    vector<vector<int>>vis(heights.size(),vector<int>(heights[0].size(),1e9));
    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0},1e9});
    vis[0][0]=0;

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int n=heights.size();
    int m=heights[0].size();

    //Bfs traversal o((n*m)^2) time complexity 
    while(q.size()){
        int i=q.front().first.first;
        int j=q.front().first.second;
        int cost=q.front().second;
        q.pop();
        for(int ind=0;ind<4;ind++){
            int nodex=dx[ind]+i;
            int nodey=dy[ind]+j;
            if(nodex<0||nodey<0||nodex>=n||nodey>=m
            ||vis[nodex][nodey]<=max(vis[i][j],abs(heights[nodex][nodey]-heights[i][j])))continue;

            vis[nodex][nodey]=max(vis[i][j],abs(heights[nodex][nodey]-heights[i][j]));
            q.push({{nodex,nodey},vis[nodex][nodey]});
        }
    }
    return vis[n-1][m-1];
}
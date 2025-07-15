//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
//here we use 2D array as distance array -->we can use bfs to find the shortest path in the maze
//the time complexity is O(n^2) where n is the number of rows or columns



int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>>vis(n,vector<int>(n,1e9));

    queue<pair<int,pair<int,int>>>q;
    if(grid[0][0]==1)return -1;
    vis[0][0]=1;
    q.push({1,{0,0}});
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};// directions for 8 possible moves (up, down, left, right, and diagonals)
    //dx and dy are used to move in all 8 directions
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    //we use a queue to store the current node and the distance from the source
    //we use a pair to store the distance and the node
    while(q.size()){
        int cost=q.front().first;
        int nodei =q.front().second.first;
        int nodej =q.front().second.second;
        q.pop();
        for(int i=0;i<8;i++){
            int newnode = nodei +dx[i];
            int newnode2 =nodej+dy[i];
            if(newnode>=0&&newnode<n&&newnode2>=0&&newnode2<n&&grid[newnode][newnode2]==0&&vis[newnode][newnode2]>cost+1){
                vis[newnode][newnode2]=cost+1;
                q.push({cost+1,{newnode,newnode2}});
            }
        }
    }
    if(vis[n-1][n-1]==1e9)return -1;
    return vis[n-1][n-1];
}

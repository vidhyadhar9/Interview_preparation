/*

knight problem is the simple graph matrix problem where you need to reach to the target 
position in the minimum number of jumps

Approach 1:
to find the minimum jumps we can use the bfs approach
we will use the queue to store the position of the knight and the number of jumps taken to
reach that position
we will also use the visited array to mark the visited positions

tc -- o(V)-->o(n*m)
sc -- o(n*m)
*/



//solution

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        q.push({{knightPos[0],knightPos[1]},0});
        int dx[8] = {1,1,2,2,-1,-1,-2,-2};
        int dy[8] ={-2,2,1,-1,-2,2,1,-1};
        while(q.size()){
            int index_x = q.front().first.first;
            int index_y = q.front().first.second;
            int count = q.front().second;
            if(targetPos[0]==index_x and targetPos[1]==index_y)return count;
            q.pop();
            for(int i=0;i<8;i++){
                int newIndex_x = index_x + dx[i];
                int newIndex_y = index_y + dy[i];
                if(newIndex_x<0||newIndex_x>n||newIndex_y<0||newIndex_y>n||vis[newIndex_x][newIndex_y])continue;
                 vis[newIndex_x][newIndex_y]=1;
                q.push({{newIndex_x,newIndex_y},count+1});
            }
            
        }
        return 0;
    }
};
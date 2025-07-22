// User function template for C++

/*Rat in a Maze
it is a backtracking problem where we have to find all the paths from the top left corner to the bottom right corner of a grid.
We can only move in 4 directions: up, down, left, and right.
while moving we have to store the path in a string and return all the paths.
We can represent the grid as a 2D vector of integers where 1 represents a cell
with value 1 (which we can move on) and 0 represents a cell with value 0 (which we cannot move on).
We have to avoid obstacles (represented by 0) and only move on cells with value 1.
*/

void fun(string &s,vector<string>&ans,vector<vector<int>> &mat,int ind,int indj,vector<vector<int>>&vis)
{
    if(ind>=mat.size()||ind<0||indj>=mat.size()||indj<0||vis[ind][indj]||mat[ind][indj]==0)
    return ;
    if((ind==mat.size()-1)&&(indj==mat.size()-1))
    {
        ans.push_back(s);
        return ;
    }
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    for(int i=0;i<4;i++)
    {
        int newid=ind+dx[i];
        int newidj=indj+dy[i];
        if(mat[ind][indj]&&vis[ind][indj]==0)
        {
            vis[ind][indj]=1;
            if(dx[i]==0&&dy[i]==-1)
            s.push_back('L');
            else if(dx[i]==0&&dy[i]==1)
            s.push_back('R');
            else if(dx[i]==1&&dy[i]==0)
            s.push_back('D');
            else
            s.push_back('U');
            fun(s,ans,mat,newid,newidj,vis);
            s.pop_back();
            vis[ind][indj]=0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &mat) {
    // Your code goes here
    vector<string>ans;
    string s;
    vector<vector<int>>vis(mat.size(),vector<int>(mat.size(),0));
    fun(s,ans,mat,0,0,vis);
    
    return ans;
    
}

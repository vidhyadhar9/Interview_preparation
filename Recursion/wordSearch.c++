bool fun(int i,int j,int ind,vector<vector<char>>& board, string word,vector<vector<int>>&vis)
{
    int n=board.size(),m=board[0].size();
    
    if(ind==word.size())
    return true;
    if(i>=n||i<0||j>=m||j<0||vis[i][j]==1)
    return false;

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool ans=false;
    for(int k=0;k<4;k++)
    {
        int newi=i+dx[k];
        int newj=j+dy[k];
        
            if(word[ind]==board[i][j])
            {
                vis[i][j]=1;
                ans|=fun(newi,newj,ind+1,board,word,vis);
                vis[i][j]=0;
            }
        
    }
    return ans;

}
bool exist(vector<vector<char>>& board, string word) {
    int n=board.size(),m=board[0].size();


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vector<vector<int>>vis(n,vector<int>(m,0));
            if(fun(i,j,0,board,word,vis))
            return true;
        }
    } 
    return false;
}

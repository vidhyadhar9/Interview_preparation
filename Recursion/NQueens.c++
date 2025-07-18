/*NQueens is the classical problem where we use rows and cols of the  of teh chess board 
it is the best of backtracking algorithm in this we place the Q at of the place in the chass board and look a
against the constrainst

the constraints are;
no 2 queens are to be placed in the same row, column, or diagonal
so what we do in the coding poart is we try to place in the chess board by validating the constraints and then we place on the locality where we fell 
no constarint is voilated but if we feek constraint is voilated in any on=f the oath then we revoke that queen in that lace and try to place
in suitable place if we cannot place then we will come back then we move current queen to any other place
we will try to backtrack for every impossible move and try  to get the correct place for each queen
*/













bool isPossible(vector<string>&queens,int row,int col){
    int column = col,rows=row;
    int n=queens.size();
    while(rows>=0 and column>=0){
        if(queens[rows][column]=='Q')return false;
        column--;
    }
    column=col;
    rows=row;
    while(rows>=0 and column>=0){
        if(queens[rows][column]=='Q')return false;
        rows--,column--;
    }
    rows=row,column=col;
    while(rows<n and column>=0){
        if(queens[rows][column]=='Q')return false;
        rows++,column--;
    }
    return true;
}
void Solve(vector<string>&queens,int row ,int col,int n,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(queens);
        return;
    }

    for(int i=0;i<n;i++){
        
        if(isPossible(queens,i,col)){
            queens[i][col]='Q';
            Solve(queens,i,col+1,n,ans);
            queens[i][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
        vector<string>queens;
        for(int i=0;i<n;i++){
        string s1(n,'.');
        queens.push_back(s1);
        }  
        vector<vector<string>>ans;
        Solve(queens,0,0,n,ans);
        return ans;
}

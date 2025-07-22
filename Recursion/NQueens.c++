/*NQueens is the classical problem where we use rows and cols of the  of teh chess board 
it is the best of backtracking algorithm in this we place the Queen at of the place in the chess board and look a
against the constraints

the constraints are;
no 2 queens are to be placed in the same row, column, or diagonal
so what we do in the coding part is we try to place in the chess board by validating the constraints and then we place on the locality where we feel
no constraint is violated but if we feel constraint is violated in any one of the path then we revoke that queen in that place and try to place
in suitable place if we cannot place then we will come back then we move current queen to next place
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

/*

questions :
in this we will be given n dice of m faces ,and faces are numbered from 1->m
and we will be given some target x
we need to find no of ways to get that target by using the values of the dice

Approach -->we need to check all the possibilities for each dice 

as we are checking for each dice face we can use recursion

-->if we use recursion the tc m^n as for each dice we are checking for m faces and we have n dices
but we can optimize it using dp 
lets say there were 3 dice 

1st --1
2nd dice value is 2
3rd dice value is 1,3,x-3
4th dice value is 1,2,x-2
5th dice value is 1,2,x-2

1st -->2
2nd -->1
3rd -->1 x-3

4th -->1,2,x-2
5th -->1,2,x-2



we can use the dp to store the previous explorations and return the stored value

(n*x)*m-->tc 


*/



//solution :

class Solution {
  public:
    int Ways(int m,int n,int x,vector<vector<int>>&dp){
        
        if(n==0)return x==0;
        
        if(dp[n][x]!=-1)return dp[n][x];
        
        int ans = 0;
        
        for(int i=1;i<=m;i++){
            ans += Ways(m,n-1,x-i,dp);
        }
        return dp[n][x]= ans;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return Ways(m,n,x,dp);
    }
};

/* questions states that we will be given k number of eggs 
we need to find the minimum number of steps to find the floor 
f from which if we drop an egg it will be broken

so in test cases we will be given with k eggs and a building of n floors

we need to determine the minimum steps we required to find the floor f with given k
*/



/*
approach :
as there were 2 possiblilities for every drop either it will be broken or not

in simple language we can use recursion as there were 2 possibilities for every drop either it will be broken or not

for example if we had only 1 egg then we need to explore all floors from 1 to n


so we have to explore all the possibilities and we need to find minimum steps ans from them

constariants 1<=k;

*/




//solution

int findMinimumSteps(int n,int k){

    if(k==1)return n;//if k==1 means only one egg is present so we have to test all the floors 1 to n sequenctially
    int ans = 1e9;
    for(int i=1;i<=n;i++){
        ans = min({ans, max(1+findMinimumSteps(i-1,k-1),1+findMinimumSteps(n-i,k))})
    }
    return ans;
}


//extension for it is using dp
/*here we are finding overlapping subproblems thats why we can use the dp*/

int findMinimumSteps(int n,int k){

    vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
    return solve(n,k,dp);
}

int solve(int n,int k,vector<vector<int>>& dp){

    if(k==1)return n;//if k==1 means only one egg is present so we have to test all the floors 1 to n sequenctially
    if(n==1 || n==0)return 0;
    if(dp[k][n]!=-1)return dp[k][n];
    int ans = 1e9;
    for(int i=1;i<=n;i++){
        ans = min({ans, max(1+solve(i-1,k-1,dp),1+solve(n-i,k,dp))});
    }
    return dp[k][n] = ans;
}


//to do -->solve in more optimised way using BS on DP

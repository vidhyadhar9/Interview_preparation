/*same like whether we can make the subset with sum k or not but here we count the ways rather than true of falee*/



bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,0));
    
    dp[0][0]=1;//base case for no target for 0 elements
    
    for(int i=1;i<=arr.size();i++){
        for(int target=0;target<=sum;target++){
            int x= dp[i-1][target];
            int y=0;
            if(target-arr[i-1]>=0)
            y=dp[i-1][target-arr[i-1]];
            
            dp[i][target]=x+y;
        }
    }
    return dp[arr.size()][sum];
}
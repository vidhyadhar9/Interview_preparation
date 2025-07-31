/*we are generating the matrix which stores the targets which we can acheive and then we use that tabulation array to 
to iterate anad check for the minimum differnece of 2 separate subsets
this works fine for all positive intergers but not for negative integers*/





int minimumDifference(vector<int>& nums) {
    int sum=0;
    for(auto it:nums)sum+=it;
    vector<vector<bool>>dp(nums.size(),vector<bool>(sum+1,false));

    for(int i=0;i<nums.size();i++){
        dp[i][0]=true;
    }   
    if(nums[0]<=sum)dp[0][nums[0]]=true;

    for(int i=1;i<nums.size();i++){
        for(int target=0;target<=sum;target++){
            int x=dp[i-1][target];
            int y=0;
            if(nums[i]<=target)y=dp[i-1][target-nums[i]];
            dp[i][target]=x||y;
        }
    }
    int mini=1e9;
    for(int i=0;i<=sum;i++){
        if(dp[nums.size()-1][i])
        mini=min(abs(i-(sum-i)),mini);
    }
    return mini;
}





/* for negative and positive numbers in the array we need to write the meet in the middle code to get the correct solution
*/






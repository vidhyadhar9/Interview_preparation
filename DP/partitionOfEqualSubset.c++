/*same as sumOfSubsetEqualsToK  but here we need to calculate for the sum which is equal to the half of the total sum of array 
if we get total sum as odd then we cannot partition the array into two equal subsets
if we get total sum as even then we can check whether we can make a subset which is equal to half of the total sum
so execute the same code whether we could make totalSum/2  then if we can make we have to return true else we have to return false
*/


//recursive dp-->memorization o(n*k) , o(n*k),o(n);

bool fun(int i,int target,vector<int>&nums,vector<vector<int>>&dp)
{
    
    if(target==0)return true;
    if(i==0)return nums[0]==target;
    if(dp[i][target]!=-1)
    return dp[i][target];
    bool take=false;
    if(nums[i]<=target)
    take = fun(i-1,target-nums[i],nums,dp);
    bool nott=fun(i-1,target,nums,dp);
    return dp[i][target]=nott|take;
    
}
bool canPartition(vector<int>& nums) {
    int s=0,n=nums.size();
    
    for(int i=0;i<nums.size();i++)
    s+=nums[i];
    vector<vector<int>>dp(n+1,vector<int>(s/2+1,0));
    if(s&1)return false;
//base case for tabulation
int target=s/2;
return fun(0,target,nums,dp);
}







//tabulation method -->tc O(n*k) ,space -> O(n*k)
bool canPartition(vector<int>& arr) {
int totalSum = 0;
for(int num : arr) {
    totalSum += num;
}

if(totalSum % 2 != 0) return false; // If total sum is odd, cannot partition

int target = totalSum / 2;

vector<vector<bool>> dp(arr.size() + 1, vector<bool>(target + 1, false));

for(int i=0;i<arr.size();i++)dp[i][0]=1;

for(int i=0;i<arr.size();i++){
    if(target>=arr[i])dp[i][arr[i]]=1;
}

for(int i=1;i<arr.size();i++){
    for(int j=0;j<=target;j++){
        int x= dp[i-1][j];
        int y=0;
        if(j-arr[i]>=0) {
            y = dp[i-1][j-arr[i]];
        }
        dp[i][j] = x || y;
    }
}
return dp[arr.size() - 1][target];
}


/*
Given an array of integers and a target sum, find all whether we can make at least one subset which equals to target
we can solve this in o(2^n) time complexity using recursion
where n is the number of elements in the array

we can observe the overlapping subproblems in this problem
so we can use dynamic programming to solve this problem in O(n*k) time complexity
where n is the number of elements in the array and k is the target sum

tc -> O(n*k) ,space -> O(n*k) +o(n)
to reduce o(n) stack space we can use tabulation method

while doing tabluation we need think about the base case 
and then about the loops from where it is going to start and end
and also about the transitions

as we are taking dp[n][k] as the table
we need to think when we reach index o and arr[0]==k then we should mark as true
since dp[0][0] may not occur so but at index 0  the sum may remain the arr[0]
so we neeed to check if arr[0] == k then we should mark dp[0][arr[0]] as true
*/




class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,0));
        
        for(int i=0;i<arr.size();i++){
            dp[i][0]=1;
        }
        for(int i=0;i<arr.size();i++){
         if(arr[i]<=sum) dp[i][arr[i]]=1;
        }
        for(int i=1;i<arr.size();i++){
            for(int target=1;target<=sum;target++){
                int x= dp[i-1][target];
                int y=0;
                if(target-arr[i]>=0)
                y=dp[i-1][target-arr[i]];
                
                dp[i][target]=x|y;
            }
        }
        return dp[arr.size()-1][sum];
    }
};



/*tc -> O(n*k) ,space -> O(n*k) */
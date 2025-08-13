/*
Given an array of N integers, you have to find if it is possible to partition the array with following rules:

Each element should belong to exactly one partition.
Each partition should have atleast K elements.
Absolute difference between any pair of elements in the same partition should not exceed M.

ex :
N = 5
K = 2
M = 3
A[] = {8, 3, 9, 1, 2}



here it stating about the partition and for every element had 2 chances to stay in any of the partitioned array 
according to the constraint the difference between every element in the partitioned array should be less than the 
<=M

so if we track the minimum and maximum numbers in that partitioned array we can check whteher they are in good partition or not 

so to make it easy we can sort them anyway we are using subsequence 
so we can pick the elements randomely
but by doing sorting we can find the diffecence eaily

for given example the sorted array will be {1, 2, 3, 8, 9}

then we can partition the array anyway we can know the min and max easily 
the partions could be 1,2 and 3,8,9 nut 9-3 >M
so we can not take this partition
and other partitioned could be 1,2,3 and 8,9 where the M and K are satisfied

so we can partition the whole array so we can return true

as every element had 2 chances (approx) then tc will be like 2^n and each element runs loop which could be upto n(worst cases
)
then tc will o(2^n *n) and space could be stack space o(n);

and then for the implementation we can use dp or backtracking


to optimise this we can use the DP which could reduce the tc to o(n*n)

*/



// solution 


// User function Template for C++

class Solution {
  public:
    bool Partition(int n,int k,int m,vector<int>&arr,int last_index,vector<int>&dp){
        if(last_index==n)return true;
        int ans = false;
        if(dp[last_index]!=-1)return dp[last_index];
        for(int i=last_index;i<n;i++){
            if(i-last_index+1>=k and arr[i]-arr[last_index]<=m){
               ans |=Partition(n,k,m,arr,i+1,dp); 
            }else if (arr[i]-arr[last_index]>m)break;
        }
        return dp[last_index]=ans;
    }
    bool partitionArray(int N, int K, int M, vector<int> &A) {
        // code here
        
        sort(A.begin(),A.end());
        vector<int>dp(N+1,-1);
        return Partition(N,K,M,A,0,dp);
    }
};
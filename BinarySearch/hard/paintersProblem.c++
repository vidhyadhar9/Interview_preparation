/*
Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).


as we are discussing minimizing the max time taken by the each painter we 
can do the binary search as we are minimizing the maximum time taken by the painter we can do the binary search on the time and check whether we can paint all the boards in that time or not if we can then we will try to minimize it more by moving to the left half of the search space otherwise we will move to the right half of the search space


*/


//solution :

class Solution {
  public:
    bool check(vector<int>&arr,int k,int limit){
        int sum =  0;
        for(int i=0;i<arr.size();i++){
            if((arr[i]+sum)>limit){
                k--;
                sum=arr[i];
            }else sum+=arr[i];
        }
        return k>0;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        
        long long maxi=  0,sum=0;
        for(auto it:arr){
            maxi=max(maxi,it*1ll);
            sum+=it;
        }
        long long left = maxi,right = sum;
        int ans = sum;
        while(left<=right){
            long long mid = (left+right)/2;
            if(check(arr,k,mid)){
                ans=min(ans*1ll,mid);
                right=mid-1;
            }else left=mid+1;
        }
        return ans;
    }
};
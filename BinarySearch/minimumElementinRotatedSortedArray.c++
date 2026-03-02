/*
you will be given an array which is sorted and rotated by some times
you need to find the minimum element from that array

solution:
we can do the linear search which could result us around o(n)

2nd approach :
use binary search the trick here is we need to find the sorted part and tarck the minimum from the sorted elements and then move to the other half because of the uncertanity there
will be chance of the minimum element in the mid of the other part 
so we will element the soreted part after checking the 1st element in the sorted part is minimum or not and 
we will repeat this by element the sorted half


*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = 1e9;
        int left =0,right= nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[left]<=nums[mid]){
                mini=min(mini,nums[left]);
                left=mid+1;
            }else {
                mini=min(mini,nums[right]);
                right=mid;
            }
        }
        return mini;
    }
};
/*
You will be given an array which is sorted intially by rotated by left or right side ,we will need to find the 
element in that rotated sorted array

soution :
in first case we can do the linear search which could result us around o(n)

in second case we will do bs where we will divide an existing part of the array into  half and check whether 
the left element is less thean the right if so we will check whether the element lies in it or it 
if so we will eleminate the other half 
if not we will eleminate this half and check in the other half
we will repeat it until we find the result or else return -1;

*/



class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0,right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target)return mid;
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target and target<nums[mid]){
                    right=mid-1;
                }else left=mid+1;
            }else {
                if(nums[mid]<target and target<=nums[right]){
                    left=mid+1;
                }else right=mid-1;
            }
        }
        return -1;
    }
};
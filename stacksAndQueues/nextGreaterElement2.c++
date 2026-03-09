/*

in next greater element we will be using stack as the direct data structure which can help us to track the next
greater element 

but in this question it is extension to that question here the array can do cyclic rotations to get the next greater element

approach:
create a new array with around double times the given array ans store the array 2 times
and do next greater element directly then we can see the next greater element 

we can store the answer in next array by iteranting upto n size rather 2*n 



*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>newarr(2*nums.size()),ans(nums.size());

        for(int i=0;i<newarr.size();i++){
            newarr[i]=nums[i%nums.size()];
        }
        stack<int>st;
        for(int i=newarr.size()-1;i>=0;i--){
            while(st.size() and st.top()<=newarr[i])st.pop();
            if(st.size()==0){
                st.push(newarr[i]);
                newarr[i]=-1;
            }else {
                int newele = newarr[i];
                newarr[i]=st.top();
                st.push(newele);
            }
        }

        for(int i=0;i<nums.size();i++){
            ans[i]=newarr[i];
        }
        return ans;

    }
};
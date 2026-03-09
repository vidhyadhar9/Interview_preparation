/*
problem here we need to find how much water is being stored in between pillars we need to count overall total water 
being stored

approach :
brute :find left and right side next greater ones and subtract the height of the piller from the min of the 
left and right side elements iff both exists


optimization :
rather than looping each time to resuce o(n^2) to o(n) we need next greater elements arrays from left side and right like
prefix and suffix

then we can solve it in o(n,n);

optimal ;
use 2 pointers from left and right 


*/


//optimal solution ;
class Solution {
public:
    int trap(vector<int>& height) {
       int length=height.size();
       int left=0,right= length-1;
       int max_left=height[left],max_right=height[right];
       long long sol=0;
       while(left<=right){
            if( height[left]<height[right] ){
                if( max_left<=height[left] ){
                    max_left=height[left];
                }
                else
                sol+=max_left-height[left];
                left++;
            }
            else{
              if( max_right<=height[right] ){
                    max_right=height[right];
                }
                else
                sol+=max_right-height[right];
                right--;  
            }
       }
       return sol;
    }
};




//expected next greater element way:
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>pf(height.size(),0);
        vector<int>sf(height.size(),0);

        pf[0]=height[0];
        for(int i=1;i<n;i++)
        {
            pf[i]=max(height[i],pf[i-1]);
        }
        
        sf[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sf[i]=max(height[i],sf[i+1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int mh=min(pf[i],sf[i]);
            ans+=mh-height[i];
        }
        return ans;
    }
};
/*
Given a string s, the task is to find the minimum number of cuts
 needed for palindrome partitioning of the given string. A partitioning 
of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
*/




// solution

// User function Template for C++

class Solution {
  public:
    bool isValid(string &s,int start,int end){
        string substrin = s.substr(start , end-start+1);
        string s2= substrin;
        reverse(s2.begin(),s2.end());
        return s2==substrin;
    }

    int Partition(string &s,int ind,vector<int>&dp){
        if(ind==s.size())return 0;
        int mini = 1e9;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<s.size();i++){
            if(isValid(s,ind,i)){
                mini= min(Partition(s,i+1,dp)+1,mini);
            }
        }
        return dp[ind]=mini;
    }
    int palPartition(string &s) {
        // code here
        vector<int>dp(s.size()+1,-1);
        return Partition(s,0,dp)-1;
    }
};




/*
its tc would be like o(n^3) in dp in recursion it could be for every char has possibility so it could 2^n*o(pali)*n
and space will be o(n) for dp and o(n) for recursion stack

if we calculate the  palidrome earlier then we can reduce the tc to o(n^2)


*/
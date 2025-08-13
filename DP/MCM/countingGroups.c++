/*Here we will be given a string with numbers we need to calculate the no.of ways we can separate the groups
such that the Immediate next groups sum should be greater than or equal to this current sum


for ex: 1119

we can form groups 1|1|1|9 , 1|1|19 , 11|19,1|119,1|11|9 , 111|9,1119

so as we are doiong partioning in the string and doing manipulation we can use recrsion to split it in multiple ways 

but using recursion could cause us the tc which could be equal to 2^n as we have 2 chances for every index
which may give TLE over n>=32

so we can go for DP because there were chances for the overlapping subproblems

how can we see subproblems

see you had chance to place the partition at every index so we may get a chance which might have solved before

see for example 1119 -->1|11|91|1,11|1|91|1
see 2 ecapmples if you have solved a subproblem from 2nd partition in first string then u can easily use in the second one
so as there were overlappings we can use the dp

as we need to track the lastsum we might need 2d dp which could be tc of maxsum*n

*/


// code


class Solution {
  public:
    int Count(string &s,int ind ,int prevSum,vector<vector<int>>&dp){
        //Base case
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind][prevSum]!=-1)return dp[ind][prevSum];
        int cursum = 0;
        int ans = 0;
        for(int i=ind;i<s.size();i++){
            cursum += s[i]-'0';
            if(cursum>=prevSum)ans+= Count(s,i+1,cursum,dp);
        }
        return dp[ind][prevSum]=ans;
    }
    int TotalCount(string str) {
        // Code here
        int sum = 0;
        for(auto it:str){
           sum+=it-'0'; 
        }
        vector<vector<int>>dp(str.size()+1,vector<int>(sum+1,-1));
        return Count(str,0,0,dp);
    }
};
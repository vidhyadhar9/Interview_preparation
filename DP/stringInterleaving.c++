/*In string interleaving they will give 3 strings we need to check is it possible to make a 3rd string using other 2 by 
interleaving them. For example, if we have strings "abc" and "def", we can form "adbcef" by interleaving the characters.

Approach 1 : it can be solved using backtracking ,as we had 2 chances if it s1[index] matched with s3[index] then we will move both the indexes
and similarly if s2[index] matched with s3[index] then we will move both the indexes
if any of the string returned true then we will return true

s1 = abc and s2 = def s3=abdecf


        here we start with 0,0,0
    
        at first we compare s1[index] with s2[index]
        so here s1[0]==s3[0] so we will move forward 
        then  indexes will be 1,0,1
        the s1[1] and s3[1]-->b==b then move indexes
        now we have 2,0,2;
        the s1[2] is c and s2[0] is d and s2[2] is d
        so we will move check s1 and s3 as they are not matching we will move to s2 and s3 and they are matching so we will 
        move to 2,1,3
        then check for other parts too and compare and move the indexes if they wont return true move in other way
        if(s1[i] == s3[k] && s2[j] == s3[k]){
            return backtrack(s1,s2,s3,i+1,j,k+1) || backtrack(s1,s2,s3,i,j+1,k+1);
        }
        else if(s1[i] == s3[k]){
            return backtrack(s1,s2,s3,i+1,j,k+1);
        }
        else if(s2[j] == s3[k]){
            return backtrack(s1,s2,s3,i,j+1,k+1);
        }
        return false;
    }

approach -2
    as there is overlapping subproblems we can use the memoization technique to store the results of subproblems and avoid redundant calculations.


*/


class Solution {
public:
    bool Interleave(int s1_index, int s2_index, int s3_index, string& s1,
                    string& s2, string& s3, vector<vector<int>>& dp) {
        if (s1.size() == s1_index and s2.size() == s2_index and s3_index == s3.size())
            return true;
        if (s1_index == s1.size() and s2_index == s2.size())
            return false;
        if (dp[s1_index][s2_index] != -1)
            return dp[s1_index][s2_index];
        int firststring = false, secondstring = false;
        if (s1.size() > s1_index and s1[s1_index] == s3[s3_index])
            firststring = Interleave(s1_index + 1, s2_index, s3_index + 1, s1,s2, s3, dp);
        if (s2.size() > s2_index and s2[s2_index] == s3[s3_index])
            secondstring = Interleave(s1_index, s2_index + 1, s3_index + 1, s1,s2, s3, dp);
        return dp[s1_index][s2_index] = firststring || secondstring;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return Interleave(0, 0, 0, s1, s2, s3, dp);
    }
};

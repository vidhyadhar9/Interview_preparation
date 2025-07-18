
bool valid(string &s,int i,int j, unordered_map<string,int>&mp){
    string sub=s.substr(i,j-i+1);
    if(mp[sub])return true;
    return false;
}
int checkWord(string &s,int ind,vector<string>& wordDict,unordered_map<string,int>&mp){
    if(ind==s.size())return true;

    for(int i=ind;i<s.size();i++){
        if(valid(s,ind,i,mp)){
            if(checkWord(s,i+1,wordDict,mp))return true;
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,int>mp;
    for(auto it:wordDict)mp[it]=1;
    return checkWord(s,0,wordDict,mp);  
}




/*its almost like palindrome partioning where we use complete backtracking where we place the segment or divide the string
and then check whether we are getting the valid segmentation or not
if once we reach the last word of the string then we can say we have achieved atleast one separation
where we can return true from there */

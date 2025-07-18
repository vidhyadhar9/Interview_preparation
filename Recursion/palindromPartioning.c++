/*Given a string s, partition s such that every substring of the partition is
a palindrome. Return all possible palindrome partitioning of s.*/


//Approach:
/*we have to partion the string into substring where every substring is a palindrome
As we know if we check for one aplindroma and then move for otehr one by one we may not get all substring as palindrome
so trying out all possible ways is better approach for that we need to try every path from each string so we can try multiple ways to create a vector <strin>where evru
string is a palindrome*/


bool isPalindrome(string &s,int first,int count){
string sub = s.substr(first,count);
string s2=sub;
reverse(s2.begin(),s2.end());
cout<<s2<<" "<<sub<<endl;
return s2==sub;
}
void Partition(string &s,vector<string>&v1,vector<vector<string>>&ans,int ind){

    if(ind==s.size()){
        ans.push_back(v1);
        return ;
    }

    for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i-ind+1)){
            string sub=s.substr(ind,i-ind+1);
            v1.push_back(sub);
            Partition(s,v1,ans,i+1);
            v1.pop_back();
        }
    }

}
vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string>v1;
    Partition(s,v1,ans,0);
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<vector<string>>result = partition(s);
    for(auto &v : result){
        for(auto &str : v){
            cout << str << " ";
        }
        cout << endl;
    }

}


//its way to solve the problem using recursion and backtracking
//time complexity is O(2^n) where n is the length of the string
//space complexity is O(n) for the recursion stack and the storage of results
//this is a brute force approach and can be optimized further using dynamic programming

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
       sort(s.begin(),s.end());
       int l=s.size();
       string n=s[0],m=s[l-1];
       string ans="";
       for(int i=0;i<n.size();i++)
       {
           if(n[i]==m[i])
                ans+=n[i];
                else
                break;
       }
       return ans;
    }
};


/*
lonest common prefix be minimum string among the given array if it matches with all other strings
they mention there should common prefix of every string so we have to comapre with lexigrophically largest and smaklest strings
here i have soreted rather than that we can you min and strings by tracking by iterating through the arrray and then comparing both of them and
return the common prefix taht will be maximum llongest common prefix among the arrau of strings*/
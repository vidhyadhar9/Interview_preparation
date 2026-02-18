class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.size();
        while(i<n and s[i]==' ')i++;        
        int j=n-1;
        while(j>=0 and s[j]==' ')j--;
        int start=i,end=j;
        reverse(s.begin()+i,s.begin()+j+1);
        while(i<=j){
            int x=i;
            while(i<=j and s[i]!=' '){
                i++;
            }
            reverse(s.begin()+x,s.begin()+i);
            while(s[i]==' ')i++;
        }
        string s2;
        for(int i=start;i<end+1;i++){
            if(s[i]!=' ')s2.push_back(s[i]);
            else {
                while(s[i]==' ')i++;
                s2.push_back(' ');
                i-=1;
            }
        }
        return s2;
    }
};


/* tried for the inplace string but didnt pushed that ,but you can in place string reversal which decreases 
space to o(1) and here i have use o(n,n) */
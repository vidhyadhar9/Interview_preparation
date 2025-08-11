class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //explore all paths from 'a' to 'z' for every charachter
        queue<pair<string,int>>q;
        set<string>st;
        for(auto it:wordList)st.insert(it);
        q.push({beginWord,1});
        int mini=1e9;
        while(q.size()){
            string word=q.front().first;
            int count = q.front().second;
            if(word==endWord)
            mini=min(mini,count);
            q.pop();
            for(int i=0;i<word.size();i++){
                string orginal=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,count+1});
                    }
                }
                word=orginal;
            }
        }
        if(mini==1e9)return 0;
        return mini;
    }
};
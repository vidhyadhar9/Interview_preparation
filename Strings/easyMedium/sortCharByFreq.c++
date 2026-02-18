/*
here we are using the priority queue to sort the characters by their frequency
intially we will calculate teh characters and their frequesncies using map which causes us n*logn freq
and then we will be using priority queue to sort the characters by their frequencies
Time Complexity: O(nlogn)-->atmost 52*log(52) as there were only 52 characters in a-z and A-Z
Space Complexity: O(52)
later we will be access the character and later we will be inserting the character as we using count and character which could overall take o(n)
and space Complexity: O(n)
*/

//over tc-->o(n*log(n)+n) and sc-->o(n)



//Approach 1 

string frequencySort(string s) {
    string solution;

    map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    priority_queue<pair<int,char>>pq;
    for(auto it:mp){
        pq.push({it.second,it.first});
    }

    while(pq.size()){
        int count = pq.top().first;
        int ch = pq.top().second;
        pq.pop();
        for(int i=0;i<count;i++){
            solution.push_back(ch);
        }
    }
    return solution;

}






//Approach -2 

//directly sort the string based on frequency and then access the o(52*log(52)) and space o(52 ) and space o(n+n)

string frequencySort(string s) {
    string solution;
    map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    vector<pair<int,char>>freq;
    for(auto it:mp){
        freq.push_back({it.second,it.first});
    }
    sort(freq.begin(),freq.end(),greater<pair<int,char>>());
    for(auto it:freq){
        for(int i=0;i<it.first;i++){
            solution.push_back(it.second);
        }
    }
    return solution;

}
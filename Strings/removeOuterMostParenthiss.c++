class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<pair<char,int>>st;
        string s2;
        vector<int>arr(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(s[i]==')' and st.size()==1){
                arr[st.top().second]=1;
                st.pop();
                arr[i]=1;
            }
            else if(s[i]=='(')st.push({'(',i});
            else if (s[i]==')' and st.size()>1){
                st.pop();
            }
        }   
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1)continue;
            else s2.push_back(s[i]);
        }
        return s2;
    }
};

/*removing outer most parenthesis could be solved using stack ny marking the locations of which place we have to elemeniate by using the 
stack size
if the stack size is 1 and if we encounter ')' then we to mark boht '(' and ')' and pop the char from the stack andthe
we have to store the lcation of the character in the array and then we can iterate through the array and
remove the characters which are marked as 1 in the array and return the string
this is a o(n) solution and space complexity is o(n) as we are using the stack and array to store the locations
This is a simple and efficient way to remove the outermost parentheses from a string.

time complexity could be o(n) and space complexity is o(n) as we are using stack and array to store the locations
*/
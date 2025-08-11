/* in this we will be give a matrix we need to find the maximum number of 1's appeared in the rectangle form

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

lets we have given this matrix then the answer will be 6 ,as we can form a rectangle of 1's with height 1 and width 3.
so to do this we need to solve area under the histogram problem which is similar to it but we will be using next smallest and 
previous smallest element

Approach :

here we will be caluculating the prefix maxtri which can be appeared like this

1 0 1 0 0
2 0 2 1 1
3 1 3 2 2
4 0 0 3 0

we will caluclute area under the histogtram for evry row 
here the area under the histogram 

area under the histogram
 here we will be given a linear array with heights of the bars
 from that heights we need to calculate the maximum rectangular area
 so if we have heights = [2,1,5,6,2,3] then the maximum rectangular area will be 10
 for example area of the rectangle of 2 is 2*1 = 2 and 2*4 = 8 and 
 area of height 1 is 1*6 =6 and area of the 4 will 4*2 =8 and 5*2 =10 and 6*1 =6;

 similarly conside each row as the heights and cakculate the heights for each maxtrix we will get the maxi result 
 return that one as answer

the time complexity will be o(n*m)+o(n*m), and space will be o(2*m+n*m);

*/


// Solution

class Solution {
public:
    int findMaxi(vector<int>&v,int cols){
        vector<int>prefix(cols,0),suffix(cols,0);
        int n= cols;
        stack<int>st;
        for(int i=0;i<cols;i++){
            while((!st.empty()) and v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty())prefix[i]=-1;
            else prefix[i]=st.top();
            st.push(i);
        }
        while(st.size())st.pop();
        for(int i=n-1;i>=0;i--){
            while((!st.empty()) and v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty())suffix[i]=n;
            else suffix[i]=st.top();
            st.push(i);
        }

        // for(int i=0;i<n;i++)cout<<prefix[i];
        // cout<<endl;
        // for(int j =0;j<n;j++)cout<<suffix[j];


        

        int maxi =0 ;
        for(int i=0;i<n;i++){
            maxi = max(maxi, v[i]*(suffix[i]-prefix[i]-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() ,m = matrix[0].size();
        vector<vector<int>>prefix(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0)prefix[i][j]=matrix[i][j]-'0';
                else prefix[i][j]=matrix[i][j]=='0'?0:prefix[i-1][j]+matrix[i][j]-'0';
            }
        }   

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<prefix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,findMaxi(prefix[i],m));
        }
        return maxi;


    }
};
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int>dis(100000,1e9);
        dis[start]=0;
        while(q.size()){
            int steps=q.front().first;
            int node = q.front().second;
            q.pop();
            for(int i=0;i<arr.size();i++){
                int num = (node*arr[i])%100000;
                
                if(dis[num]>steps+1){
                    if(num==end)return steps+1;
                    q.push({steps+1,num});
                    dis[num]=steps+1;
                }
                
            }
        }
        return dis[end]==1e9?-1:dis[end];
    }
};



/*Here reached every step would be consider as a node adn from there we will consider it as a graph
we will find the minimum number of steps rewuired to reach teh end as they provide the module number then the max number 
of nodes will 1 less than the actual nodes
TC-->(100000*arr.size()) hypothetical

here we have used the queue instead of the pq because any way we are going step by step so there is no need of PQ
which reduced log(100000) TC
space could be around 10000 as it we consier graph node in the queue* /
/*
here we will be given fixed matrix size and number of snakes and ladders

and their positions

we need to return the minimum number of moves to reach from 1 to n*m

Approach 1:
we will be using BFS to solve this we will try to explore the chances from 1 t0 6 for every position and 

and we have ladder we are going to clib if not we will be going to the same position
if we had snake we will be moving down

the positions will be given in an array as ladders and snakes



*/

//solution 


// User function Template for C++

class Solution {
  public:
    int minThrow(int N, int arr[]) {
        // code here
        vector<int>game(31);
        int c =1;
        for(int i=1;i<31;i++){
            game[i]=c++;
        }
        
        for(int i=0;i<2*N;i+=2){
            game[arr[i]]=arr[i+1];
        }
        
        queue<pair<int,int>>q;
        q.push({1,0});
        vector<int>vis(30+1,0);
        
        // for(int i=0;i<31;i++)
        // cout<<game[i]<<" ";
        
        while(q.size()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            vis[node]=1;
            node = game[node];
            vis[node]=1;
            if(node==30)return steps;
            
            for(int i=1;i<=6;i++){
                if(node+i<=30 and vis[node+i]==0)
                q.push({node+i,steps+1});
            }
        }
        return -1;
        
    }
};
//course has to be completed using topological sorting
#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       //detecting cycle or not 
    vector<int>indegree(numCourses,0);

    for(auto it:prerequisites)
    {
        indegree[it[0]]++;
    }
    queue<int>q;
    for(int i=0;i<numCourses;i++)
    {
        if(indegree[i]==0)
        q.push(i);

    }
    vector<int>ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:prerequisites)
        {
        if(it[1]==node)
        {
            indegree[it[0]]--;
            if(indegree[it[0]]==0)
            q.push(it[0]);
        }
        }
    }
    return  ans.size()==numCourses;

}






vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
       //detecting cycle or not 
       vector<int>indegree(numCourses,0);

       for(auto it:prerequisites)
       {
            indegree[it[0]]++;
       }
        queue<int>q;
       for(int i=0;i<numCourses;i++)
       {
            if(indegree[i]==0)
            q.push(i);

       }
        vector<int>ans;
       while(!q.empty())
       {
         int node=q.front();
         q.pop();
         ans.push_back(node);
         for(auto it:prerequisites)
         {
            if(it[1]==node)
            {
                indegree[it[0]]--;
                if(indegree[it[0]]==0)
                q.push(it[0]);
            }
         }
       }
       if(ans.size()==numCourses)
       return ans;
       return {};

}
// This function returns the order of courses if possible, otherwise an empty vector
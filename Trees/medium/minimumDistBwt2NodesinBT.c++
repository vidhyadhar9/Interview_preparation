/*will be givem a tree to find the dist between 2 nodes 1,b 
solution found a lca and founda dist between lca to a and b individually and added to the sum

tc --> o(4*n);
sc -->o(2*n);
*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    
    bool Traverse(Node *root,int target,vector<int>&v){
        if(root==NULL)return false;
        v.push_back(root->data);
        if(root->data==target||Traverse(root->left,target,v)||Traverse(root->right,target,v))return true;
        v.pop_back();
        return false;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        vector<int>v1,v2;
        Traverse(root,a,v1);
        Traverse(root,b,v2);
        int lca = 0;
        for(int i=0;i<min(v1.size(),v2.size());i++){
            if(v1[i]==v2[i])lca=i;
            else break;
        }
        int a_dist = (v1.size()-1)-lca;
        int b_dist = (v2.size()-1)-lca;
        return a_dist+b_dist;
        
    }
};
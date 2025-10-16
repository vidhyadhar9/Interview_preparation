/*
 A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*Approach:
   1. We will use level order traversal to visit each level of the tree.
   just check for the flag whether to store front or back node of the level
*/

class Solution {
  public:
    /* Function to print nodes of extreme corners
    of each level in alternate order */
    vector<int> extremeNodes(Node* root) {
        // Your code here
        vector<int>ans;
        ans.push_back(root->data);
        queue<Node*>q;
        if(root->left)
        q.push(root->left);
        int t=1;
        if(root->right)q.push(root->right);
        while(q.size()){
            if(t)ans.push_back(q.front()->data);
            else ans.push_back(q.back()->data);
            t=!t;
            int s=q.size();
            for(int i=0;i<s;i++){
                Node *node =q.front();
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
        }
        return ans;
    }
};
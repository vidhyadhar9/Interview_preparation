/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/



/*
Approach :

use the post order traversal to calculate the maximum sum

return vectors at each phase we will store the array of size 2

1st index will store the maximum sum including the current node

2nd index will store the maximum sum excluding the current node

we will track the over all sum from the child nodes
and at the end we will try to find the max of both the indices and return it
*/

class Solution {
  public:
    vector<int> Maxsum(Node *root){
        if(root==NULL)return {0,0};
        auto l = Maxsum(root->left);
        auto r = Maxsum(root->right);
        int include = root->data+l[1]+r[1];
        int exclude = max(l[0],l[1])+max(r[0],r[1]);
        return {include,exclude};
        
        
    }
    int getMaxSum(Node *root) {
        // code here
        auto it = Maxsum(root);
        return max(it[0],it[1]);
    }
};
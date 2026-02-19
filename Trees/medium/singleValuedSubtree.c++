/* here we need to count how many subtrees existed i which the total subtree has same values 

solution : we find whether the subtree is true or not (means whether the subtree left and right subtree has same values as the root node or not ) if it is true then we will increase the count by 1 and we will return true to the parent node otherwise we will return false to the parent node
values are not along with which the left side subtree and right subtree has to satisfy the condition of single valuesd tree

*/

/* Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
  public:
   bool findScore(Node *root,int &ans){
        if(root==NULL)return true;
        auto leftside = findScore(root->left,ans);
        auto rightside = findScore(root->right,ans);
        if(leftside==false || (root->left and root->left->data!=root->data))return false;
        if(rightside==false ||(root->right and  root->right->data!=root->data))return false;
        ans++;
        return true;
        
    }
    int singlevalued(Node *root) {
        // code here
        int ans = 0;
        findScore(root,ans);
        return ans;
    }
};

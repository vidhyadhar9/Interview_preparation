/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


/*
approach caluculate the biggest BST from the given Binary tree using inorder traversal

here we will use post order traversal to calculate the largest BST

we will track the left maximum node and right minimum node and if the current node is greater than left max and smaller than right min
then we can say that the current subtree is BST

then we will try to caluclate the BST size including the current node
 if not we will return -1 which can helps to say the below suntree is not the subTree

 and at every node we will try to update the maximum size of the BST found till now
 and we also check is there any subTree on left or right which is not a BST the we return -1 if any of the left or right subtree is not a BST

 if yes we will return the maximum subtree size including the current node
 and if not we will return -1
 

*/


class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> LargestBst(Node *root,int &maxi){
        
        if(root==NULL)return {0,-1e9,1e9};
        auto left = LargestBst(root->left,maxi);
        auto right = LargestBst(root->right,maxi);
        bool x = true;
        if(root->left)x=(left[1]<root->data);
        if(root->right)x=x&&(right[2]>root->data);
        if(left[0]==-1||right[0]==-1||x==false)
        return {-1,max({right[1],root->data}),min({left[2],root->data})};
        maxi= max(maxi,left[0]+right[0]+1);
        return {left[0]+right[0]+1,max({right[1],root->data}),min({left[2],root->data})};
    }
    int largestBst(Node *root) {
        // Your code here
        int maxi =0;
        auto it=LargestBst(root,maxi);
        return max(maxi,it[0]);
    }
};
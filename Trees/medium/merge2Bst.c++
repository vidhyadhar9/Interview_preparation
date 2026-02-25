/*
    in questions multiple /2 bsts will be provided then those treees should be merged as single bsts

    questions asked to return single root it is different 
    if the question asked to return the elements its about traversal and sorting the resukt array
    o(n+m)+o(n+m) -->rather than sorting we can do it by taking extra array 

*/

//end question soltuion :
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void Traverse(Node *root,vector<int>&v){
      if(root==NULL)return ;
      Traverse(root->left,v);
      v.push_back(root->data);
      Traverse(root->right,v);

  }
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int>v;
        Traverse(root1,v);
        Traverse(root2,v);
        sort(v.begin(),v.end());//take new array and merge 2 seperate arrays 
        return v;
        
    }
};
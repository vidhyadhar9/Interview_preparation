/*Here the question asks about how many turns required to go from one node to another in a binary tree 



Approach:

if we want to travel from one node to anotehr node we need to pass from a common ancestor 
that is LCA
if we find the common ancestor then the process becomes easy
if we find the path from ancestor to the first node and similarly  for the second node
we can check the turns required
we can chcek the node path from one  node to other by check the adjacent node direction
this can be checked using the strings




here we use 2 strings to store the path from Ancestor to the first node and similarly for 2nd node and then
reverse one string and attach them and check the adjacent indexes and count the number of disimilar
edges and return the count



TC -->o(n +n) and spoace will be o(n+n+2*node)

*/







/*
Structure of the node of the tree is as follows
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution {
  public:
    // function should return the number of turns required to go from first node to
    // second node
    Node * LCA(struct Node *root,int first,int second){
        if(root==NULL)return NULL;
        if(root->data==first || root->data==second){
             return root;
        }
        Node *left = LCA(root->left,first,second);
        Node *right = LCA(root->right,first,second);
        
        if(left and right)return root;
        return left==NULL?right:left;
        
    }
    void path(Node *root,string &s,int target,vector<string>&ans){
        if(root==NULL)return ;
        if(root->data==target){
            ans.push_back(s);
        }
        s.push_back('l');
        path(root->left,s,target,ans);
        s.pop_back();
        s.push_back('r');
        path(root->right,s,target,ans);
        s.pop_back();
        
    }
    int NumberOFTurns(struct Node* root, int first, int second) {
        // Your code goes here
        //no of turn can be calculated from node to node using LCA
        //Beacuse the path should pass through the LCA
        Node *LA = LCA(root,first,second);
        vector<string>ans;
        //we traverse from the LCA node to the other nodes and oush that respective node n
        //path to ndoe
        string s1="",s2="";
        path(LA,s1,first,ans);
        path(LA,s2,second,ans);
        s1=ans[0];
        s2=ans[1];
        reverse(s1.begin(),s1.end());
        s1=s1+s2;
        if(s1.size()==0 and s2.size()==0)return -1;
        int c=0;
        for(int i=0;i<s1.size()-1;i++){
            if(s1[i]!=s1[i+1])c++;
        }
        return c?c:-1;
        
    }
};
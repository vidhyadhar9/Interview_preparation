
/*we will be given 2 trees we need to check whether the 2nd tree is subtree or first or not 
here first tree will have duplicate values

solution :
In solution we approached in this way like we will find 2nd root node value in the first tree and we will store in the 
vector and we will try to explore each and every subtree from each and every node that we have store i.e.., which is matching 
with the 2nd tree root node 

if we found atleast one subtree which is matching with the 2nd tree then we will return true otherwise we will return false
*/

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to check if S is a subtree of tree T. o(n) where n are the nodes of the 1st tree 
    // and m are the nodes of the end tree 
    //the tc will be o(n+ o(n*m)) in worst case when all the nodes of the 1st tree are same as the root node of the 2nd tree and we will have to check for each and every node of the 1st tree
    //space will be o(n)
    void findTargets(Node *root,int target,vector<Node*>&v){
        if(root==NULL)return ;
        if(root->data==target)v.push_back(root);
        findTargets(root->left,target,v);
        findTargets(root->right,target,v);
    }
    bool check(Node *root,Node *tree){
        if(root==NULL and tree==NULL)return true;
        if(root==NULL || tree==NULL)return false;
        bool leftside = check(root->left,tree->left);
        bool rightside = check(root->right,tree->right);
        if(leftside&&rightside&&(root->data==tree->data))return true;
        return false;
    }
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        vector<Node*>target;
        findTargets(T,S->data,target);
        
        for(auto it:target){
            if(check(S,it))return 1;
        }
        return 0;
        
    }
};


// tc -->o()


//the best case will be o(n) and O(KMP algo)
/* it can be solved using the preorder and inorder traversals*/
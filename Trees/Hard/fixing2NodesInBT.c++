/*In this question a Binary search tree will be given where 2 nodes will be mismatched from there position
the task is to fix the position and their values at corect place so 



Approacj:
As we Know the BST will be in ascending order if we do Inorder traversal so we will do inorder ( any one traversal) 
the  store those nodes in the vector and sort it then again iterate through the tarversal by taking the sorted vector and check whether the givem node will be exact position or not if it is in correct leave it if not assign the node 
or else what we can do is directly intailize the node into the root->data which could give us the BST without any changes

Time complexity --> O(n*log for sorting the nodes ) +O(2*n for tarversa) and space -->o(n)*/

/*
class Node
{
    public:
    int val;
    Node *left, *right;
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void Traverse1(Node * root,vector<int>&v){
        if(root==NULL)return ;
        Traverse1(root->left,v);
        Traverse1(root->right,v);
        v.push_back(root->data);
    }
    void Traverse2(Node *root,vector<int>&v,int &ind){
        if(root==NULL)return ;
        Traverse2(root->left,v,ind);
        root->data=v[ind++];
        Traverse2(root->right,v,ind);
    }
    void correctBST(Node* root) {
        // add code here.
        vector<int>v;
        Traverse1(root,v);
        sort(v.begin(),v.end());
        // for(auto it:v)cout<<it<<endl;
        int index=0;
        Traverse2(root,v,index);
    }
};





//we can do another method which could decrease the time complexity to o(n) and space will be only stack space--> optimal solutiion

//APPROACH-2

/* in 2nd approach we will be using the inorder traversal and we ill use 3 pointers to track the nodes which are
not at their specified places
this approach will be in 2 types means the nodes which are misplaced are adjacent to each other 
and other type is some distance apart
if they are adjacent we need to track prvious and current element and 
if they are distance we need to track the last non positioned node along with other mispalced node and swap them

ex-->[1,2,8,7,9,10]-->here 7 and 8 are adjacnet
ex-->[1,2,25,7,8,9,5] -->here 25 and 5 are miss placed so we need to track 3 nodes here 
first 25 and other is 7 and last node is 5
so we need to swap first and last nodes to make the valid bst
in first case we need to swap first and second as there was no last

*/



/*
class Node
{
    public:
    int val;
    Node *left, *right;
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node *first=NULL,*second =NULL,*last=NULL,*previous=NULL;
    void Traverse1(Node * root){
        if(root==NULL)return ;
        Traverse1(root->left);
        if(previous!=NULL and previous->data>root->data){
            if(second==NULL){
                first=previous;
                second=root;
            }else last=root;
        }
        previous=root;
        Traverse1(root->right);
        
        
    }
    void correctBST(Node* root) {
        // add code here.
        Traverse1(root);
        if(last==NULL){
            swap(first->data,second->data);
        }else{
            swap(last->data,first->data);
        }
       
    }
};
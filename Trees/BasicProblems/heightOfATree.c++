//Most of the tree problems can be solved using basic traversals and using some manipulation in between them

//in Height of the Tree problem we just need the max height of the tree i.e.., from root to any of the node which will be int the max depth


//to solve the basic tree problem 
    //assume if there is no node ==>if(root==NULL)return 0;
    //assume if there isonly node 
    //assume it there is left and right child to the node
    /* when you assume left and right childs then you need to call left and right sub tree function and utilize the ansers*/

//above are the basic things to keep in mind while doing Tree problems

//Time Complexity: O(N) where N is the number of nodes in the tree
//Space Complexity: O(H) where H is the height of the tree, which is the maximum depth of the recursion stack
//This is because we are using recursion, and the maximum depth of the recursion stack will be equal to the height of the tree.

int maxDepth(TreeNode* root) {
        if(root==NULL)//if noofr is null
        return 0;
        int lh=maxDepth(root->left);//left traversal
        int rh=maxDepth(root->right);//right traversal
        return 1+max(lh,rh);//manipulation
}

//we use height type of code in calculating whether tree is balanced or and and finding diameter of the tree

//code for the checking tree is balanced or not
int Balanced(TreeNode *root){
    if(root==NULL)return 0;
    int lh=Balanced(root->left);
    int rh=Balanced(root->right);
    if(lh==-1 || rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    return 1+max(lh,rh);
}


//code for the Diameter of the tree
//Diameter of the tree can be the path from any node to any other node which may not passed thtough the root node
//as we want to track the maximum among the the paths and nodes we gone throguh we will be taking maxi variable as 
//reference variable which could be helping us to track the maximum of al path at each node

int Diameter(TreeNode *root){
    if(root==NULL)return 0;
    int lh=Diameter(root->left);
    int rh=Diameter(root->right);
    maxi=max(lh+rh+1,maxi); //lh+rh+1 is the diameter of the tree at that node
    return 1+max(lh,rh); //returning the height of the tree
}



//be careful while looking at the diameter because question may be varied 
//dimaeter may be the nodes or the edges if the edges asked then maxi-1 will be the result from the above code


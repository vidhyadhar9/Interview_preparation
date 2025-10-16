/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/*

Approach :

    first create a new tree without random pointers using bfs
    then attach random pointers using bfs again
*/


class Solution {
  public:
    /* The function should clone the passed tree and return
       root of the cloned tree */
    Node* cloneTree(Node* root) {
        // Your code here
        map<Node*,Node*>mp;
        queue<Node*>q;
        Node *root2 = new Node(root->data);
        mp[root]=root2;
        q.push(root);
        while(q.size()){
            Node* node =q.front();
            q.pop();
            Node *node2 = mp[node];
            if(node->left){
                Node *leftNode = new Node(node->left->data);
                node2->left=leftNode;
                mp[node->left]=leftNode;
                q.push(node->left);
            }
            if(node->right){
                Node *rightNode = new Node(node->right->data);
                node2->right = rightNode;
                mp[node->right]=rightNode;
                q.push(node->right);
            }
            
        }
        
        
        //attaching randome pointers
        
        while(q.size())q.pop();
        
        q.push(root);
        
        while(q.size()){
            Node * node = q.front();
            q.pop();
            Node * node2 = mp[node];
            if(node->random){
                Node *ran = mp[node->random];
                node2->random = ran;
            }
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return root2;
        
    }
};
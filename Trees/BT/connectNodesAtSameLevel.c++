/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

*/

/*

Approach-1: as we want next node we can do level order traversal and keep track of nodes at each level in a vector and then connect them
*/

class Solution {
  public:
  //tc will be o(n) and space will be o(n);
    Node* connect(Node* root) {
        // code here
        queue<Node*>q;
        q.push(root);
        vector<Node*>v;
        while(q.size()){
            int s= q.size();
            for(int i=0;i<s;i++){
                Node* node = q.front();
                v.push_back(node);
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
            for(int i=0;i<s-1;i++){
                v[i]->nextRight=v[i+1];
            }
            v.clear();
            
        }
        return root;
    }
};
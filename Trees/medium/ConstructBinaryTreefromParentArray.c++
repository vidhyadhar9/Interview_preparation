/*here the question provides the parent array with the root elment which has the -1 value in the array 
here the array consists of index values are the elements and values of the array are the parents of that respent index element

solution : first found root element and as well as mapped the child elemets to the parent element ans constructed the 
tree using level order traversal

*/


/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* createTree(vector<int>& parent) {
        // code here
        vector<vector<int>>mp(parent.size());
        queue<Node*>q;
        Node *parentNode=new Node(-1);
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1){
                parentNode->data = i;
                q.push(parentNode);
            }else 
                mp[parent[i]].push_back(i);
        }
        
        while(q.size()){
            Node *node = q.front();
            q.pop();
            for(auto it:mp[node->data]){
                Node *newNode = new Node(it);
                if(node->left==NULL)node->left=newNode;
                else node->right = newNode;
                q.push(newNode);
            }
        }
        return parentNode;
    }
};

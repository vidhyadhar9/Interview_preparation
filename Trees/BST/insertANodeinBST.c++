/*we will begiven nodes in the array we need to insert the elements as BST 
While doing traversal from left to right in the array always try to find the better 
suitable position for each element
It can be found by comparing the element with the root node
if the root element is greater than the inserting element then we will go to the left subtree
if the root element is less than the inserting element then we will go to the right subtree
if the root element is equal to the inserting element then we will not insert it as BST does
if we move to null pointer then we will insert the element there

*/


#include <iostream>
using namespace std;
//struct node is main impt always keep this struct in your brain while writing code for the Trees because 
//interviewers may not give you TreeNode directly to you

struct Node {
    int data;
    Node* left;
    Node* right;
};

//just assume there is only one node and we need to insert another node in the BST
//we will return the root node after inserting the new node

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}


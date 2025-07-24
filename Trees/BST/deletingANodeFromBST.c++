/*Deleting a node for the Tree is one of the nice problem to understand rather than deleting the tree node and making it 
complicated always try to find the ndoe and then left left trees maxnode and then replaece the node value with left side
maximum and then try to delete left maximum in its left subtree 
by that we wont delete the node but we are replacing the deleting value with the left maximum value and then 
deleting the left maximum value from left subtree as it is duplicated
*/



void deleteNode(Node*& root, int data) {
    if (root == nullptr) {
        return;
    }
    
    if (data < root->data) {
        return deleteNode(root->left, data);
    } else if (data > root->data) {
        return deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            root = temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = root->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }
            
            // Copy the inorder successor's content to this node
            root->data = temp->data;
            
            // Delete the inorder successor
            deleteNode(root->right, temp->data);
        }
    }
}
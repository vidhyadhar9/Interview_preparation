/*
LRU cache implementation;

here we will get the key from the user if it existed in the lru we will return it by changing its postion 
to checnge it position we first remove the existed node i..e, we will  delete node at that postion and place after the head

and 2nd one is inserting the new node here we will face lot of edge cases

1st check whether existed or not if so just as it is in get like removing the node and placing the after the head
else chack for teh capacity if so delet the lru that is at the last node before node and place the new node at the after the head and add it in the map as well as remove the lru from  the mp and delet the node to remove the memory leak
after node rmoving new node has to place at the after the head
and add to the map

*/


class Node {
public:
    int key, value;
    Node *left, *right;
    Node(int k, int v) {
        key = k;
        value = v;
        left = right = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    Node *head, *tail;
    map<int, Node*> mp;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->right = tail;
        tail->left = head;
    }

    void remove(Node* node) {
        Node* prev = node->left;
        Node* next = node->right;
        prev->right = next;
        next->left = prev;
    }

    void changePosition(Node* node) {
        node->right = head->right;
        node->left = head;
        head->right->left = node;
        head->right = node;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        remove(node);
        changePosition(node);
        return node->value;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            changePosition(node);
            return;
        }

        if(mp.size() == capacity) {
            Node* lru = tail->left;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        changePosition(newNode);
        mp[key] = newNode;
    }
};
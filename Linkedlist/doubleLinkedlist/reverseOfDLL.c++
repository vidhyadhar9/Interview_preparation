class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node * prev=NULL,*cur=head,*temp=NULL;
        while(cur){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
};
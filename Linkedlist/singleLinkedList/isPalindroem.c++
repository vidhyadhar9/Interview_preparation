/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * findMid(ListNode * head){
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    void reverse(ListNode *mid){
        ListNode *prev=NULL,*cur=mid->next,*temp=NULL;
        while(cur){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        mid->next=prev;

    }
    bool isPalindrome(ListNode* head) {
        //find mid 
        //reverse it
        //then cehck the first and mid+1 nodes
        ListNode *mid = findMid(head);
        reverse(mid);
        // ListNode *temp3= head;
        // while(temp3){
        //     cout<<temp3->val;
        //     temp3=temp3->next;
        // }
        ListNode *temp1 = head,*temp2 = mid->next;
        while(temp1 and temp2){
            if(temp1->val !=temp2->val)return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};
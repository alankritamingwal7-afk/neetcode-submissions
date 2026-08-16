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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL && n==1){
            return NULL;
            delete head;
        }
        // will find the length of linked list 
        ListNode* curr = head;
        int len = 0;
        while(curr){
            len+=1;
            curr=curr->next;
        }
        // itrate till len-n;
        int pos = len-n;
        if(pos==0){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        // traverse thr node before the target
        curr = head;
        for(int i=1; i<pos;i++){
            curr=curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;

        
    }
};

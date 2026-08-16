class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        stack<ListNode*> st;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // Step 1: Push k nodes into stack
            int count = 0;
            ListNode* temp = curr;
            while (temp && count < k) {
                st.push(temp);
                temp = temp->next;
                count++;
            }

            // Step 2: If fewer than k nodes remain, connect as-is and break
            if (count < k) {
                prev->next = curr;
                break;
            }

            // Step 3: Pop nodes from stack to reverse
            while (!st.empty()) {
                prev->next = st.top();
                st.pop();
                prev = prev->next;
            }

            // Step 4: Connect to next group
            prev->next = temp;
            curr = temp;
        }

        return dummy->next;
    }
};

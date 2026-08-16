class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap based on node value
        priority_queue<pair<int, ListNode*>, 
                       vector<pair<int, ListNode*>>, 
                       greater<pair<int, ListNode*>>> pq;
        
        // Step 1: Push the head of each list into the heap
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        
        // Dummy node to build result
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        
        // Step 2: Extract min and build merged list
        while(!pq.empty()) {
            auto it = pq.top();   // smallest node
            pq.pop();
            
            // attach to result
            tail->next = it.second;
            tail = tail->next;
            
            // push next node from same list
            if(it.second->next) {
                pq.push({it.second->next->val, it.second->next});
            }
        }
        
        return dummy->next;
    }
};

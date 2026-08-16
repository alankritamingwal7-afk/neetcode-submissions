/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertcopy(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copynode = new Node(temp->val);
            Node* tempnxt = temp->next;
            copynode->next = tempnxt;
            temp->next = copynode;
            temp = temp->next->next;
        }

    }

    void connectrandomptr(Node* head){
        Node* temp = head;
        while(temp){
            Node* copynode = temp->next;
            //check random pointer null
            if(temp->random!=nullptr){
                copynode->random = temp->random->next;
            }
            else{
                copynode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node* connectnext(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp){
            res->next=temp->next;
            temp->next = temp->next->next;
            res= res->next;
            temp=temp->next;
        }
        return dummy->next;

    }

    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        
        // Step 1: Insert copy nodes after each original node
        insertcopy(head);
        
        // Step 2: Connect random pointers for copy nodes
        connectrandomptr(head);
        
        // Step 3: Separate the two lists
        return connectnext(head);
    }
};

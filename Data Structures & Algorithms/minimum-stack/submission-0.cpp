#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

class MinStack {
    Node* head;       // main stack
    Node* minHead;    // stack to track minimums
public:
    MinStack() {
        head = nullptr;
        minHead = nullptr;
    }

    void push(int val) {
        // push to main stack
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        // push to min stack if empty or val <= current min
        if (minHead == nullptr || val <= minHead->val) {
            Node* minNode = new Node(val);
            minNode->next = minHead;
            minHead = minNode;
        }
    }

    void pop() {
        if (head == nullptr) return;
        int poppedVal = head->val;

        // pop from main stack
        Node* temp = head;
        head = head->next;
        delete temp;

        // pop from min stack if needed
        if (minHead != nullptr && minHead->val == poppedVal) {
            Node* minTemp = minHead;
            minHead = minHead->next;
            delete minTemp;
        }
    }

    int top() {
        if (head == nullptr) return -1;
        return head->val;
    }

    int getMin() {
        if (minHead == nullptr) return -1;
        return minHead->val;
    }
};

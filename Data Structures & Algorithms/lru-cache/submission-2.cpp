#include <iostream>
#include <map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    int cap;
    map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Insert node right after head
    void insert(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Remove node from list
    void remove(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* resnode = mp[key];
        remove(resnode);
        insert(resnode);
        //mp[key] = head->next; // update map to new position
        return resnode->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
            //mp[key] = head->next;
            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);   // erase by key, not value
            remove(lru);
            delete lru;
        }

        Node* newnode = new Node(key, value);
        insert(newnode);
        mp[key] = head->next;
    }
};

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* t1 = &dummy;
        ListNode* t2 = &dummy;
        while(n-- >= 0 && t2){
            t2 = t2->next;
        }
        while(t2){
            t2 = t2->next;
            t1 = t1->next;
        }

        ListNode* del = t1->next;
        t1->next = t1->next->next;
        delete del;
        return dummy.next;
    }
};


// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0); 
        ListNode dummy2(0);
        
        ListNode* h1 = &dummy1;
        ListNode* h2 = &dummy2;
        ListNode* t1 = head;
        while(t1){
            if(t1->val < x){
                h1->next = t1;
                h1 = h1->next;
            } else {
                h2->next = t1;
                h2 = h2->next;
            }
            t1 = t1->next;
        }
        h2->next = nullptr;
        h1->next = dummy2.next;
        return dummy1.next;
    }
};



// HW
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1






// https://leetcode.com/problems/reverse-nodes-in-k-group/description/




// https://leetcode.com/problems/lru-cache/     


class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(){
        key = -1;
        val = -1;
        next = nullptr;
        prev = nullptr;
    }
    Node(int key, int val): key(key), val(val), next(nullptr), prev(nullptr) {} 
    Node(int key, int val, Node* next, Node* prev): key(key), val(val), next(next), prev(prev) {}
};


class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int cap = 0;
    Node* head;
    Node* tail;
    
    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node; 
        head->next = node; 
    }
    
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) {
        if(capacity<=0) return; 
        cap = capacity;
        head = new Node();
        tail = new Node();    
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        Node* node = cache[key];
        remove(node);
        addToFront(node);
        return node->val;
    }


    void put(int key, int value) {
        if(cache.count(key)){
            Node* node = cache[key];
            node->val = value;
            remove(node);
            addToFront(node);
        } else {
            if(cache.size() == cap){
                Node* lru = tail->prev;
                cache.erase(lru->key);
                remove(lru); 
            }
            Node* node = new Node(key,value);
            cache[key] = node;
            addToFront(node);
        }
    }
};

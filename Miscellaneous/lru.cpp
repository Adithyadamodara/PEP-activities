#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key,value;
    Node* next;
    Node* prev;

    Node(int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache{
private:
    int capacity;
    unordered_map<int, Node*> lru;
    Node* head;
    Node* tail;

    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
public:
    LRUCache(int capacity){
        if(capacity<=0) return;
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key){
        if(lru.find(key) == lru.end()){
            return -1;
        }
        Node* node = lru[key];
        removeNode(node);
        addToFront(node);
        return node->value;
    }

    void put(int key, int value){
        if(lru.find(key) != lru.end()){
            Node* node = lru[key];
            removeNode(node);
            addToFront(node);
        } else {
            if(lru.size() == capacity){
                Node* node = tail->prev;
                lru.erase(node->key);
                removeNode(node);
                delete(node);
            }
            Node* nd = new Node(key, value);
            lru[key] = nd;
            addToFront(nd);
        }
    }
};

int main(){
    LRUCache cache(2); // Cache with size 2
    cache.put(1,5);
    cache.put(2,10);
    cout<<cache.get(1)<<endl;
    cache.put(3,15);
    cout<<cache.get(2)<<endl; // -1 as it is evicted from the cache 
    cout<<cache.get(3)<<endl;
    return 0;
}
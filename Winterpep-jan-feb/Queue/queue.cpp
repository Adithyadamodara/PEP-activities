#include<bits/stdc++.h>
#include<stdexcept>
using namespace std;

struct Node{
    int value;
    Node* next;

    Node(int v): value(v), next(nullptr) {}    
};

class Queue{
private:
    int s;
    Node* head;
    Node* tail;
public:
    Queue(){
        s = 0;
        head = nullptr;
        tail = nullptr;
    }
    bool empty(){
        return s == 0;
    }
    void push(int value){
        Node* node = new Node(value);
        if(empty()){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        s++;
    }
    int pop(){
        if(empty()) throw runtime_error("Queue is empty");
        Node* del = head;
        head = head->next;
        int val = del->value;
        delete del;
        s--;
        return val;
    }
    int front(){
        if(empty()) throw runtime_error("Queue is empty");
        return head->value;
    }
    int size(){
        return s;
    }
    ~Queue(){
        while(s){
            Node* del = head;
            head = head->next;
            delete del;
            s--;
        }
    }
};

int main(){
    Queue que;
    cout<<que.size()<<endl;
    que.push(5);
    que.push(7);
    que.push(8);
    cout<<que.front()<<endl;
    que.pop();
    cout<<que.front()<<endl;
    que.pop();
    cout<<que.front()<<endl;
    que.pop();
    cout<<que.front()<<endl;
    return 0;
}
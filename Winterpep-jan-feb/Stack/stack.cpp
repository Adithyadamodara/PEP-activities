#include<iostream>
#include<stdexcept>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int v): val(v), next(nullptr) {}
};

class Stack{
private:
    int size;
    Node* head;
public:
    Stack(){
        size = 0;
        head = nullptr;
        cout<<"Instance Created\n";
    }
    void push(int val){
        Node* node = new Node(val);
        if(!head){
            head = node;
        } else {
            node->next = head;
            head = node;
        }
        size++;
    }
    bool empty(){
        return size == 0;
    }
    int pop(){
        if(empty()) throw runtime_error("\nStack Underflow");
        Node* node = head;
        head = head->next;
        size--;
        int val = node->val;
        delete node;
        return val;
    }
    int top(){
        if(empty()) throw runtime_error("\nStack is empty");
        return head->val;
    }

    // Memory deallocation
    ~Stack(){
        while(!empty()){
            pop();
        }
        cout<<"\nInstance deleted";
    }

};

int main(){
    Stack stk;
    stk.push(5);
    stk.push(3);
    cout<<stk.top();
    stk.pop();
    cout<<stk.top();
    stk.pop();
    stk.top();
    return 0;
}
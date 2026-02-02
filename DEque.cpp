#include<bits/stdc++.h>
using namespace std;

struct Node{   
public:
    int value;
    Node* next;
    Node* prev;

    Node(int v): value(v), next(nullptr), prev(nullptr) {}  
};

class dlist{
private:
    int s; 
    Node* head;
    Node* tail;
public:
    dlist(){
        head = nullptr;
        tail = nullptr;
        s=0;
    }
    int size(){
        return s;
    }
    void push(int v){
        if(s==0){
            head = new Node(v);
            tail = head;
        } else {
            Node* temp = new Node(v);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        s++;
    }
    void pop(){
        if(s==0) return;
        Node* del = head;
        if(s==1) head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete(del);
        s--;
    }
    void pop_back(){
        if(s==0) return;
        Node* del = tail;
        if(s==1) head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete(del);
        s--;
    }
    int front(){
        if(s==0){
            return -1;
        }
        return head->value;
    }
    int back(){
        if(s==0){
            return -1;
        }
        return tail->value;
    }
    bool empty(){
        if(s==0){
            return true;
        } else return false; 
    }

    ~dlist(){
        while(s>0){
            pop();   
        }
    }
};

int main(){
    dlist obj;
    cout<<obj.size()<<endl; 
    obj.push(5);
    cout<<obj.size()<<" "<<obj.front()<<" "<<obj.back()<<endl;
    obj.pop();
    cout<<obj.size();
    obj.push(6);
    obj.push(7);
    obj.push(9); // 6 7 9
    cout<<" "<<obj.front()<<" "<<obj.back()<<" Pop_back: "<<obj.back()<<" ";
    return 0;
}
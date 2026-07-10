#include<iostream>
#include<vector>
using namespace std;

class MyStack{
private:
    int size;
    int top;
    vector<int> stk;
public:
    MyStack(int size): size(size), top(-1) {
        stk.resize(size);
    }

    void push(int val){
        if(top==size-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        stk[++top] = val;
    }

    void pop(){
        if(top==-1) {
            cout<<"Stack is empty";
            return;
        }
        stk.pop_back();
        top--;
    }

    bool isempty(){
        return top==-1;
    }

};
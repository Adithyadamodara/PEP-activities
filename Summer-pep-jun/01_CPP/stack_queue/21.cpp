// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

class Solution {
public:

    void rec(stack<int>& st, int x){
        if(st.empty()) {
            st.push(x);
        }
        else {
            int n = st.top();
            st.pop();
            rec(st,x);
            st.push(n);    
        }
    }
    stack<int> insertAtBottom(stack<int>& st, int x) {
        rec(st,x);
        return st;
    }
};



// https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1


class Solution {
public:
    int n = -1;  
    void deleteMid(stack<int>& s) {
        // code here..
        if(n==-1) n = floor(s.size())/2;
        if(n==0) {
            s.pop();
            return;
        }
        int ele = s.top();
        s.pop();
        n--;
        deleteMid(s);
        s.push(ele);
    }
};



// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int value) {
        if(!stk.empty()){
            stk.push({value, min(stk.top().second, value)});
        } else {
            stk.push({value, value});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        if(stk.empty()) return 0;
        return stk.top().first;
    }
    
    int getMin() {
        if(stk.empty()) return 0;
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




 // https://leetcode.com/problems/implement-stack-using-queues/description/


 class MyStack {
private:
    queue<int> qu;
    int size = 0;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(size==0){
            qu.push(x);
            size++;
            return;
        }
        qu.push(x);
        size++;
        for(int i=0;i<size-1;i++){
            int n = qu.front();
            qu.pop();
            qu.push(n);
        }
    }
    
    int pop() {
        int n = qu.front();
        qu.pop();
        size--;
        return n;
    }
    
    int top() {
        if(size==0) return 0;
        return qu.front();
    }
    
    bool empty() {
        return size==0;    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }        
        int x = stk2.top();
        stk2.pop();
        return x;
    }
    
    int peek() {
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return (stk1.empty() && stk2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// https://www.geeksforgeeks.org/problems/queue-reversal/

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if(q.empty()){
            return; 
        } else {
            int n = q.front();
            q.pop();
            reverseQueue(q);
            q.push(n);
        }
    }
};  




// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/



class Solution {
public:
    void reverse(queue<int>& q, int k){
        if(k==0) return;
        
        int t = q.front();
        q.pop();
        reverse(q, k-1);
        q.push(t);
    }  
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if(k>n) return q;
        reverse(q,k);
        int t = n - k; 
        while(t--){
            int e = q.front();
            q.pop();
            q.push(e);
        }
        return q;
    }
};




// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
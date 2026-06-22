#include<iostream>
#include<stdexcept>
#include<vector>
using namespace std;

class Heap{
public:
vector<int> arr;

void heapify(){
    int n = arr.size();
    for(int i= n/2 - 1;i>=0;i--){
        heapDown(i);
    }
}
void heapDown(int parent){
    int x = parent;
    int left = x*2 + 1;
    int right = x*2 + 2;
    int n = arr.size();
    if(left < n && arr[left] < arr[x]){
        x = left;
    }
    if(right < n && arr[right] < arr[x]){
        x = right;
    }
    if(parent != x){
        swap(arr[x],arr[parent]);
        heapDown(x);
    } else return;
}

void heapUp(int idx){
    while(idx > 0){
        int parent = (idx - 1)/2;
        if(arr[parent] > arr[idx]){
            swap(arr[parent],arr[idx]);
            idx = parent;
        } else break;
    }
}

void push(int x){
    arr.push_back(x);
    heapUp(arr.size() - 1);
}

int pop(){
    if(isEmpty()) throw runtime_error("Heap is Empty"); 
    int val = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    heapDown(0);
    return val;
}

bool isEmpty(){
    return arr.empty();
}

int getSize(){
    return arr.size();
}

int peek(){
    if(isEmpty()) throw runtime_error("Heap is empty");
    return arr[0];
}

};


int main(){
    Heap hp;
    hp.push(3);
    hp.push(18);
    hp.push(2);
    cout<<hp.pop();
    cout<<hp.pop();
    cout<<hp.pop();
    return 0;
}
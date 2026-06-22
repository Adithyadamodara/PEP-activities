#include<bits/stdc++.h>
using namespace std;

// Find the previous smallest element of a given array;

vector<int> prevSmallEle(vector<int>& arr){
    int n = arr.size();
    vector<int> res;
    stack<int> stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && stk.top()>arr[i]){
            stk.pop();
        }
        if(stk.empty()){
            stk.push(arr[i]);
            res.push_back(-1);
        } else if(stk.top()<arr[i]){
            res.push_back(stk.top());
            stk.push(arr[i]);
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> res = prevSmallEle(arr);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}
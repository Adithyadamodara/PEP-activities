#include<bits/stdc++.h>
using namespace std;

// Return size of the largest subarray with equal number of 0s and 1s

// 0 1 0 1 1 1 0 0 1 1 0 0 0 1 0 


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int> defs;
    defs[0]=-1;
    int maxDef=0,ones=0,zeros=0;
    for(int i=0;i<n;i++){
        if(arr[i]) ones++;
        else zeros++;
        int def = ones - zeros;
        if(defs.find(def) != defs.end()){
            maxDef = max(maxDef, i - defs[def]);
        } else {
            defs[def] = i;
        }
    }
    cout<<maxDef;
    return 0;   
}
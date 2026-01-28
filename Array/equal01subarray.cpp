#include<bits/stdc++.h>
using namespace std;

// Counting arrays with equal 0 & 1 pairs

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int> mpp;
    mpp[0]=1;
    int ones=0, zeros=0, res=0;
    for(int i=0;i<n;i++){
        if(arr[i]) ones++;
        else zeros++;
        int def = ones-zeros;
        if(mpp.count(def)){
            res += mpp[def]++;
        } else {
            mpp[def]=1;
        }
    }
    cout<<res;
    return 0;
}
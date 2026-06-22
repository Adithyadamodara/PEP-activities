#include<bits/stdc++.h>
using namespace std;

// Maximizing the minimum distance between cows in stalls with distance arr[i]

// Brute Force Implementation

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;
    int maxMinDef = -1e9;
    vector<int> resarray; 
    for(int i=1;i<(1<<n);i++){ // i => set bit checker 
        vector<int> temp;
        for(int j=0;j<n;j++){ // j => index pointer
            if((i & (1<<j)) != 0){ // setbit checked with index 
                temp.push_back(arr[j]);
            }
        }
        if(temp.size()==k){
            vector<int> defs;
            int mn=1e9;
            for(int j=1;j<temp.size();j++){
                mn = min(mn,temp[j]-temp[j-1]);
            } 
            if(mn > maxMinDef){
                    resarray = temp;
                    maxMinDef = mn;
            }
        }
    }
    for(int i:resarray) cout<<i<<" ";
    cout<<"\nMaximum Minimum Def: "<<maxMinDef;
    return 0;
}
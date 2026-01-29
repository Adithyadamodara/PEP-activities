#include<bits/stdc++.h>
using namespace std;

// Generating all subsequences of a given array using bit manipulation

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n";
    for(int i=1;i<(1<<n);i++){ // i => set bit checker 
        vector<int> temp;
        for(int j=0;j<n;j++){ // j => index pointer
            if((i & (1<<j)) != 0){ // setbit checked with index 
                temp.push_back(arr[j]);
            }
        }
        for(int ele:temp) cout<<ele<<" ";
        cout<<endl;     
    }
    
    return 0;
}
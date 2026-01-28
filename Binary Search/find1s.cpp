#include<bits/stdc++.h>
using namespace std;

// Given a binary array in non-increasing order find the number of 1s

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Given non-increasing array: ";
    for(int i:arr){
        cout<<i<<" ";
    }
    
    int low = 0, high = n-1, rightmost=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==1) {
            rightmost = mid;
            low = mid+1;
        } else if(!arr[mid]){
            high = mid - 1;
        } else low = mid + 1;
    }
    cout<<"\nTotal 1s in array: "<<rightmost+1;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Finding consecutive target eles in a sorted array 


int firstPos(vector<int>& arr, int& n, int& target){
    int low = 0, high = n-1, index;
    
    while(low<=high){
        int mid = low + ( high - low)/2;
        if(arr[mid]==target){
            index = mid;
            high = mid-1;
        } else if(arr[mid]<target) {
            low = mid + 1;
        } else high = mid - 1;
    }
    return index;
}

int lastPos(vector<int>& arr, int& n, int& target){
    int low = 0, high = n-1, index;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            index = mid;
            low = mid + 1;
        } else if(arr[mid]<target) {
            low = mid + 1;
        } else high = mid - 1;
    }
    return index;
}

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    int target;
    cout<<"Enter target: ";
    cin>>target;
    
    sort(arr.begin(),arr.end());
    cout<<"Sorted array: ";
    for(int i:arr){
        cout<<i<<" ";
    }

    int leftidx = firstPos(arr, n, target);
    int rightidx = lastPos(arr, n, target);

    cout<<"\nLeftmost: "<<leftidx<<"\nRightmost: "<<rightidx;
    return 0;
}
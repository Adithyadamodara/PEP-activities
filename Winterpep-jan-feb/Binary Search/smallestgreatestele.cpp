#include<bits/stdc++.h>
using namespace std;

// In a sorted, strictly increasing array, find the smallest element which is greater than given elememt

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter Target: ";
    int target=0;
    cin>>target;
    cout<<"Given Array: ";
    for(int i:arr) cout<<i<<" ";
    int low = 0, high = n-1, index=-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            if(mid<n-1) index = mid+1;  // IF target element is in last index, then the result is -1
            break;
        } else if(arr[mid]<target){
            low = mid + 1;
        } else high = mid - 1;
    }
    if(index==-1) cout<<"\nElement not present";
    else cout<<"\nElement is: "<<arr[index];
    return 0;
}
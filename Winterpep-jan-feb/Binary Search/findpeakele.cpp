#include<bits/stdc++.h>
using namespace std;

// Find the peak element in a sorted array. ( MOUNTAIN ARRAY )
/* Find the element after which the array becomes non-increasing*/

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Given array: ";
    for(int i:arr) cout<<i<<" ";

    int low=0, high = n-1;
    while(low<high){
        int mid = low + (high - low)/2; 
        if(arr[mid]<arr[mid-1]){
            high = mid;
        } else {
            low = mid + 1;
        } 
    }
    cout<<"\nPeak element: "<<arr[low-1];
    return 0;
}
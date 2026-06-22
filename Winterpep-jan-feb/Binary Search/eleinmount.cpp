#include<bits/stdc++.h>
using namespace std;

// Given a MOUNTAIN ARRAY
// Find the given target element present in the leftmost position


// Finding Peak element in array to split up and serach each halves for element

// If element is found in the increasing(left) subarray, the index is returned
// if element is not found in left subarray, it goes to right subarray and seraches

int findPeak(vector<int>& arr){       
    int low=0, high = arr.size()-1, index;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]<arr[mid-1]){
            index = mid-1;
            break;
        }else if(arr[mid] > arr[mid-1]){
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
    cout<<"Enter Target ele: ";
    cin>>target;
    cout<<"Given Array: ";
    for(int i:arr) cout<<i<<" ";

    int peakIdx = findPeak(arr);
    cout<<"\nPeak Index: "<<peakIdx<<endl;
    int low=0, high=peakIdx, index=-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target) {
            index = mid;
            break;
        } else if(arr[mid] < target){
            low = mid + 1;
        } else high = mid - 1;
    }
    
    if(index==-1){
        low = peakIdx, high = n-1;
        while(low <= high){
            int mid = low + (high - low )/2;
            if(arr[mid]==target){
                index = mid;
                break;
            } else if(arr[mid] < target){
                high = mid-1;
            } else low = mid + 1; 
        }
    }
    if(index==-1) cout<<"Element not found";
    else cout<<"\nIndex of element: "<<index;
    return 0;
}
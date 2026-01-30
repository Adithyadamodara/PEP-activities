#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter Target: ";
    cin>>target;

    int left=0, right=n-1, index=-1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(arr[mid]==target){
            left = mid;
            break;
        }
        if(arr[mid]>arr[right]){
            if(arr[mid]>target && arr[left]<=target){
                right = mid-1;
            } else {
                left = mid + 1;
            }
        } else {
            if(arr[mid]<target && arr[right]>=target){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

    }

    cout<<"\nIndex: "<<left;
    return 0;
}
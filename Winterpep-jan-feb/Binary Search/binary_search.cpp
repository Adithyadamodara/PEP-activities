#include<bits/stdc++.h>
using namespace std;

// Regular Binary serach


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    sort(arr.begin(),arr.end());
    cout<<"Sorted array: ";
    for(int i:arr){
        cout<<i<<" ";
    }
    int low = 0, high = n-1, res = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target) {
            res=mid;
            break;
        } else if(arr[mid]<target){
            low = mid + 1;
        } else high = mid - 1;
    }
    cout<<"\nTarget index: "<<res;
    return 0;
}
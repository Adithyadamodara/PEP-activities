#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ind = -1;
    int left=0,right=n-1; 
    while(left<=right){
        int mid = left + (right - left)/2;
        if(arr[mid] < arr[right]){
            ind = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout<<"\n"<<ind;
    return 0;
}
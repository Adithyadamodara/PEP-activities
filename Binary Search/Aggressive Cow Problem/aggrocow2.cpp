#include<bits/stdc++.h>
using namespace std;

// Aggressive cow by counting and maintaining the max distance

bool isPossible(vector<int>& arr,int n, int k, int d){
    int count=1;
    int lastPos = arr[0];
    
    for(int i=1;i<n;i++){
        if(arr[i]-lastPos >= d){
            count++;
            lastPos = arr[i];
        }
        if(count==k) return true;

    }
    return false;
}

int agg_cows(vector<int>& arr, int n, int k){
    int start = 1;
    int end = arr[n-1] - arr[0];
    int ans = -1;

    while(start<=end){
        int mid = start + (end - start)/2;
        if(isPossible(arr,n,k,mid)){
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
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
    cout<<"Maximum minimum distance between stalls: "<<agg_cows(arr,n,k);   

    return 0;
}
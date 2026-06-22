#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l ,int mid , int r){
    vector<int> temp(r-l+1,0);

    int i = l, j = mid+1;
    int k=0;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++]; 
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    while(j<=r){
        temp[k++] = arr[j++];
    }

    for(int p=0;p<(r-l+1);p++){
        arr[l+p] = temp[p];
    }
}

void sort(vector<int>& arr, int l,int r){
    if(l>=r) return;
    
    int mid = l + (r - l)/2;
    sort(arr,l,mid);
    sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,0,n);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
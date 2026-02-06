#include<bits/stdc++.h>
using namespace std;


void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

// selecting last element and comparing other elements, smaller elements swapped to the left and bigger elements skipped
int partition(vector<int>& arr,int l, int r){
    int pivot = arr[r];
    int j=l;
    for(int i=j;i<r;i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[j],arr[r]);
    return j;
}

void quicksort(vector<int>& arr, int l,int r){
    if(l>=r) return;
    int p = partition(arr,l,r);
    quicksort(arr, l, p-1);
    quicksort(arr, p+1, r);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
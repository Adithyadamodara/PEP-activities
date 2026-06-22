#include<iostream>
using namespace std;

// Checking if an array is sorted 

int main(){
    int n;
    bool res=true;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]) {
            res = false;
            break;
        }
    }
    if(res) cout<<"Sorted";
    else cout<<"Not sorted";
    return 0;
}
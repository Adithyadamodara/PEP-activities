#include<bits/stdc++.h>
using namespace std;

// Create Array of size N. Find the most frequent element in the array(Rightmost in case of conflict/equal max frequencies)
// Using Hash Map (Unordered_map) & dynamic array allocation and deletion in heap
int main(){
    int n;
    cin>>n; 
    int *arr = new int[n];
    unordered_map<int,int> freq;
    int maxVal=INT_MIN;
    int res;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
        if(freq[arr[i]] >= maxVal) {    // Using >= to ensure selection of rightmost element incase of equal max frequencies
            maxVal = freq[arr[i]];
            res = arr[i];
        }
    }
    cout<<"Result: "<<res<<"\nFrequency: "<<maxVal;
    delete arr; 
    return 0;
}
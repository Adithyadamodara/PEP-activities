#include<bits/stdc++.h>
using namespace std;

// Create Array of size N. Find the most frequent element in the array(Rightmost in case of conflict)

// Using Hash Map 
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
        if(freq[arr[i]] > maxVal) {
            maxVal = freq[arr[i]];
            res = arr[i];
        }
    }
    cout<<"Result: "<<res<<"\n Frequency: "<<maxVal;
    delete arr; 
    return 0;
}
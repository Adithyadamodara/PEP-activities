#include<bits/stdc++.h>
using namespace std;

/* Given an array and with n number of fruits. Find the maximum level of fruits that can be consumed from each bucket
so that the total becomes M.
It is guaranteed that sum of all the fruits in the basket will be greater than M.
Kevin can only eat fruits from a basket if it has more fruits than M.
Find the optimal position to place a marker so that M Fruits can be consumed.

*/

bool isPossible(vector<int>& arr, int mid,int m){
    int sum=0;
    for(int i:arr){
        int def = i - mid;
        if(def>0) sum += def;
    }
    return sum>=m;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int m;
    cout<<"Enter M: ";
    cin>>m;
    
    int low = 0, high = *max_element(arr.begin(),arr.end()), ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(isPossible(arr, mid, m)){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout<<"Answer: "<<ans;
    return 0;
}
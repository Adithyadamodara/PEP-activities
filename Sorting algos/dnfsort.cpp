#include<iostream>
#include<vector>
using namespace std;

// In Place array sorting using DNF

/* Constraints:
    1. In place
    2. compolexity  < O(n^2)
    3. No extra space

    DNF
*/

void swap(int& a, int& b){
    a = a+b; 
    b = a-b; 
    a = a-b; 
}

void dnf_sort(vector<int>& arr){
    int l = 0, m=0, h=arr.size()-1;

    while(m<=h){
        if(arr[m]==0){
            swap(arr[m], arr[l]);
            m++;
            l++;
        } else if(arr[m]==1){
            m++;
        } else {
            swap(arr[m], arr[h]);
            h--;
        }
    }
}


int main(){
    int n;
    cin>>n; 
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dnf_sort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    
    return 0;
}
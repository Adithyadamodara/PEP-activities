#include<iostream>
#include<map>
using namespace std;

/* 
Given an integer array nums of length n where all the integers of nums are in the range [1, n]
and each integer appears once or twice. Return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

*/


// HInt: Modify the given array, given range [1, N] for index mapping


int main(){
    int n;
    cin>>n;
    int* arr= new int[n];
    map<int,int> freq;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }
    
    // Brute force 
    int res[n];
    int s=0;
    for(auto& i:freq){
        if(i.second==2) {
            res[s++] = i.first;
        }
    }
    cout<<"Elements that appear twice"<<endl;
    for(int i=0;i<s;i++) cout<<res[i]<<" ";
    delete arr;
    return 0;
}
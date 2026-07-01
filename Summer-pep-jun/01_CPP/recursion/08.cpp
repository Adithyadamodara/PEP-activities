// Linear search & binary search using recursion

#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
    if(size == 0) return false;
    if(arr[0] == key) return true;
    return search(arr+1, size-1, key);
}

bool binSearch(int arr[], int l, int r, int key){
    if(l>r) return false;
    int mid = l + (r - l)/2;
    if(arr[mid] == key) return true;
    else if (arr[mid] < key) return binSearch(arr, mid + 1, r, key);
    else return binSearch(arr, l, mid - 1, key);
}


int main(){
    int arr[] = {5,6,1,7,2,0,9};
    cout<<search(arr, 7, 87)<<endl;

    int arr1[] = {1,2,4,5,6,8,9,13};
    cout<<binSearch(arr1, 0, 8, 13);

    return 0;
}
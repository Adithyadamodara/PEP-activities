// Linear Search in 2D array 

#include<iostream>
using namespace std;

bool isPresent(int arr[][3], int target, int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j] == target) return true;
        }
    }
    return false;
}

void calcRowSum(int arr[][3], int r, int c){
    for(int i=0;i<r;i++){
        int sum = 0;
        for(int j=0;j<c;j++){
            sum += arr[i][j];
        }
        cout<<"Row 1: "<<sum<<endl;
    }
}

void maxSumnRow(int arr[][3], int r, int c){
    int maxSum = -1;
    int rowIndex = -1;

    for(int i=0;i<r;i++){
        int sum = 0;
        for(int j=0;j<c;j++){
            sum += arr[i][j];
        }
        if(maxSum <= sum){
            maxSum = sum;
            rowIndex = i; 
        }
    }
    cout<<"Max Sum: "<<maxSum<<endl;
    cout<<"Row: "<<rowIndex;
}



int main(){
    int arr[][3] = {1,2,3,9,8,7,7,8,9};
    // bool found = isPresent(arr, 4, 3, 3);
    // // if(found) cout<<"Found";
    // else cout<<"Not Found";

    calcRowSum(arr, 3, 3);
    cout<<endl;
    maxSumnRow(arr, 3, 3);
    return 0;
}

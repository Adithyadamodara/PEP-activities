#include<bits/stdc++.h>
using namespace std;


void zigZag(vector<vector<int>>& arr){
    int m = arr.size();
    int n = arr[0].size();
    for(int i=0;i<n;i++){
        if( i%2==0){
            for(int j=0;j<m;j++){
                cout<<arr[j][i]<<" ";
            }
        } else {
            for(int j=m-1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
    }
}


void spiral(vector<vector<int>>& arr){
    int m = arr.size();
    int n = arr[0].size();
    int s = m*n;
    
    int topRow = 0, leftCol = 0, rightCol = n-1, bottomRow = m-1;
    while(topRow<=bottomRow && leftCol<=rightCol){
        
        for(int i=leftCol; i<=rightCol;i++){
            cout<<arr[topRow][i]<<" ";
        }
        topRow++;

        for(int i=topRow;i<=bottomRow;i++){
            cout<<arr[i][rightCol]<<" ";
        }
        rightCol--;

        for(int i=rightCol;i>=leftCol;i--){
            cout<<arr[bottomRow][i]<<" ";
        }
        bottomRow--;

        for(int i=bottomRow;i>=topRow;i--){
            cout<<arr[i][leftCol]<<" ";
        }
        leftCol++;
    }
}

int main(){
    vector<vector<int>> arr = {{ 6, 8, 10, 2},{ 14, 1, 13, 15}, { 5, 11, 9, 3}, { 12, 16, 4, 7}};
    zigZag(arr);
    cout<<endl;
    spiral(arr);
    return 0;
}
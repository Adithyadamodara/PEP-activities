#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;

    int **arr = new int*[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
    }

    //write code for deletion

    return 0;
}
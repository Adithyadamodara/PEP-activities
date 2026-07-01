// 2d Arrays

#include<iostream>
using namespace std;

// Every column except the first must be bounded (defined in the function defenition)

void func(int arr[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j+=2){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    func(arr);

    return 0;
}

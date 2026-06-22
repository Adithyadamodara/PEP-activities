// Printing Solid square pattern n*n

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int n=20;
    int s = -1;
    for(int i=0;i<n*2-1;i++){
        if(i<n){
            s+=2;
            for(int j=0;j<n-i-1;j++) cout<<" ";
            for(int j=0;j<s;j++) cout<<"*";
        } else {
            s-=2;
            for(int j=0;j<i-n+1;j++) cout<<" ";
            for(int j=0;j<s;j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }   
    return 0;
}
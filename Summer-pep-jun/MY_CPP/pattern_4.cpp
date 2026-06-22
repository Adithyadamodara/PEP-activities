// Number Triangle

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    // a. 1234

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<j+1<<" ";
    //     }
    //     cout<<endl;
    // }

    // b. Repeated 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<i+1<<" ";
    //     }
    //     cout<<endl;
    // }


    // c. Alphabet Triangle

    char c = 'A';
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<char(c+j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
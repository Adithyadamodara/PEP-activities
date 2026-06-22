// Easy - Medium patterns

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    // a. Right angled triangle
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(j<n-i-1) cout<<"  ";
    //         else cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // b. Inverted Right angled
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(j<i) cout<<"  ";
    //         else cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // c. Binary triangle
    // bool bit = 1;
    // for(int i=0;i<n;i++){
    //     if(i%2==0) bit = 1;
    //     else bit = 0; 
    //     for(int j=0;j<=i;j++){
    //         cout<<bit<<" ";
    //         bit = !bit;
    //     }
    //     cout<<endl;
    // }

    // d. Floyd's Triangle

    // int a = 1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<a++<<" ";
    //     }
    //     cout<<endl;
    // }

    // e. Continuous Character traingle
    // char c = 'A';
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<c++<<" ";
    //     }
    //     cout<<endl;
    // }

    // f. Hollow Square
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==n-1){
                cout<<"* ";
            } else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}
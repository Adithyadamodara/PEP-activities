// Medium

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    
    // a. Pyramid
    // int p=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<p;j++){
    //         cout<<"*";
    //     }
    //     p+=2;
    //     cout<<endl;
    // }
    
    // b. Inverted Pyramid
    // int p = ((n-1)*2) + 1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<p;j++){
    //        cout<<"*"; 
    //     }
    //     p-=2;
    //     cout<<endl;
    // }

    // c. Diamond
    // int p = ((n-1)*2) + 1;
    // int t = 1;
    // for(int i=0;i<p;i++){
    //     if(i<n){
    //         for(int j=0;j<n-i-1;j++){
    //             cout<<" ";
    //         }
    //         for(int j=0;j<t;j++){
    //             cout<<"*";
    //         }
    //         t+=2;
    //     } else {
    //         t-=2;
    //         for(int j=0;j<(i%n)+1;j++){
    //             cout<<" ";
    //         }
    //         for(int j=0;j<t;j++){
    //             cout<<"*";
    //         }
    //     }
    //     if(i==n-1) t-=2;
    //     cout<<endl;
    // }
        
    return 0;
}
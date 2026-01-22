#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int ans=1;
    
    // Prints single line
    for(int i=0;i<=n;i++){
        cout<<ans<<" ";
        ans = ans * (n-i) / (i+1);
    }
    return 0;
}
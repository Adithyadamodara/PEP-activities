#include<bits/stdc++.h>
using namespace std;

// Reversing a number while making sure the resulting number is within integer limits

int main(){
    int n;
    cin>>n;
    int temp=n;
    long long res=0;
    while(temp>0){
        int t = temp%10;
        res = (res*10 + t) > INT_MAX ? -1 : res*10 + t;
        if(res==-1) break;
        temp/=10;
    }
    cout<<res;
    return 0;
}
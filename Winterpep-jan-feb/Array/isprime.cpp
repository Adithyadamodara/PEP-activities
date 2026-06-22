#include<iostream>
#include<vector>
using namespace std;

// Find all pais of prime numbers whose difference is 6 given a range N(inclusive).

/*bool isPrime(int n){
    if(n<=1) return false;
    if(n%2==0) return false;
    for(int i=3;i*i<n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}*/

void sieve(bool s[], int n){
    for(int i=2;i<=n;i++) s[i] = true;
    s[0] = s[1] = false;
    for(int p=2;p*p<=n;p++){
        if(s[p]){
            for(int i=p*p;i<=n;i+=p){
                s[i] = false;
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    bool s[n+1];
    sieve(s,n);
    vector<vector<int>> res;
    for(int i=2;i<=n;i++){
        if(s[i] && ((i+6)<n) && s[i+6]) res.push_back({i,i+6});
    }
    for(auto& pair: res){
        cout<<pair[0]<<" - "<<pair[1]<<endl;
    }
    return 0;
}
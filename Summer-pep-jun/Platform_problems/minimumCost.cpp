#include<iostream>
#include<vector>
using namespace std;


const int MOD = 1e9 + 7;
long long getSum(long long n){
    long long a = n, b = n+1;

    if(a%2==0) a/=2;
    else b/=2;

    return (a % MOD) * (b%MOD) % MOD;
}

int minimumCost(vector<int>& nums, int k) {
    long long t = k;
    long long cost = 0;
    long long x = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=t){
            t -= nums[i];
        } else {
            long long p = (nums[i] - t + k - 1LL)/k;
            long long extra = (getSum(p+x) - getSum(x) + MOD) % MOD;
            x += p;
            t += 1LL * k*p;
            cost = (cost + extra) % MOD;
            t -= nums[i];
        }
    }
    return cost;
}


int main(){
    vector<int> arr = {1,1,7,14};
    cout<<minimumCost(arr, 4);
    return 0;
}
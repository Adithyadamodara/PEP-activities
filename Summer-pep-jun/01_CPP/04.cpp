#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>& nums, int k){
    bool found = false;
    for(int i:nums){
        if(nums[i] == k) {
            found = true;
            break;
        }
    }   
    return found ? k*2 : k/2;
}

int main(){
    vector<int> nums = {3,5,1,12,36,32,4};
    int k = 12;
    cout<<"Ans: "<<solution(nums, k);
    return 0;
}
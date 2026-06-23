// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// https://leetcode.com/problems/move-zeroes/description/?envType=problem-list-v2&envId=d2s5a6x3


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,0,3,12};

    s.moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}
/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function. */

// https://leetcode.com/problems/sort-colors/description/?envType=problem-list-v2&envId=d2s5a6x3

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++; 
                mid++;
            } 
            else if(nums[mid]==1) mid++;
            else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,1,2,0,1,2,1,0,0};
    s.sortColors(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;
}
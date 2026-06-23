/* 
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

// https://leetcode.com/problems/majority-element/
// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Inital attempt 

    // int majorityElement(vector<int>& nums) {
    //     int res = 0;
    //     int n = nums.size();
    //     if(n == 1) return nums[0];
    //     for(int i = 0;i<n;i++){
    //         int count = 1;
    //         for(int j = i+1;j<n;j++){
    //             if(nums[i]==nums[j]) count++;
    //             if(count > n/2) {
    //                 res = nums[i];
    //                 break;
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int element = -1;
        for(int num: arr){
            if(count == 0){
                element = num;
                count = 1;
            } else if(num == element){
                count++;
            } else count--;
        }
        
        count = 0;
        for(int n:arr){
            if(n == element) count++;
        }
        if(count > n/2) return element;
        return -1;
    }
};

int main(){
    Solution s;


    return 0;
}
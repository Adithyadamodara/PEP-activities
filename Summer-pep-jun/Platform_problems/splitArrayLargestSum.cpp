// https://leetcode.com/problems/split-array-largest-sum/


class Solution {
public:
    bool canPartition(vector<int>& nums, int k, int high){
        int cnt = 1;
        int sum = 0;
        for(int i:nums){
            if(sum+i > high) {
                cnt++;
                sum=i;
            } else {
                sum += i;
            }
            if(cnt>k) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // low -> max element as answer will not be lesser than maximum element in the array
        // high -> sum of entire array

        int low = *max_element(nums.begin(), nums.end()) - 1;
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low + 1<high){
            int mid = low + (high - low)/2;
            
            if(canPartition(nums, k, mid)){
                high = mid;
            } else {
                low = mid;
            }
        }
        
        return high;
    }
};
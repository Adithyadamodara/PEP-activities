#include<iostream>
using namespace std;


// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/2045255531/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int  i = 0, j = numbers.size() - 1;
        while(i<j){
            int sum = numbers[i] + numbers[j];
            if(sum == target) break;
            if(sum < target) i++;
            else j--;
        }
        return {i+1, j+1};
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
        int n = prices.size();
        int ms = prices[0];
        for(int i=1;i<n;i++){
            ms = min(ms, prices[i-1]);
            profit = max(profit, prices[i] - ms);
        }
        return profit > 0 ? profit : 0;
    }
};


// https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1


bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
    sort(arr.begin(), arr.end());
    int n = arr.size();
    
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum > target){
                k--;
            } else if(sum < target){
                j++;
            } else {
                return true;
            }
        }
    }
    return false;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/2045350103/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        int j = 0;
        for(int i=0;i<n;i++){ 
            if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};



int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    
    return 0;
}
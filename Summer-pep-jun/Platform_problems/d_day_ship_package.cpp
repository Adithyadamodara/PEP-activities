// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int maxW){
        int d = 1;
        int w = 0;
        for(int i:weights){
            if(w + i > maxW){
                w = i;
                d++;
            } else {
                w += i;
            }
            if(d > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) /2;

            if(isPossible(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
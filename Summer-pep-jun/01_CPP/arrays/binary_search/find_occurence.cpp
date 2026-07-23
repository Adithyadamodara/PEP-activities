// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

class Solution {
  public:
    int bs(vector<int>& arr, int target, bool isFirst){
        int idx = -1;
        int low = 0;
        int high = arr.size() - 1; 
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] == target){
                idx = mid;
                if(isFirst){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                continue;
            }
            if(arr[mid]>target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return idx;
    }
    int countFreq(vector<int>& arr, int target) {
        const int n = arr.size();
        int low = 0;
        int high = n-1;
        int start = bs(arr, target, 1);
        int end = bs(arr, target, 0);
        
        return start == -1 ? 0 :end - start + 1;
    }
};

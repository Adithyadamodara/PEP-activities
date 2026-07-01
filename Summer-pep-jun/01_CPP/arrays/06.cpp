// https://www.geeksforgeeks.org/problems/pair-sum-in-a-sorted-and-rotated-array/1

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int pivot = 0;
        for(int i=1;i<n;i++){
            if(arr[i] < arr[i-1]) {
                pivot = i;
                break;
            }
        }
        
        int i = pivot;
        int j = (pivot - 1 + n) % n;
        while(i!=j){
            int sum = arr[i] + arr[j];
            if(sum == target) return true;
            else if(sum>target){
                j = (j - 1 + n) % n;
            }
            else {
                i = (i + 1) % n;
            }
        }
        return false;
    }
};



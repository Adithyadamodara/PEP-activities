// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = -1;
        int low = 0;
        int high = letters.size() - 1; 
        
        while(low <= high){
            int mid = low + (high - low)/2;

            if(letters[mid] > target){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high == letters.size()-1 ? letters[0]:letters[ans];
    }
};
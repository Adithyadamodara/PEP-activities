// https://leetcode.com/problems/magnetic-force-between-two-balls/


class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mx){
        int prev = position[0];
        int cnt = 1;
        for(int i=1;i<position.size();i++){
            if(position[i] - prev >= mx){
                cnt++;
                prev = position[i];
            }
            if(cnt == m) return true;
        }
        return cnt >= m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int high = position.back() - position.front();
        int low = 1;    
    
        while(low<high){
            int mid = low + (high - low + 1)/2;
            
            if(isPossible(position, m, mid)){
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
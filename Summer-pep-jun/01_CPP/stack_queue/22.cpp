// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

// https://www.geeksforgeeks.org/problems/previous-smaller-element/1


// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1


// https://leetcode.com/problems/next-greater-element-i/description/


// https://leetcode.com/problems/largest-rectangle-in-histogram/

// https://leetcode.com/problems/asteroid-collision/description/    

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        for(int i=0;i<n;i++){
            int ele = asteroids[i];
            bool destroyed = false;
            
            while(!stk.empty() && ele < 0 && stk.top() > 0){
                int t = stk.top();
                if(t < abs(ele)){
                    stk.pop();
                } else if( t > abs(ele)){
                    destroyed = true;
                    break;
                } else {
                    stk.pop();
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) stk.push(ele);
        }

        vector<int> res(stk.size());
        for(int i=stk.size()-1;i>=0;i--){
            res[i] = stk.top();
            stk.pop();
        }
        return res;
    }
};
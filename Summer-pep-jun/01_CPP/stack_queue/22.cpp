// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

// https://www.geeksforgeeks.org/problems/previous-smaller-element/1

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        const int n = arr.size();
        vector<int> res;
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && stk.top() >= arr[i]){
                stk.pop();
            }
            
            if(stk.empty()){
                res.push_back(-1);
                stk.push(arr[i]);
            } else if(stk.top() < arr[i]){
                res.push_back(stk.top());
                stk.push(arr[i]);
            }
        }
        return res;
    }
};

// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1


class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        const int n = arr.size();
        vector<int> res(n,-1); 
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && stk.top() <= arr[i]){
                stk.pop();
            }
            if(stk.empty()){
                stk.push(arr[i]);
                res[i] = -1;
            } else if(stk.top() > arr[i]){
                res[i] = stk.top();
                stk.push(arr[i]);
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/next-greater-element-i/description/


// https://leetcode.com/problems/largest-rectangle-in-histogram/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        int maxArea = 0;
        stack<int> stk;
        vector<int> left(n);
        vector<int> right(n);

        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            if(stk.empty()){
                left[i] = -1;
                stk.push(i);
            } else if(heights[stk.top()] < heights[i]){
                left[i] = stk.top();
                stk.push(i);
            }
        }
        while(!stk.empty()){
            stk.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            if(stk.empty()){
                right[i] = n;
                stk.push(i);
            } else if(heights[stk.top()] < heights[i]){
                right[i] = stk.top();
                stk.push(i);
            }
        }

        for(int i=0;i<n;i++){
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};


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
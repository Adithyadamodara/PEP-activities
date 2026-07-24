// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
public:
    bool dfs(int v, vector<bool>& visited, vector<vector<int>>& adj, vector<bool>& recStack){
        visited[v] = true;
        recStack[v] = true;
        for(auto i:adj[v]){
            if(!visited[i]){
                if(dfs(i, visited, adj, recStack)){
                    return true;
                } 
            } else if(recStack[i]) return true;
        }
        recStack[v] = false;
        return false;
    } 
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
    
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i, visited, adj, recStack)){
                return true;
            }
        }
        
        return false;
    }
};


// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// DFS

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int r, int c, int oc, int nc){
        int m = image.size();
        int n = image[0].size();
        image[r][c] = nc;
        if(r-1 >= 0 && image[r-1][c] == oc){
            dfs(image, r-1, c, oc, nc);
        }
        if(c-1 >=0 && image[r][c-1] == oc){
            dfs(image, r, c-1, oc, nc);
        }
        if(r+1 < m && image[r+1][c] == oc){
            dfs(image, r+1, c, oc, nc);
        }
        if(c+1 < n && image[r][c+1] == oc){
            dfs(image, r, c+1, oc, nc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int m = image.size();
        int n = image[0].size();
        if(image[sr][sc] == newColor) return image;
        
        int oc = image[sr][sc];
        
        dfs(image, sr, sc, oc, newColor);
        return image;
    }
};


// BFs

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int m = image.size();
        int n = image[0].size();
        if(image[sr][sc] == newColor) return image;
        
        int oc = image[sr][sc];
        queue<pair<int,int>> bfs;
        bfs.push({sr,sc});
        image[sr][sc] = newColor;
        while(!bfs.empty()){
            auto [r,c] = bfs.front();
            bfs.pop();
            
            if(r-1 >= 0 && image[r-1][c] == oc){
                bfs.push({r-1, c});
                image[r-1][c] = newColor;
            }
            if(c-1 >=0 && image[r][c-1] == oc){
                bfs.push({r, c-1});
                image[r][c-1] = newColor;
            }
            if(r+1 < m && image[r+1][c] == oc){
                bfs.push({r+1, c});
                image[r+1][c] = newColor;
            }
            if(c+1 < n && image[r][c+1] == oc){
                bfs.push({r, c+1});
                image[r][c+1] = newColor;
            }
        }
        
        return image;
    }
};

// https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution {
  public:
  
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& stk){
        visited[v] = true;
        for(int e: adj[v]){
            if(!visited[e]){
                dfs(e, adj, visited, stk);
            }
        }
        stk.push(v);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        stack<int> stk;
        vector<int> res;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, adj, visited, stk);
            }
        }
        
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};


// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path){
        visited[v] = true;
        path[v] = true;
        for(auto i:adj[v]){
            if(!visited[i]){
                if(dfs(i, adj, visited, path)) return true;
            } else if(path[i]){
                return true;
            }
        }
        path[v] = false;  
        return false;  
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);    
        vector<vector<int>> adj(numCourses);

        for(auto e: prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(i, adj, visited, path)){
                return false;
            }
        }
        return true;
    }
};
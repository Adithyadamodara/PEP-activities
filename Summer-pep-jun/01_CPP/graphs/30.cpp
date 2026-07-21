// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> res;
        vector<bool> visited(adj.size(), false);
        
        stack<int> dfs;
        dfs.push(0);
        while(!dfs.empty()){
            int v = dfs.top();
            dfs.pop();
            
            if(visited[v]) continue;
            
            visited[v] = true;
            res.push_back(v);
            
            for(int i = adj[v].size()-1;i>=0;i--){
                int u = adj[v][i];
                if(!visited[u]){
                    dfs.push(u);
                }
            }
            
        }
        return res;
    }
};

// http://geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<bool> visited(adj.size(), false);
        vector<int> res;
        
        queue<int> bfs;
        bfs.push(0);
        
        while(!bfs.empty()){
            int v = bfs.front();
            bfs.pop();
                
            if(visited[v]) continue;
            
            visited[v] = true;
            res.push_back(v);
            
            for(int i:adj[v]){
                if(!visited[i]){
                    bfs.push(i);
                }
            }
        }
        
        return res;
    }
};


// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> res;
        vector<bool> visited(V, false);
        
        vector<vector<int>> adj(V);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]) {
                vector<int> sub;
                stack<int> stk;
                stk.push(i);
                sub.push_back(i);
                visited[i] = true;
                while(!stk.empty()){
                    int v = stk.top();
                    stk.pop();
                    for(int j: adj[v]){
                        if(!visited[j]){
                            stk.push(j);
                            sub.push_back(j);
                            visited[j] = true;
                        }
                    }
                }
                res.push_back(sub);
            }
        }
        
        return res;
    }
};


// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }    
        } 
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                stack<int> dfs;
                count++;
                dfs.push(i);

                while(!dfs.empty()){
                    int v = dfs.top();
                    dfs.pop();
                    if(visited[v]) continue;
                    visited[v] = true;
                    for(int j = adj[v].size()-1;j>=0;j--){
                        int u = adj[v][j];
                        if(!visited[u]){
                            dfs.push(u);
                        }
                    }
                }
            }
        }
        return count;
    }
};

//optimized,- without creating adj list and only using recursive dfs

class Solution {
public:
    void dfs(int v, vector<vector<int>>& isConnected, vector<bool>& visited){
        if(visited[v]) return;
        visited[v] = true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[v][i]){
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};


// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();    
        queue<pair<int, int>> bfs;

        int fresh = 0;
        int time = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) {
                    bfs.push({i,j});
                } else if(grid[i][j] == 1) fresh++;
            }
        }

        while(!bfs.empty() && fresh > 0){
            int s = bfs.size();
            for(int i=0;i<s;i++){
                auto [r,c] = bfs.front();
                bfs.pop();
                if(r-1>=0 && grid[r-1][c] == 1){
                    bfs.push({r-1, c});
                    grid[r-1][c] = 2;
                    fresh--;
                }
                if(c-1>=0 && grid[r][c-1] == 1){
                    bfs.push({r, c-1});
                    grid[r][c-1] = 2;
                    fresh--;
                }
                if(r+1<m && grid[r+1][c] == 1){
                    bfs.push({r+1, c});
                    grid[r+1][c] = 2;
                    fresh--;
                }
                if(c+1<n && grid[r][c+1] == 1){
                    bfs.push({r, c+1});
                    grid[r][c+1] = 2;
                    fresh--;
                }
            }
            time++;
        }        
        return fresh == 0 ? time: -1; 
    }
};  
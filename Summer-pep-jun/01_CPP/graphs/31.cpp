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
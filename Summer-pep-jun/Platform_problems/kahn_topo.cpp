// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        vector<int> res;
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> qu;  
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        
        while(!qu.empty()){
            int v = qu.front();
            qu.pop();
            res.push_back(v);
            for(int u:adj[v]){
                indegree[u]--;
                if(indegree[u] == 0){
                    qu.push(u);
                }
            }
        }
        return res;
    }
};
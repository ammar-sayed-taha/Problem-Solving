class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        int len = prerequisites.size();
        
        if(len == 0) return true;
        
        int v, u;
        for(int i=0; i<len; i++){ // fill directed graph
            v = prerequisites[i][0];
            u = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        vector<int> color(numCourses, 0);
        for(int i=0; i< numCourses; i++){
            if(color[i] == 0 && dfs(i, adj, color)) return false;
        }
        return true;
    }
    
    bool dfs(int src, vector<int> adj[], vector<int> &color){
        color[src] = 1;
        for(int v: adj[src]){
            if(color[v] == 1) return true;
            if(color[v] == 0 &&  dfs(v, adj, color)) return true;
        }
        color[src]=2;
        return false;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses], order;
        vector<int> color(numCourses, 0);
        int len = prerequisites.size();
        
        if(len == 0){
            for(int i=numCourses-1; i>=0; --i)
                order.push_back(i);
            return order;
        }
                   
        int v, u;
        for(int i=0; i<len; i++){ // fill directed graph
            v = prerequisites[i][0];
            u = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
       bool hasCycle = false;
        for(int i=0; i< numCourses; i++){
            if(color[i] == 0 && dfs(i, adj, color, order)) {
                hasCycle = true;
                break;
            }
        }
        if(hasCycle) order.clear();
        
        return order;
        
    }
    
    bool dfs(int src, vector<int> adj[], vector<int> &color, vector<int> &order){
        color[src] = 1;
        
        for(int v: adj[src]){
            if(color[v] == 1) return true;
            if(color[v] == 0 && dfs(v, adj, color, order)) return true; 
                
        }
        order.push_back(src);
        
        color[src]=2;
        return false;
    }
    
};

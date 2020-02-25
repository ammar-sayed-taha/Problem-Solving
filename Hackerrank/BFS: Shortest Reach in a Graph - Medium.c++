
class Graph {
    public:
        unordered_map<int, vector<int>> graph;
        int size;
        Graph(int n) {
            this->size = n;
        }
    
        void add_edge(int u, int v) {
            this->graph[u].push_back(v);
            this->graph[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            unordered_set<int> visited;
            vector<int> dist(this->size, -1);
            dist[start] = 0;
            queue<int> nextToVisite;
            nextToVisite.push(start);

            while(!nextToVisite.empty()){
                int node = nextToVisite.front();
                nextToVisite.pop();
                visited.insert(node);

                for(int child: this->graph[node]){
                    if(visited.find(child) == visited.end()){
                        if(dist[child] == -1)
                            dist[child] = dist[node] + 6;
                        else 
                            dist[child] = min(dist[node] + 6, dist[child]);

                        nextToVisite.push(child);
                    }
                }
            }

            return dist;

        }
    
};

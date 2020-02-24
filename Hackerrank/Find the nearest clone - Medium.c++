
#define vi vector<int>
#define vl vector<long>
#define umapivi unordered_map<int, vi>
#define umapii unordered_map<int, int>
#define useti unordered_set<int>

void bfs(int start, umapivi & graph, vl &ids, int &val, int &minLen, int &graph_nodes, useti & vis){
    umapii dist;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis.insert(node);

        // if the node with same color found and not the start one then return
        if(ids[node-1] == val && dist.find(node) != dist.end()){
            minLen = min(minLen, dist[node]);
            return;
        }
        for(int i:graph[node])
            if(vis.find(i) == vis.end()){
                q.push(i);
                if(dist.find(i) == dist.end()) dist[i] = 1 + dist[node];
                else dist[i]++;
            }
    }
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // create adjacency list for graph
    umapivi graph;
    for(int i=0; i<graph_from.size(); i++){
        graph[graph_from[i]].push_back(graph_to[i]);
        graph[graph_to[i]].push_back(graph_from[i]);
    }
    int minLen = INT_MAX;
    useti visited;
    for(int i=1; i<= graph_nodes; i++)
      if (visited.find(i) == visited.end() && ids[i - 1] == val &&
          graph.find(i) != graph.end())
        bfs(i, graph, ids, val, minLen, graph_nodes, visited);

    return( minLen == INT_MAX) ? -1 : minLen;
}


/*
 ** the problem solved using BFS
 ** but it could be solved using DFS also
 ** Time Complexity: O(n^2) => visit all 2D array items
 ** Space Complexity O(n^2) => of visited array
*/

// Complete the maxRegion function below.
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> pairii;
typedef vector<vector<int>> vvpairii;

int bfs(pairii node, vvb &visited, vvi &grid){
    vvi dist{{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    int len = grid.size();
    int newLen = grid[0].size();
    queue<pairii> q;
    int maxRegion = 0;

    q.push({node.first,node.second});

    pairii cell;
    while(!q.empty()){
        cell = q.front();
        q.pop();
        if(visited[cell.first][cell.second]) continue;

        visited[cell.first][cell.second] = true;

        maxRegion++;

        for(vi child: dist){
            int i = child[0] + cell.first;
            int j = child[1] + cell.second;

            if(i < 0 || i >= len || j < 0 || j >= newLen) continue;

            if(!visited[i][j] && grid[i][j] == 1)
                q.push({i,j});
        }
    }

    return maxRegion;
}

int maxRegion(vector<vector<int>>& grid) {
    int len = grid.size();
    int newLen = grid[0].size();
    int maxRegion = 0;
    vvb visited(len);
    for(int i=0; i<len; i++)
        visited[i].resize(newLen, false);

    for(int i=0; i<len; i++)
        for(int j=0; j<newLen; j++)
            if(!visited[i][j] && grid[i][j] == 1)
                maxRegion = max(maxRegion, bfs({i, j}, visited, grid));

    return maxRegion == INT_MIN ? -1 : maxRegion;
}

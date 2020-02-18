#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void addStep(vector<int> *moves, int x, int y, int newX, int newY){
//    cout<<moves[newX][newY]<<"\n";
    if(moves[newX][newY] == -2){
        moves[newX][newY] = moves[x][y]+1;
    }
}
// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    queue<pair<int, int>> q;
    int len = grid.size();
    vector<int> moves[len];

    for(int i=0; i<len; i++)
        for(int j=0; j<len; j++){
            if(grid[i][j] == 'x') moves[i].push_back(-1);
            else moves[i].push_back(-2);
        }
    moves[startX][startY] = 0;

    pair<int, int> node;
    q.push({startX, startY});
    int i, j;

    while(q.size()){
        node = q.front();
        q.pop();
        i = node.first;
        j = node.second;

        if(i == goalX && j==goalY) {
            return moves[i][j];
        }

        grid[i][j] = 'x';

        // top
        for(int m = i-1; m>=0 && grid[m][j] == '.'; m--){
            q.push({m, j});
            addStep(moves, i, j, m, j);
        }

        // right
        for(int m = j+1; m<len && grid[i][m] == '.'; m++){
            q.push({i, m});
            addStep(moves, i, j, i, m);
        }

        // bottom
        for(int m = i+1; m<len && grid[m][j] == '.'; m++){
            q.push({m, j});
            addStep(moves, i, j, m, j);
        }

        // left
        for(int m = j-1; m>=0 && grid[i][m] == '.'; m--){
            q.push({i, m});
            addStep(moves, i, j, i, m);
        }


    }
    return -1;

}

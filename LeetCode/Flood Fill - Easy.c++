/*
Time Complexity: O(n)
space Complexity: O(n)
solve problem using BFS
*/

typedef pair<int,int> pii;
typedef unordered_set<string> usets;
typedef queue<pii> qpii;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int len = image.size(); // length of row
        if(len == 0) return {};
        int len2 = image[0].size(); // length of col
        
        qpii q; // queue
        usets vis;
        string num;
        int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // left, top, right, down directions of current cell
        
        int currentColor = image[sr][sc]; // get current color to compare neighbors later
        
        q.push({sr,sc}); // push current cell
        
        // concate current cell "rc" and push it in visited cells
        num = sr+48;
        num += sc+48;
        vis.insert(num);
        
        pii node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            // if current cell == the source color, change it
            if(image[node.first][node.second] == currentColor){
                image[node.first][node.second] = newColor;
            }
            
            // visit all directions of current cell
            for(auto cell: dir){
                int r = cell[0] + node.first ;
                int c = cell[1] + node.second;
                if(r<0 || r>=len || c<0 || c>=len2) continue;
                
                num = r+48;
                num += c+48;
                if(vis.find(num) == vis.end() && image[r][c] == currentColor){
                    q.push({r,c});
                    vis.insert(num);
                }
            }
        }
        return image;
        
    }
};

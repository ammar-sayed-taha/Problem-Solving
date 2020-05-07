/**
 * TC: O(N)
 * SP: O(1)
 */
 
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int cousins[4][2]; // 
        cousins[0][0] = x; // hold x
        cousins[0][1] = y; // hold y
        findCousins(root, -1, 0, x, y, cousins);
        if(cousins[1][0] != cousins[1][1] and
           cousins[2][0] == cousins[2][1]) return true;
        return false;
    }
    
    void findCousins(TreeNode * node, int parent, int depth, int &x, int &y, int cousins[4][2]){
        if(node == nullptr or (cousins[3][0] == true && cousins[3][1] == true)) return;
        
        if(node->val == cousins[0][0]){ // value x
            cousins[1][0] = parent;
            cousins[2][0] = depth;
            cousins[3][0] = true;
        }else if(node->val == cousins[0][1]){ // value y
            cousins[1][1] = parent;
            cousins[2][1] = depth;
            cousins[3][1] = true;
        }
        findCousins(node->left, node->val, depth + 1, x, y, cousins); // left
        findCousins(node->right, node->val, depth + 1, x, y, cousins); // right
    }
    
    
    
};

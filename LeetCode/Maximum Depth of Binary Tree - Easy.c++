/**
 * Time Complexity: O(N)
 * Space Complexity: O(N) because of DFS, but it can be O(1) using BFS
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

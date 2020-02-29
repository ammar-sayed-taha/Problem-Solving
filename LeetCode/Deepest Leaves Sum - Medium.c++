/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int height = getTreeHeight(root); // get the height of the tree
        return getLeavesSum(root, 1, height);
    }
    // get the height of the tree
    int getTreeHeight(TreeNode * node){
        if(!node) return 0;
        return 1+  max(getTreeHeight(node->left), getTreeHeight(node->right));
    }
    // get sum of leaves
    int getLeavesSum(TreeNode * node, int level, int & height){
        if(!node) return 0;
        if(level == height) return node->val;
        return getLeavesSum(node->left, level+1, height) + getLeavesSum(node->right, level+1, height);
    }
};

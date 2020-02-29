/**
 * time complexity: O(N)
 * space complexity: O(lgN)
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> nextToVisit;
        int sum=0;
        nextToVisit.push(root);
        TreeNode * node;
        while(!nextToVisit.empty()){
            node = nextToVisit.front();
            nextToVisit.pop();
            
            if(node->left) nextToVisit.push(node->left);
            if(node->right) nextToVisit.push(node->right);
            
            if(node->val % 2 == 0) // even
                sum += getGrandChildsSum(node->left, node->right);
        }
        return sum;
    }
    // calculate the sum of grand childs
    int getGrandChildsSum(TreeNode * left, TreeNode * right){
        int sum =0;
        if(left){
            if(left->left) sugetm+=left->left->val;            
            if(left->right) sum+=left->right->val;
        }
        if(right){
            if(right->left) sum += right->left->val;            
            if(right->right) sum += right->right->val;
        }
        return sum;
    }
};

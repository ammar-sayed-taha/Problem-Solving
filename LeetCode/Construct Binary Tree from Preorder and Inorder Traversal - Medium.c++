// Time Compexity: O(n)
// Space Compexity: O(n)  => hash map

class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int len1 = pre.size(), len2 = in.size();
        if(len1 == 0 && len2 == 0) return nullptr;
        
        TreeNode * head = nullptr, *node;
        unordered_map<int, TreeNode*> vis; // visited nodes
        
        int i=0, j=0, dir=0;
        while(i<len1 && j<len2){
            if(i==0) // first time
                node = head =  new TreeNode(pre[0]); 
            
            if(0 == dir && i != 0){
                node->left = new TreeNode(pre[i]);
                node = node->left;
            }else if(1 == dir){
                node->right = new TreeNode(pre[i]);
                node = node->right;
            }
            vis[pre[i]] = node;
            
            if(pre[i] == in[j] && j<len2-1){
                j++;
                if(vis.find(in[j]) == vis.end()) dir=1;
                else{
                    while(j<len2 && (vis.find(in[j]) != vis.end())) j++;
                    node = vis[in[j-1]];
                    dir = node->left == nullptr ? 0 : 1;
                }
            }else dir = 0;
            i++;
        }
        return head;
    }
};

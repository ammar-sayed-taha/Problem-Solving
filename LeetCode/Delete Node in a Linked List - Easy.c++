/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        for(; node->next->next; node->val = node->next->val, node = node->next);
        node->val = node->next->val;
        node->next = NULL;
    }
};

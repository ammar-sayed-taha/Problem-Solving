/**
 * Time Complexity: O(N)
 * Space Complexity: O(N) => string variable
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string binary = "";
        for(ListNode *node = head; node != NULL; binary += to_string(node->val), node = node->next);
        return bitset<32>(binary).to_ulong();
    }
};


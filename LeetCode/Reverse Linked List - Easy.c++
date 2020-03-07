/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *node, *newHead = NULL;
        for(node = head; node; node = head){
            if(head) head = head->next;
            node->next = newHead;
            newHead = node;
        }
        return newHead;
    }
};

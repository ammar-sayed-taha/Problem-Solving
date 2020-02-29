/**
 * assume N: length of list1 and M: length of list 2
 * Time Complex :O(N) where N >= M
 * Space Complexity: O(N) where N >= M
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * zeroNode = new ListNode(0);
        string num1 = getNums(l1);
        string num2 = getNums(l2);
        string sum = sumLists(num1, num2); // create sumList to sum two numbers bacasue of overflow numbers
        
        if((sum.length() == 1 && sum[0] == '0' && num1.length() == 1) ||
            (sum.length() == 1 && sum[0] == '0' && num2.length() == 1)) return zeroNode; // if input is l1=[0] or l2=[0]
        
        return buildTree(sum, sum.length()-1);
    }
 
    // get numbers from linked list into string
    string getNums(ListNode * node){
        if(!node) return "";
        return getNums(node->next) + to_string(node->val);
    }
    
    // build tree of string of numbers
    ListNode * buildTree(string sum, int index){
        if(index < 0) return NULL;
        ListNode * node = new ListNode(int(sum[index] - 48));
        node->next = buildTree(sum, index-1);
        return node;
        
    }  
    
    // sum two string numbers 
    string sumLists(string num1, string num2){
        int len1 = num1.length();
        int len2 = num2.length();
        int index1 = len1-1, index2 = len2-1;
        string result = "";
        int ch1,ch2, carry=0;

        while(index1 > -1 || index2 > -1){
            if(index1 > -1) ch1 = num1[index1--] - 48;
            else ch1 = 0;

            if(index2 > -1) ch2 = num2[index2--] - 48;
            else ch2 = 0;

            int num = ch1+ch2+carry;
            if(num>9){
                carry=1;
                num-=10;
            }else carry = 0;

            result = to_string(num) + result;
        }

        if(carry) result = to_string(carry) + result;

        return result;
    }
    
};

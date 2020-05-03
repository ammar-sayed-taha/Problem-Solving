/*
* TC: O(N)
*SC: O(N)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char ch;
        for(char c: s){
            if(st.size() > 0){
                if(c == '}' && st.top() == '{') st.pop();
                else if(c == ']' && st.top() == '[') st.pop();
                else if(c == ')' && st.top() == '(') st.pop();
                else st.push(c);
            }
            else st.push(c);
        }
        
        return st.size() > 0 ? false: true;
    }
};

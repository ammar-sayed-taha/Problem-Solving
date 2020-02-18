#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char>st;
    int len = s.length();
    char ch;

    for(char i:s){
        if(i == ')'){
            if(st.empty()) return "NO";
            ch = st.top();
            st.pop();
            if(ch != '(') return "NO";
        }
        else if(i == '}'){
            if(st.empty()) return "NO";
            ch = st.top();
            st.pop();
            if(ch != '{') return "NO";
        }
        else if(i == ']'){
            if(st.empty()) return "NO";
            ch = st.top();
            st.pop();
            if(ch != '[') return "NO";
        }else st.push(i);
        
    }

    if(!st.empty()) return "NO";

    return "YES";
    


}

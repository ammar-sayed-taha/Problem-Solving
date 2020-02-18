#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> newStack, oldStack;   
        void push(int x) {
            newStack.push(x);
        }

        void pop() {
            if(oldStack.empty())
                while(newStack.size()){
                    oldStack.push(newStack.top());
                    newStack.pop();
                }
            oldStack.pop();
        }

        int front() {
            if(oldStack.empty())
                while(newStack.size()){
                    oldStack.push(newStack.top());
                    newStack.pop();
                }
            return oldStack.top();
        }
};

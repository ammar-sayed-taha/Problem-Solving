/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool dfs(Node *node, unordered_set<Node*> &visited){
    if(!node) return false;
    visited.insert(node);
    
    if(node->next){
        if(visited.find(node->next) == visited.end())
            return  dfs(node->next, visited);
        else
            return true;
    }
    return false;
    
}

bool has_cycle(Node* head) {
    unordered_set<Node*> visited;
    return dfs(head, visited);
}














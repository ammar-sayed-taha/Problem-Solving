#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int, vi> umapvi;
typedef unordered_set<int> useti;

class Graph{
    umapvi adj;
    public:
    void addEdge(int u, int v){
        this->adj[u].push_back(v);
    }
    // push graph nodes in stack 
    void fillOrder(int src, useti &visited, stack<int> & st){
        visited.insert(src);
        for(auto v: this->adj[src])
            if(visited.find(v) == visited.end())
                fillOrder(v, visited, st);
        st.push(src);
    }
    // reverse the graph
    umapvi reverseGraph(){
        umapvi tmp;
        for(auto v: this->adj)
            for(int i: v.second)
                tmp[i].push_back(v.first);
        return tmp;
    }
    // make DFS to push every SCC in one list
    void dfs(int src, useti &visited, vi &comp){
        visited.insert(src);
        comp.push_back(src); // push vertex of component in list
        for(auto v: this->adj[src])
            if(visited.find(v) == visited.end())
                dfs(v, visited, comp);
    }
    // main function that used to start finding SCCs
    vvi findComponents(int src){
        useti visited;
        stack<int> st;
        vvi result;
        
        // fill the stack
        fillOrder(src, visited, st);
        visited.clear(); // clear visited set
        
        // reverse the Graph
        this->adj = reverseGraph();
        
        // collect components
        int vertex;
        vi comp;
        while(!st.empty()){
            vertex = st.top();
            st.pop();
            
            if(visited.find(vertex) == visited.end())
                dfs(vertex, visited, comp);
            
            if(comp.size() > 0){ // insert only filled list
              result.push_back(comp);
                comp = {};  
            }
        }
        return result;
    }
};


int main()
{
    Graph *g = new Graph();

    g->addEdge(1, 0); 
    g->addEdge(0, 2); 
    g->addEdge(2, 1); 
    g->addEdge(0, 3); 
    g->addEdge(3, 4); 
    
    vvi rs = g->findComponents(0);
    
    for(auto i: rs){ // print SCCs
        cout<<"[";
        for(auto j: i) cout<<j<<", ";
        cout<<"]\n";
    }
    return 0;
}

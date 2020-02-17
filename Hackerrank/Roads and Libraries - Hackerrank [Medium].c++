#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.


#define umapiv unordered_map<int, vector<int>>
#define useti unordered_set<int>

void countCost(int src, umapiv &cities, useti &colors, long &cost, int &c_lib,
               int &c_road ){
    colors.insert(src);
    cost = min(cost+c_road, cost+c_lib);

    for(int v:cities[src]){
        if(colors.find(v) == colors.end())
            countCost(v, cities, colors, cost, c_lib, c_road);
    }
}
void addEdge(umapiv &newCities, int v, int u){
    newCities[v].push_back(u);
    newCities[u].push_back(v);
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    // int len=cities.size();
    useti colors;
    umapiv newCities;
    long cost=0;

    // for(int i=1; i<=n; i++) newCities[i].push_back(-1);

    int len = cities.size();
    for(int i=0; i<len; i++){
        addEdge(newCities, cities[i][0], cities[i][1]);
    }

    for(auto i: newCities){
        if(colors.find(i.first) == colors.end()){
            cost+=c_lib - min(c_lib, c_road);
            countCost(i.first, newCities, colors, cost, c_lib, c_road);
        }
    }

    for(int i=1; i<=n; i++) 
        if(newCities.find(i) == newCities.end()) cost+=c_lib;

    return cost;

}

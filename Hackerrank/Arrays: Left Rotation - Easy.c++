#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {

    while(d--){
        int num = a.front();
        a.erase(a.begin());
        a.push_back(num);
    }
    return a;
}

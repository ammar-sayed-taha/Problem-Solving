#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pairs function below.
int pairs(int k, vector<int> arr) {

    sort(arr.begin(), arr.end()); // O(nlgn)

    int counter=0;
    for(auto i = 0; i < arr.size(); i++){ // O(n)
        for(auto j=i+1; j<arr.size(); j++){ // O(n)
            if(abs(arr[i] - arr[j]) == k)
                counter++;
            if(abs(arr[i] - arr[j]) > k) break;
        }
    }

    return counter;

}

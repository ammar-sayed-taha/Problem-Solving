#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());

    int i=0, counter=0;
    while(k > 0){
        if(k >= prices[i]){
            counter++;
            k-=prices[i];
            i++;
        }else
            break;
    }
    return counter;

}

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    // complete this function
    vector<long> result;
    long temp[arr.size()];
    long minVal,maxVal, fixedMin = INFINITY;
    int n = arr.size(), tl, tr;
    int j;
    for(int i=0; i<n; i++){ // O(n)
        tl=0;
        tr=i;
        temp[tr++] = arr[i];
        fixedMin = min(fixedMin, arr[i]);
        maxVal = -INFINITY;
        minVal= fixedMin;
        j=i+1;
        while(j<=n){ //O(n)

            maxVal = max(maxVal, minVal);

            if(j<n)
                temp[tr++]=arr[j];

            if(minVal == temp[tl]){
                minVal= INFINITY;
                for(int k=tl+1; k<tr;k++) minVal = min(minVal, temp[k]);
            }
            else minVal = min(minVal, temp[tr-1]);
            tl++;
            j++;
        }
        result.push_back(maxVal);
    }
    return result;
}

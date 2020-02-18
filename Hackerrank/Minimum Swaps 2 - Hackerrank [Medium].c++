#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/* // Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int len = arr.size();
    int i, j, min;
    int swapCount =0;
    int numSorted;
    for(i=0; i<len-1; i++){
        numSorted = i+1;
        min = i;
        for(j=i+1; j<len; j++){
            numSorted += arr[j-1] <= arr[j];
            if(arr[min] > arr[j])
                min = j;
        }
        if(numSorted == len) break;

        if(i != min){
             swapCount++;
             swap(arr[min], arr[i]);
        }
    }
    return swapCount;
}
 */

 int minimumSwaps(vector<int> arr) {
     unordered_map<int, int> umap;
     int len = arr.size();

    for(int i=0; i<len; i++)
        umap[arr[i]] = i;

    int index, swapCount=0;
    for(int i=len-1; i >= 0; i--){
        if(arr[i] != i+1){
            index = umap[i+1];
            umap[arr[i]] = index;
            umap[i+1] = i;
            swap(arr[i], arr[index]);
            swapCount++;

        }
    }

    return swapCount;

 }

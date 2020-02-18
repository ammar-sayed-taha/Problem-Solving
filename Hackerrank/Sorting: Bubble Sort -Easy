#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {

    int swapNum=0;
    bool isSorted=false;
    
    for(int i= a.size()-1; i>=0; i--){
        isSorted = true;
        for(int j=0; j<i;j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swapNum++;
                isSorted=false;
            }
        }
        if(isSorted) break;
    }

    cout<<"Array is sorted in "<<swapNum<<" swaps.\n";
    cout<<"First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[a.size()-1]<<endl;

}

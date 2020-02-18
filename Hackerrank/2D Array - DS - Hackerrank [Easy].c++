#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int len = arr.size();
    int sum=-INFINITY, temp;

    for(int i=0; i<len-2; i++){
        for(int j=0; j<len-2; j++){
            temp = arr[i][j] + arr[i][j+1] + arr[i][j+2]
                    + arr[i+1][j+1]
                    + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            sum = max(sum, temp);
        }
    }

    // for(int i=2; i<len; i++){
    //     for(int j=2; j<len;j++){
    //         // temp=0;
    //         temp =  arr[i][j] + arr[i][j-1] + arr[i][j-2] +
    //                            arr[i-1][j-1] +
    //                 arr[i-2][j] + arr[i-2][j-1] + arr[j-2][j-2];
    //         sum = sum < temp ? temp : sum;
    //     }
    // }
    return sum;

}

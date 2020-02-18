#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {

    long area=0;
    int left, right;
    int len = h.size();

    for(int i=0; i<len; i++){
        for(left=i; left>=0; left--)
            if(h[left]<h[i]) {
                left++;
                break;
            }
        
        if(left<0) left=0;

        for(right=i; right<len; right++)
            if(h[right]<h[i]){
                right--;
                break;
            }
        
        if(right>=len) right=len-1;
        int k = right-left+1;
        area = max(area, (long)(k*h[i]));
    }
    return area;
    
}

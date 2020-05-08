//TC: O(n)
// SC: O(1)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        int len = co.size();
        if(len == 2) return true;
        if((co[1][0] - co[0][0]) == 0) return calcBase(co, len); // if base is zero then this special case
        
        double slope = abs((double)(co[1][1] - co[0][1])/(double)(co[1][0] - co[0][0]));
        double tmpSlope;
        for(int i = 1; i<len-1; i++){
            tmpSlope = abs((double)(co[i+1][1] - co[0][1])/(double)(co[i+1][0] - co[0][0]));
            if(tmpSlope != slope) return false;
        }
        return true;
    }
    
    bool calcBase(vector<vector<int>>& co, int len){
        for(int i = 0; i<len-1; i++)
            if(co[i+1][0] - co[0][0] != 0)return false;
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, int> judgeOrPerson;
        unordered_set<int> personSet;
        int len = trust.size();
        
        if(N == 1 && len==0) return 1;
        else if(N == 0) return -1;
        
        for(vector<int> p: trust){
            personSet.insert(p[0]);
            judgeOrPerson[p[1]]++;
        }
        
        int judge = -1, count=0;
        for(auto p: judgeOrPerson){
            if(personSet.find(p.first) == personSet.end()){
                if(count < p.second) {
                    judge = p.first;
                    count = p.second;
                }
            }
        }
        
        return count >= N-1 ? judge : -1;
        
    }
};

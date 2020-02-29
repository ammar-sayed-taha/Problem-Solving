
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int, vi> umapivi; 

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        umapivi store;
        
        vvi result;
        int len = groupSizes.size();
        
        for(int i=0; i<len; i++){
            int id = groupSizes[i];
            
            store[id].push_back(i);
                        
            if(store[id].size() == id) {
                result.push_back(store[id]);
                store[id] = {};
            }
        }
        
        return result;
        
    }
};

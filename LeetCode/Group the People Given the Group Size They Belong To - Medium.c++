
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int, vi> umapivi; 

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        umapivi store; // map => key: goup size, value: list of ids its length of the key
        vvi result;
        int len = groupSizes.size();
        for(int i=0; i<len; i++){
            int id = groupSizes[i];
            store[id].push_back(i);
            if(store[id].size() == id) {
                result.push_back(store[id]); // push the group in result list
                store[id] = {}; // empty the ids of this group
            }
        }
        return result;
    }
};

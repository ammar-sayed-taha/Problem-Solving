class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> umap;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(umap.find(s[i]) != umap.end()) umap[s[i]].first++;
            else umap[s[i]] = {1, i};
        }
        int unique = INT_MAX;
        pair<int, int> val;
        for(auto i: umap){
            val = i.second;
            if(val.first == 1 && unique > val.second) unique = val.second;
        }
        return unique == INT_MAX ? -1 : unique;
    }
};

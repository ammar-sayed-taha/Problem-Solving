/*
* TC: O(N)
* SC:O(N)
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> store;
        int charsCount = 0;
        
        for(auto c: J) store.insert(c);
        for(auto c: S)
            if(store.find(c) != store.end())
                charsCount++;
        return charsCount;
    }
};

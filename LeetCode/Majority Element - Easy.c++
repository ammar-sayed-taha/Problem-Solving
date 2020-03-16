/*
* time Compleicty: O(N)
* space Complexity: O(N)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> store;
        int len = nums.size(),
            repeats = len/2;
        for(int &num: nums) store[num]++;
        for(auto &i : store)
            if(i.second > repeats) return i.first;
        return 0;
    }
};

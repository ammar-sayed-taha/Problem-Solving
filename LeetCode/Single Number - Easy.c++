/*
* Time Complexity: O(n)
* Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single =0;
        for(int i: nums)
            single ^= i;
        return single;
    }
};

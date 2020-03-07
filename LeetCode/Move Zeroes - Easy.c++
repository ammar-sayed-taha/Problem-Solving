/*
* Time Complexity: O(N)
* Space Complexity: O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        for(int start=0, end=0; end<len; end++)
            if(nums[end] != 0)
                swap(nums[start++], nums[end]);
    }
};

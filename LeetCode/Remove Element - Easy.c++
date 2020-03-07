/*
* Time Complexity: O(N)
* Space Complexity: O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int start=0;
        bool changed = false;
        
        for(int end=0; end<len; end++)
            if(nums[end] != val){
                swap(nums[start++], nums[end]);
            }else changed = true;
        
        return !changed ? len : start;
    }
};

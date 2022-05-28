class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int counter = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int& num: nums)
            if(counter != num)
                return counter;
            else counter++;
        
        return counter;
    }
};
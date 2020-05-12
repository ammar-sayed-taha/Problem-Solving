time complexity: O(lgn)
space complexity: O(1)


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
       int len = nums.size(),
        l = 0,
        r = len-1,
        m;
        int lastIndex; // used to hold index of second repeated number
        
        if(len == 1) return nums[0]; //special case
        
        while(r>=l){
            m = (l+r)/2;
			// cases if m points to single number with special cases
            if(((m-1>=0 && m+1<len) && (nums[m] != nums[m-1] && 
                                        nums[m] != nums[m+1]))) return nums[m]; // if number in middle list
            else if(m == 0 && nums[m] != nums[m+1])return nums[m]; // if number if first index
            else if(m==len-1 && nums[m] != nums[m+1]) return nums[m]; // // if number in last index
            
			// get index of second repeated number
            if(nums[m] == nums[m+1]) lastIndex = m+1;
            else lastIndex = m;
            
			// if last number is in positive position then, move right, otherwise move left
            if((lastIndex+1)&1 == 0) l=m+1;
            else r=m-1;
        }
        return -1;
        
    }
};

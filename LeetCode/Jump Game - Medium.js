/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let len = nums.length
    
    if(len == 1 && nums[0] == 0) return true
    
    function canJumpHelper(index){
        if(index >= len -1) return true
        if(nums[index] == 0) return false
        
        for(let i=1; i<= nums[index]; i++)
            if(canJumpHelper(index + i)) return true
        
        return false
    }
    return canJumpHelper(0)
};

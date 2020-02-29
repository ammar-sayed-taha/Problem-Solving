
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> storePositive;
        int maxNum = -INFINITY;
        for(int num: nums){
            if(num >= 0)
                storePositive.insert(num);
            maxNum = max(maxNum, num);
        }
        
        int target = 1;
        while(target <= maxNum){
            if(storePositive.find(target) == storePositive.end())
                return target;
            else 
                target++;
        }
            
        return target;
        
        
    }
};

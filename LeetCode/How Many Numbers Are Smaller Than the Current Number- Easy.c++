class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        int counter;        
        
        for(int i=0; i<nums.size(); i++){
            counter=0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j]<nums[i] && i!=j)
                    counter++;
            }
            result.push_back(counter);
        }
        
        return result;
        
    }
};

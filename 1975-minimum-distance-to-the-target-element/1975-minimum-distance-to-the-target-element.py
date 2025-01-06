class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        # Build dictionary to get each num as key and index as value
        min_distance = pow(10, 5) # distance larger than max nums[i]
        nums_dict = dict()

        # Fill the dictionary TC: O(n)
        for i in range(0, len(nums)):
            if nums[i] in nums_dict.keys():
                nums_dict[nums[i]].append(i)
            else:
                nums_dict[nums[i]] = [i]


        # get the min distance 
        for i in nums_dict[target]:
            x = abs(start - i)
            min_distance = min(min_distance, x)
        
        return min_distance



    





class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pos = {}
        
        size = len(nums)
        for i in range(0,size):
            complement = target - nums[i]
            if complement in pos:
                return [i,pos[complement]]
            pos[nums[i]] = i
        
        
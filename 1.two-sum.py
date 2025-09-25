#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

from typing import *

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # target = x + y
        # x = target - y
        # y = target - x
        
        num_map = {}
        
        for i in range(len(nums)):
            if num_map.get(nums[i]) is not None:
                return [i, num_map.get(nums[i])]
            
            # y = target - nums[i] 
            num_map[target - nums[i]] = i
            
            
            
# @lc code=end


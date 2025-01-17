class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        curr = 0
        end = len(nums) - 1
        
        while curr <= end:
            if nums[curr] == val:
                nums[curr],nums[end] = nums[end], nums[curr]
                
                end -= 1
                
                if nums[curr] == val:
                    continue
           
            curr += 1
        return end + 1
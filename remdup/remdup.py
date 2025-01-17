class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """        
        unique_ind = 0
        unique_no = nums[0]
        
        for ind in range(1,len(nums)):
            if nums[ind] != unique_no:
                nums[unique_ind + 1], nums[ind] = nums[ind], nums[unique_ind + 1]
                
                unique_ind += 1
                unique_no = nums[unique_ind]

        return unique_ind + 1
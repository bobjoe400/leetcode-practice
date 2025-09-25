#
# @lc app=leetcode id=344 lang=python3
#
# [344] Reverse String
#

# @lc code=start
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        back = len(s) - 1
        front = 0
        
        while front < back:
            s[back], s[front] = s[front], s[back]
            
            front += 1
            back -= 1
            
# @lc code=end


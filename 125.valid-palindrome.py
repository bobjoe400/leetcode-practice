#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#

# @lc code=start

'''

race a car
0 9 r r
1 8 a a
2 7 c c
3 6 e ''
3 

'''
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        
        while(i < j):
            c1 = ''
            c2 = ''
            
            if s[i].lower().isalnum():
                c1 = s[i].lower()
            else:
                i += 1
                
            if s[j].lower().isalnum():
                c2 = s[j].lower()
            else:
                j -= 1
            
            if c1 == '' or c2 == '':
                continue
            else:
                i += 1
                j -= 1
            
            if c1 != c2:
                return False
            
        return True
# @lc code=end


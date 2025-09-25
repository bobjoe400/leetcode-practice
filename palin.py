def isPalindrome(s: str) -> bool:
    i = 0
    j = len(s) - 1
    
    while(i < j):
        c1 = ''
        c2 = ''
        
        if s[i].isalnum():
            c1 = s[i].lower()
        else:
            i += 1
            
        if s[j].isalnum():
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

isPalindrome("race a car")
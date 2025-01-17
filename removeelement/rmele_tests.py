from rmele import Solution

sol:Solution = Solution()


with open('test_cases.txt') as f:
    for test_no in range(int(f.readline())):
        s = f.readline().strip()
        if len(s) > 2:
            arr1 = list(map(int, s.strip('[]').split(',')))
        rem = int(f.readline())
        
        s = f.readline().strip()
        if len(s) > 2:
            exp = list(map(int, s.strip('[]').split(',')))
        exp_num = int(f.readline())
            
        act_num = sol.removeElement(arr1, rem)
        act = arr1[:act_num]
            
        success = False
        if sorted(exp)==sorted(act) and act_num == exp_num:
            success = True
        
        print(f"Test {test_no} {('fail', 'success')[success]}")
        
        if not success:
            print(f'expected: {exp_num}, {sorted(exp)}\nactual: {act_num}, {sorted(act)}')
        
        
        
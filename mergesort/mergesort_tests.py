from mergesort import Solution

sol:Solution = Solution()


with open('test_cases.txt') as f:
    for _ in range(int(f.readline())):
        s = f.readline().strip()
        if len(s) > 2:
            arr1 = list(map(int, s.strip('[]').split(',')))
        m = int(f.readline())
        
        s = f.readline().strip()
        if len(s) > 2:
            arr2 = list(map(int, s.strip('[]').split(',')))
        n = int(f.readline())
        
        s = f.readline().strip()
        if len(s) > 2:
            exp = list(map(int, s.strip('[]').split(',')))
            
        sol.merge(arr1, m, arr2, n)
        
        print(f'{exp} does{(' not ', ' ')[exp == arr1]}equal {arr1}')

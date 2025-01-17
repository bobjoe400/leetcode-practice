class Solution(object):


    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        
        def ip_merge_sort(arr, start = 0, end=None):
            if end is None:
                end = len(arr)
            
            if end - start <= 1:
                return
            
            mid = (start + end)//2
            
            ip_merge_sort(arr, start, mid)
            ip_merge_sort(arr, mid, end)
            
            ip_merge(arr, start, mid, end)
            
        def ip_merge(arr, start, mid, end):
            # Temporary copy of the segment to merge
            left = arr[start:mid]
            right = arr[mid:end]

            i = j = 0
            k = start

            # Merge back into the original array
            while i < len(left) and j < len(right):
                if left[i] <= right[j]:
                    arr[k] = left[i]
                    i += 1
                else:
                    arr[k] = right[j]
                    j += 1
                k += 1

            # Copy any remaining elements from left and right
            while i < len(left):
                arr[k] = left[i]
                i += 1
                k += 1

            while j < len(right):
                arr[k] = right[j]
                j += 1
                k += 1
        
        nums1[m:] = nums2[:n]
        
        ip_merge_sort(nums1)
        
        return 
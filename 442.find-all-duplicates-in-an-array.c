/*
 * @lc app=leetcode id=442 lang=c
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "stdlib.h"
#include "math.h"

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;

    int* result = calloc(numsSize, sizeof(int));
    
    if(!result){
        return NULL;
    }

    for(int i = 0; i < numsSize; i++){
        int curr_index = abs(nums[i]) - 1;

        if(nums[curr_index] > 0){
            nums[curr_index] *= -1;
        } else {
            result[(*returnSize)++] = abs(nums[i]);
        }
    }

    return result;
}
// @lc code=end


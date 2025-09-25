/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include "stdlib.h"

int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnColumnSizes = NULL;
    *returnSize = 0;

    int** returnValue = (int**) calloc(numsSize * numsSize / 6, sizeof(int*));

    if(!returnValue){
        return NULL;
    }

    int* columnSizes = (int*) calloc(numsSize * numsSize / 6, sizeof(int));

    if(!columnSizes){
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare_ints);

    int i = 0;
    
    while( i < numsSize - 2){
        int curr_target = 0 - nums[i];

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right){
            int curr_left = nums[left];
            int curr_right = nums[right];

            if(curr_left + curr_right < curr_target){
                left++;
            }else if (curr_left + curr_right > curr_target){
                right--;
            }else{ // found triplet
                int* triplet = calloc(3, sizeof(int));

                if(!triplet){
                    *(*returnColumnSizes) = 0;
                    *returnSize = 0;
                    
                    free(returnValue);
                    free(columnSizes);

                    return NULL;
                }
                
                triplet[0] = -curr_target;
                triplet[1] = curr_left;
                triplet[2] = curr_right;

                returnValue[(*returnSize)] = triplet;
                columnSizes[(*returnSize)] = 3;

                (*returnSize)++;

                left++;
                right--;

                while(left < right && nums[left] == curr_left){
                    left++;
                }

                while(right > left && nums[right] == curr_right){
                    right--;              
                }
            }
        }

        while(i < numsSize-2 && nums[i] == nums[i+1]){
            i++;
        }

        i++;
    }

    if(*returnSize != 0){
        *returnColumnSizes = columnSizes;
    }

    return returnValue;
}
// @lc code=end


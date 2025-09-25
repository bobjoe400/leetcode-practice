/*
 * @lc app=leetcode id=56 lang=c
 *
 * [56] Merge Intervals
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int compare_vals(const void* a, const void* b){
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    int** returnValue = (int**) calloc(intervalsSize, sizeof(int*));

    if(!returnValue){
        return NULL;
    }

    *returnColumnSizes = (int*) calloc(intervalsSize, sizeof(int));

    if(!returnColumnSizes){
        return NULL;
    }

    // sort the input array by the lower value of the intervals
    qsort(intervals, intervalsSize, sizeof(intervals[0]), compare_vals);

    returnValue[*(returnSize)] = (int*) calloc(2, sizeof(int));
    returnValue[*(returnSize)][0] = intervals[0][0];
    returnValue[*(returnSize)][1] = intervals[0][1];

    (*returnColumnSizes)[*(returnSize)] = 2;
    
    (*returnSize)++;

    for (int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] <= returnValue[*(returnSize) - 1][1]){// merge intervals
            if(intervals[i][1] > returnValue[*(returnSize) - 1][1]){
                returnValue[*(returnSize) - 1][1] = intervals[i][1];
            }
        } else { // start a new interval    

            returnValue[*(returnSize)] = calloc(2, sizeof(int));

            if(!returnValue[*(returnSize)]){
                *returnSize = 0;
                *(*returnColumnSizes) = 0;

                free(returnValue);

                return NULL;
            }

            returnValue[*(returnSize)][0] = intervals[i][0];
            returnValue[*(returnSize)][1] = intervals[i][1];

            (*returnColumnSizes)[*returnSize] = 2;

            (*returnSize)++;
        }
    }

    return returnValue;
}
// @lc code=end

int main(){
    int** intervals = (int**) calloc(2, sizeof(int*));
    int* interval1 = (int*) calloc(2, sizeof(int));
    int* interval2 = (int*) calloc(2, sizeof(int));

    interval1[0] = 4;
    interval1[1] = 7;
    interval2[0] = 1;
    interval2[1] = 4;

    intervals[0] = interval1;
    intervals[1] = interval2;

    int intervalsSize = 2;
    int returnSize = 0;
    
    int* returnColumnSizes = (int*) NULL;

    merge(intervals, 2, &intervalsSize, &returnSize, &returnColumnSizes);

    for(int i = 0; i < intervalsSize; i++){
        free(intervals[i]);
    }

    free(intervals);

    if(returnColumnSizes != NULL){
        free(returnColumnSizes);
    }

}

